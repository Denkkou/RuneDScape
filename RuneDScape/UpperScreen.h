#ifndef anUpperScreenFile
#define anUpperScreenFile

/*The Upper Screen - Displays player and world*/
/*This screen will also hande movement and world interaction*/
#include "ScreenBase.h"
#include "GameManager.h"
#include <vector>

class ColliderComponent;

class UpperScreen : public ScreenBase {
public:
	UpperScreen();
	~UpperScreen();

	void Input();
	void Update();
	void Render();

	static void AddTile(int srcX, int srcY, int posX, int posY, const char* filePath, int group);

	static SDL_Rect camera;
	static SDL_Event _event;

	//list of colliders
	static std::vector<ColliderComponent*> colliders;
};

#endif 
