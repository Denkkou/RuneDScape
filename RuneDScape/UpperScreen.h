#ifndef anUpperScreenFile
#define anUpperScreenFile

/*The Upper Screen - Displays player and world*/

class UpperScreen {
public:
	UpperScreen();
	~UpperScreen();

	void Input();
	void Update();
	void Render(SDL_Renderer* gameRenderer);
};

#endif 
