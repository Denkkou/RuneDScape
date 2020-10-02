#ifndef aGameManagementFile
#define aGameManagementFile

/*The Game Manager - Contains both 'screens'*/
#include <SDL.h>
#include <SDL_image.h>

#include "FPSDelayTimer.h"

class GameManager {
public:
	GameManager();
	~GameManager();

	void Run();

	void Input();
	void Update();
	void Render();

	static SDL_Renderer* gameRenderer;
private:
	bool gameRunning;
	SDL_Event _event;
};

#endif