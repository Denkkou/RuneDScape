#ifndef aGameManagementFile
#define aGameManagementFile

/*The Game Manager - Contains both 'screens'*/
#include "FPSDelayTimer.h"
#include "UpperScreen.h"
#include "LowerScreen.h"

class GameManager {
public:
	GameManager();
	~GameManager();

	void Run(SDL_Renderer* gameRenderer);

	void Input();
	void Update();
	void Render(SDL_Renderer* gameRenderer);
private:
	bool gameRunning;

	UpperScreen upperScreen;
	LowerScreen lowerScreen;
};

#endif