#include "Map.h"
#include "TextureManager.h"

//test map
int testMap[16][16] = { 
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 ,0 ,1 ,0 ,1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 ,1 ,0 ,1 ,0}
};

Map::Map() {
	dirt = TextureManager::LoadTexture("Assets/dirt.png");
	water = TextureManager::LoadTexture("Assets/water.png");

	LoadMap(testMap);

	//size of each tile
	src.x = 0;
	src.y = 0;
	src.h = dst.w = 16;
	src.w = dst.h = 16;

	dst.x = dst.y = 0;
}

Map::~Map(){}

void Map::LoadMap(int arr[16][16]){
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			map[i][j] = arr[i][j];
		}
	}
}

void Map::DrawMap() {
	int type = 0;

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			type = map[i][j];

			dst.x = j * 16;
			dst.y = i * 16;

			switch (type) {
			case 0:
				TextureManager::Draw(dirt, src, dst);
				break;
			case 1:
				TextureManager::Draw(water, src, dst);
				break;
			}
		}
	}
}
