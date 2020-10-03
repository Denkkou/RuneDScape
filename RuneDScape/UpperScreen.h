#ifndef anUpperScreenFile
#define anUpperScreenFile

/*The Upper Screen - Displays player and world*/
/*This screen will also hande movement and world interaction*/
#include "ScreenBase.h"
#include "GameManager.h"

class UpperScreen : public ScreenBase {
public:
	UpperScreen();
	~UpperScreen();

	void Input();
	void Update();
	void Render();

	static SDL_Event _event;
};

#endif 
