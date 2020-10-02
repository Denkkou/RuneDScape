#include "UpperScreen.h"
#include "Map.h"

Map* map;

UpperScreen::UpperScreen() {
	map = new Map();

	//log initialisation
	printf("Upper Screen Initialised\n");
}

UpperScreen::~UpperScreen(){}

void UpperScreen::Input() {
}

void UpperScreen::Update() {
}

void UpperScreen::Render() {
	map->DrawMap();
}
