#pragma once
#include "ComponentHeader.h"

class TileComponent : public Component {
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* filePath;

	TileComponent() = default;
	
	TileComponent(int x, int y, int w, int h, int id) {
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		//set up tile IDs
		switch (tileID) {
		case 0:
			filePath = "Assets/water.png";
			break;
		case 1:
			filePath = "Assets/dirt.png";
			break;
		case 2:
			filePath = "Assets/wall.png";
			break;
		default:
			break;
		}
	}

	void Init() override {
		entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 2);
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(filePath);
		sprite = &entity->getComponent<SpriteComponent>();
	}
};