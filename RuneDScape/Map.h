#ifndef aMapFile
#define aMapFile

#include "GameManager.h"

class Map {
public:
	Map();
	~Map();

	void LoadMap(int arr[16][16]);
	void DrawMap();

private:
	SDL_Rect src, dst;

	SDL_Texture* dirt;
	SDL_Texture* water;

	int map[16][16];
};

#endif