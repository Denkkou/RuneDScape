#ifndef anEntityComponentSystemFile
#define anEntityComponentSystemFile

/*Entity Component System*/
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

//forward declarations
class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID getNewComponentTypeID() {
	//remember last stored ID
	static ComponentID lastID = 0u;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {
	static_assert (std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = getNewComponentTypeID();
	return typeID;
}

//set amount of components an entity can have
constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;
using ComponentArray = std::array<Component*, maxComponents>;

//base component class
class Component {
public:
	//reference to owner
	Entity* entity;

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() {};

	virtual ~Component() {};
};

//base entity class
class Entity {
public:
	Entity(Manager& mManager) : manager(mManager){
	}

	void Update() {
		for (auto& c : components) c->Update();
	}

	void Draw() {
		for (auto& c : components) c->Draw();
	}

	bool isActive() const { return active; }
	void Destroy() { active = false; }

	bool HasGroup(Group mGroup) {
		return groupBitSet[mGroup];
	}

	void addGroup(Group mGroup);
	void DelGroup(Group mGroup) {
		groupBitSet[mGroup] = false;
	}

	//check if component is attached
	template<typename T> bool hasComponent() const {
		return componentBitSet[getComponentTypeID<T>];
	}

	//add component to entity
	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->Init();
		return *c;
	}

	//get component
	template<typename T> T& getComponent() const {
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	Manager& manager;
	bool active = true;

	//vector of components
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
	GroupBitSet groupBitSet;
};

//manager class to contain entities
class Manager {
public:
	//update all entities
	void Update() {
		for (auto& e : entities) e->Update();
	}

	//call all entities' draw function
	void Draw() {
		for (auto& e : entities) e->Draw();
	}

	//remove all inactive entities
	void Refresh() {
		for (auto i(0u); i < maxGroups; i++) {
			auto& v(groupedEntities[i]);
			v.erase(std::remove_if(std::begin(v), std::end(v),
				[i](Entity* mEntity) {
					return !mEntity->isActive() || !mEntity->HasGroup(i);
				}), std::end(v));
		}

		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity) {
				return !mEntity->isActive();
			}),
			std::end(entities));
	}

	void AddToGroup(Entity* mEntity, Group mGroup) {
		groupedEntities[mGroup].emplace_back(mEntity);
	}

	std::vector<Entity*>& getGroup(Group mGroup) {
		return groupedEntities[mGroup];
	}

	//add entity
	Entity& addEntity() {
		Entity* e = new Entity(*this);
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}

private:
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, maxGroups> groupedEntities;
};

#endif