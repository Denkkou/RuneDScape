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
		srcRect.w = srcRect.h = 16;
		dstRect.w = dstRect.h = 16 * 2;
	}

	void Update() override {
		dstRect.x = (int)transform->position.x;
		dstRect.y = (int)transform->position.y;
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, dstRect);
	}

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect;
};