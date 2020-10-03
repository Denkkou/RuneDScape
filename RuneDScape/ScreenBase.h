#ifndef aScreenBaseFile
#define aScreenBaseFile

/*A virtual base class for both screens*/
#include <SDL.h>

class ScreenBase {
public:
	ScreenBase() {  
		canvasRect.x = 0;
		canvasRect.y = 0;
		canvasRect.w = 256*2;
		canvasRect.h = 192*2;
	};

	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	SDL_Rect canvasRect;
};

#endif