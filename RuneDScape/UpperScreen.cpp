#include "UpperScreen.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

Map* map;

Manager manager;
auto& player(manager.addEntity());

UpperScreen::UpperScreen() {
	map = new Map();

	//ECS implementation
	player.addComponent<PositionComponent>();
	player.addComponent<SpriteComponent>("Assets/bot.png");

	//log initialisation
	printf("Upper Screen Initialised\n");
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
