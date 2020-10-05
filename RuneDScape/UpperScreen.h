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

	static SDL_Rect camera;
	static SDL_Event _event;

	enum groupLabels : std::size_t {
		groupMap,
		groupWalls,
		groupPlayers,
		groupColliders
	};
};

#endif 
