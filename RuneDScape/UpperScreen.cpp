#include "UpperScreen.h"
#include "Map.h"
#include "ECS.h"
#include "ComponentHeader.h"
#include "Vector2D.h"

//dynamic allocation
Map* map;

Manager manager;

auto& player(manager.addEntity());

UpperScreen::UpperScreen() {
	map = new Map();

	//ECS implementation
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("Assets/bot.png");
	player.addComponent<KeyboardController>();
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
}

void UpperScreen::Render() {
	map->DrawMap();

	manager.Draw();
}
