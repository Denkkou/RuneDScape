#pragma once
#include <string>
#include <SDL.h>
#include "ComponentHeader.h"

class ColliderComponent : public Component {
public:
	SDL_Rect collider;
	std::string tag;

	SDL_Texture* tex;
	SDL_Rect srcRect, dstRect;

	TransformComponent* transform;

	ColliderComponent(std::string t) {
		tag = t;
	}

	ColliderComponent(std::string t, int posX, int posY, int size) {
		tag = t;
		collider.x = posX;
		collider.y = posY;
		collider.h = collider.w = size;
	}

	void Init() override {
		transform = &entity->getComponent<TransformComponent>();

		tex = TextureManager::LoadTexture("Assets/ColTex.png");
		srcRect = { 0, 0, 16, 16 };

		dstRect = { collider.x, collider.y, collider.w, collider.h };
	}

	void Update() override {
		if (tag != "terrain") {

			//set dimensions
			collider.x = static_cast<int> (transform->position.x);
			collider.y = static_cast<int> (transform->position.y);
			collider.w = transform->width * transform->scale;
			collider.h = transform->height * transform->scale;
		}

		//override player hitbox
		if (tag == "player") {
			collider.x = static_cast<int> (transform->position.x) + 6;
			collider.y = static_cast<int> (transform->position.y) + 36;
			collider.w = 20;
			collider.h = 4;
		}

		dstRect.x = collider.x - UpperScreen::camera.x;
		dstRect.y = collider.y - UpperScreen::camera.y;
	}

	void Draw() override {
		//TextureManager::Draw(tex, srcRect, dstRect, SDL_FLIP_NONE);
	}
};
