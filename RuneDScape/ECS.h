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

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() {
	//remember last stored ID
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

//set amount of components an entity can have
constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
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
	void Update() {
		for (auto& c : components) c->Update();
	}

	void Draw() {
		for (auto& c : components) c->Draw();
	}

	bool isActive() const { return active; }
	void Destroy() { active = false; }

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
	bool active = true;

	//vector of components
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
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
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity) {
				return !mEntity->isActive();
			}),
			std::end(entities));
	}

	//add entity
	Entity& addEntity() {
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}

private:
	std::vector<std::unique_ptr<Entity>>  entities;
};

#endif