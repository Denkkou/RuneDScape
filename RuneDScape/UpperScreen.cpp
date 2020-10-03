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

	player.getComponent<TransformComponent>().position.Add(Vector2D(1, 1));
}

void UpperScreen::Render() {
	map->DrawMap();

	manager.Draw();
}
