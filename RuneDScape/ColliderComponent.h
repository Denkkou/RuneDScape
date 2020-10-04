#pragma once
#include <string>
#include <SDL.h>
#include "ComponentHeader.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	std::string tag;

	TransformComponent* transform;

	ColliderComponent(std::string t) {
		tag = t;
	}

	void Init() override {
		transform = &entity->getComponent<TransformComponent>();

		//add to colliders list
		UpperScreen::colliders.push_back(this);
	}

	void Update() override {
		//set dimensions
		collider.x = static_cast<int> (transform->position.x);
		collider.y = static_cast<int> (transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};
