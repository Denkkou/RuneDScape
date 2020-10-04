#include "Map.h"
#include "UpperScreen.h"
#include <fstream>

Map::Map() {
}

Map::~Map(){
}

void Map::LoadMap(std::string filePath, int sizeX, int sizeY, const char* spritePath, int group){
	char c;
	std::fstream mapFile;

	mapFile.open(filePath);

	int srcX, srcY;

	//parse the file
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			srcY = atoi(&c) * 16;
			mapFile.get(c);
			srcX = atoi(&c) * 16;

			UpperScreen::AddTile(srcX, srcY, x * (16 * 2), y * (16 * 2), spritePath, group);
			mapFile.ignore();
		}
	}

	mapFile.close();
}
