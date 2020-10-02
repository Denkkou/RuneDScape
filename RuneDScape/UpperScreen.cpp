#include "UpperScreen.h"

UpperScreen::UpperScreen() {
	//log initialisation
	printf("Upper Screen Initialised\n");
}

UpperScreen::~UpperScreen(){}

void UpperScreen::Input() {
}

void UpperScreen::Update() {
}

void UpperScreen::Render() {
	//draw canvas
	SDL_SetRenderDrawColor(GameManager::gameRenderer, 0, 0, 0, 255);
	SDL_RenderFillRect(GameManager::gameRenderer, &canvasRect);

}
