#ifndef anUpperScreenFile
#define anUpperScreenFile

/*The Upper Screen - Displays player and world*/
#include "ScreenBase.h"
#include "GameManager.h"

class UpperScreen : public ScreenBase {
public:
	UpperScreen();
	~UpperScreen();

	void Input();
	void Update();
	void Render();
};

#endif 
