#include "UpperScreen.h"
#include "Map.h"
#include "ComponentHeader.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
Manager manager;

std::vector<ColliderComponent*> UpperScreen::colliders;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

enum groupLabels : std::size_t {
	groupMap,
	groupPlayers,
	groupColliders
};

UpperScreen::UpperScreen() {
	map = new Map();

	//ECS implementation
	Map::LoadMap("Assets/testMap16x16.map", 16, 16);

	//basic player
	player.addComponent<TransformComponent>(0, 4, 16, 20, 2);
	player.addComponent<SpriteComponent>("Assets/playerSpriteSheet.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);

	//create test wall
	wall.addComponent<TransformComponent>(160.0f, 32.0f, 16, 48, 2);
	wall.addComponent<SpriteComponent>("Assets/wall.png");
	wall.addComponent<ColliderComponent>("wall");
	wall.addGroup(groupMap);
}

UpperScreen::~UpperScreen(){
	//deallocate memory
	delete map;
}

void UpperScreen::Input() {

}

void UpperScreen::Update() {
	manager.Refresh();
	manager.Update();

	//detect player collision
	for (auto cc : colliders) {
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}
}

//group lists
auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));

void UpperScreen::Render() {
	//render layers
	for (auto& t : tiles) {
		t->Draw();
	}

	for (auto& p : players) {
		p->Draw();
	}
}

void UpperScreen::AddTile(int id, int x, int y) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 16, 16, id);
	tile.addGroup(groupMap);
}
