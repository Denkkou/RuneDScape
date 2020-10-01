#ifndef aLowerScreenFile
#define aLowerScreenFile

/*The Lower Screen - Clickable menus and interfaces*/

class LowerScreen {
public:
	LowerScreen();
	~LowerScreen();

	void Input();
	void Update();
	void Render(SDL_Renderer* gameRenderer);
};

#endif 