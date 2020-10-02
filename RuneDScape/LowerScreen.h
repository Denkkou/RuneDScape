#ifndef aLowerScreenFile
#define aLowerScreenFile

/*The Lower Screen - Clickable menus and interfaces*/
#include "ScreenBase.h"
#include "GameManager.h"

class LowerScreen : public ScreenBase {
public:
	LowerScreen();
	~LowerScreen();

	void Input();
	void Update();
	void Render();
};

#endif 