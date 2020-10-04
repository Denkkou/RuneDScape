#pragma once
#include "ComponentHeader.h"

class TileComponent : public Component {
public:
	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect;
	Vector2D position;

	TileComponent() = default;
	
	~TileComponent() {
		SDL_DestroyTexture(texture);
	}

	TileComponent(int srcX, int srcY, int posX, int posY, const char* filePath) {
		texture = TextureManager::LoadTexture(filePath);

		position.x = posX;
		position.y = posY;

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = 16;

		//destination
		dstRect.x = posX;
		dstRect.y = posY;
		dstRect.w = dstRect.h = (16 * 2);
	}

	void Update() override {
		dstRect.x = position.x - UpperScreen::camera.x;
		dstRect.y = position.y - UpperScreen::camera.y;
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, dstRect, SDL_FLIP_NONE);
	}
};