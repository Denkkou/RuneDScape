#include "GameManager.h"
#include "TextureManager.h"
#include "UpperScreen.h"
#include "LowerScreen.h"

//reference to the renderer
SDL_Renderer* GameManager::gameRenderer = nullptr;

UpperScreen* upperScreen;
LowerScreen* lowerScreen;

GameManager::GameManager(){
	//create window space and renderer
	SDL_Window* gameWindow = SDL_CreateWindow("RuneDScape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 256, 384, 0);
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	gameRunning = true;

	//create instances of screens
	upperScreen = new UpperScreen();
	lowerScreen = new LowerScreen();
}
GameManager::~GameManager(){}

void GameManager::Run() {
	//FPS control
	FPSDelayTimer timer;
	const int DELTA_TIME = 16;

	//core loop
	while (gameRunning) {
		timer.resetTicks();

		Input();
		Update();
		Render();

		//delay for rest of frame
		if (timer.getTicks() < DELTA_TIME)
			SDL_Delay(DELTA_TIME - timer.getTicks());
	}
}

void GameManager::Input() {
	//polling for quit
	while (SDL_PollEvent(&_event)) {
		if (_event.type == SDL_QUIT)
			gameRunning = false;
	}

	upperScreen->Input();
	lowerScreen->Input();
}

void GameManager::Update() {
	upperScreen->Update();
	lowerScreen->Update();
}

void GameManager::Render() {
	//clear for next frame
	SDL_RenderClear(gameRenderer);

	//render lower screen on top of upper
	upperScreen->Render();
	lowerScreen->Render();

	//push changes
	SDL_RenderPresent(gameRenderer);
}
