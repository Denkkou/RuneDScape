#include "UpperScreen.h"
#include "Map.h"
#include "ComponentHeader.h"
#include "Vector2D.h"
#include "Collision.h"

Manager manager;
Map* map;
Map* terrain;

auto& player(manager.addEntity());

//+96 and +224 are the pixels that were cut off.... not sure why?
SDL_Rect UpperScreen::camera = { 0, 0, (38 * 16) + 96, (38 * 16) + 224 };

UpperScreen::UpperScreen() {
	map = new Map("Assets/LumbridgeCastleWalls_SS.png", 2, 16);
	terrain = new Map("Assets/LumbridgeCastle_SS.png", 2, 16);

	//order in which loaded is also render order!
	terrain->LoadMap("Assets/LumbridgeCastle_Map.map", 38, 38);
	map->LoadMap("Assets/LumbridgeCastleWalls_Map.map", 38, 38);

	//basic player
	player.addComponent<TransformComponent>(224, 224, 16, 20, 2);
	player.addComponent<SpriteComponent>("Assets/playerSpriteSheet.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	player.addGroup(groupPlayers);
}

//group lists
auto& tiles(manager.getGroup(UpperScreen::groupMap));
auto& colliders(manager.getGroup(UpperScreen::groupColliders));
auto& players(manager.getGroup(UpperScreen::groupPlayers));

UpperScreen::~UpperScreen(){
}

void UpperScreen::Input() {
}

void UpperScreen::Update() {
	//player position before move
	SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
	Vector2D playerPos = player.getComponent<TransformComponent>().position;

	manager.Refresh();
	manager.Update();

	for (auto& c : colliders) {
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cCol, playerCol)) {
			player.getComponent<TransformComponent>().position = playerPos;
		}
	}

	//centre player
	camera.x = player.getComponent<TransformComponent>().position.x - (256);
	camera.y = player.getComponent<TransformComponent>().position.y - (192);

	//camera bounds
	if (camera.x < 0) 
		camera.x = 0;
	if (camera.y < 0)
		camera.y = 0;
	if (camera.x > camera.w)
		camera.x = camera.w;
	if (camera.y > camera.h)
		camera.y = camera.h;
}

void UpperScreen::Render() {
	//render layers
	for (auto& t : tiles) {
		t->Draw();
	}

	for (auto& c : colliders) {
		c->Draw();
	}

	for (auto& p : players) {
		p->Draw();
	}
}
