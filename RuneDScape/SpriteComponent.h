#pragma once
#include "ComponentHeader.h"

class SpriteComponent : public Component {
public:
	SpriteComponent() = default;

	SpriteComponent(const char* filePath) {
		SetTexture(filePath);
	}

	~SpriteComponent() {
		//deallocate memory
		SDL_DestroyTexture(texture);
	}

	void SetTexture(const char* filePath) {
		texture = TextureManager::LoadTexture(filePath);
	}

	void Init() override {
		//reference to position component
		transform = &entity->getComponent<TransformComponent>();

		//16x16 sprites
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void Update() override {
		dstRect.x = static_cast<int>(transform->position.x);
		dstRect.y = static_cast<int>(transform->position.y);
		dstRect.w = transform->width * transform->scale;
		dstRect.h = transform->height * transform->scale;
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, dstRect);
	}

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect;
};