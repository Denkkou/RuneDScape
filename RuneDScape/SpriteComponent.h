#pragma once

#include "Components.h"
#include<SDL.h>

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
		position = &entity->getComponent<PositionComponent>();

		//16x16 sprites
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 16;
		dstRect.w = dstRect.h = 16 * 2;
	}

	void Update() override {
		dstRect.x = position->x();
		dstRect.y = position->y();
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, dstRect);
	}

private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect;
};