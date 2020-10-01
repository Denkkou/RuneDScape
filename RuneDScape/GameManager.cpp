#include "GameManager.h"

GameManager::GameManager(){}
GameManager::~GameManager(){}

void GameManager::Run(SDL_Renderer* gameRenderer) {
	//FPS control
	FPSDelayTimer timer;
	const int DELTA_TIME = 16;

	//core loop
	while (gameRunning) {
		timer.resetTicks();

		Input();
		Update();
		Render(gameRenderer);

		//delay for rest of frame
		if (timer.getTicks() < DELTA_TIME)
			SDL_Delay(DELTA_TIME - timer.getTicks());
	}
}

void GameManager::Input() {
	upperScreen.Input();
	lowerScreen.Input();
}

void GameManager::Update() {
	upperScreen.Update();
	lowerScreen.Update();
}

void GameManager::Render(SDL_Renderer* gameRenderer) {
	upperScreen.Render(gameRenderer);
	lowerScreen.Render(gameRenderer);
}