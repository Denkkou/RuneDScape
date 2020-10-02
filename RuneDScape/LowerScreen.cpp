#include "LowerScreen.h"

LowerScreen::LowerScreen() {
	//move canvasRect to lower half
	canvasRect.y = 193;

	//log initialisation
	printf("Lower Screen Initialised\n");
}

LowerScreen::~LowerScreen() {}

void LowerScreen::Input() {
}

void LowerScreen::Update() {
}

void LowerScreen::Render() {
	//draw canvas
	SDL_SetRenderDrawColor(GameManager::gameRenderer, 50, 0, 0, 255);
	SDL_RenderFillRect(GameManager::gameRenderer, &canvasRect);
}
