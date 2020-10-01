//include libraries
#include <SDL.h>
#include <SDL_image.h>

//include headers
#include "GameManager.h"

int main(int argc, char* argvp[]) {
	//initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { return 1; }
	else SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init failed!");

	if(IMG_Init(SDL_INIT_EVERYTHING) < 0) { return 1; }
	else SDL_LogError(SDL_LOG_CATEGORY_ERROR, "IMG_Init failed!");

	//create window space and renderer
	SDL_Window* gameWindow = SDL_CreateWindow("RuneDScape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 256, 384, 0);
	SDL_Renderer* gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//create and run the game manager
	GameManager gameManager;
	gameManager.Run(gameRenderer);

	//close application
	IMG_Quit();
	SDL_Quit();
	return 0;
}