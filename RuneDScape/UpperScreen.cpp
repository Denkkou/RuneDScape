#include "UpperScreen.h"
#include "Map.h"
#include "ComponentHeader.h"
#include "Vector2D.h"
#include "Collision.h"

Manager manager;

std::vector<ColliderComponent*> UpperScreen::colliders;

auto& player(manager.addEntity());

const char* LumbridgeCastle_SS = "Assets/LumbridgeCastle_SS.png";

//+96 and +224 are the pixels that were cut off.... not sure why?
SDL_Rect UpperScreen::camera = { 0, 0, (38 * 16) + 96, (38 * 16) + 224 };

enum groupLabels : std::size_t {
	groupMap,
	groupPlayers,
	groupColliders
};

//group lists
auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));

UpperScreen::UpperScreen() {
	//ECS implementation
	Map::LoadMap("Assets/LumbridgeCastle_Map.map", 38, 38);

	//basic player
	player.addComponent<TransformComponent>(0, 0, 16, 20, 2);
	player.addComponent<SpriteComponent>("Assets/playerSpriteSheet.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);
}

UpperScreen::~UpperScreen(){
}

void UpperScreen::Input() {
}

void UpperScreen::Update() {
	manager.Refresh();
	manager.Update();

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

	for (auto& p : players) {
		p->Draw();
	}
}

void UpperScreen::AddTile(int srcX, int srcY, int posX, int posY) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, posX, posY, LumbridgeCastle_SS);
	tile.addGroup(groupMap);
}