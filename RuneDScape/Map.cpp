#include "Map.h"
#include "UpperScreen.h"
#include <fstream>

Map::Map() {
}

Map::~Map(){
}

void Map::LoadMap(std::string filePath, int sizeX, int sizeY){
	char tile;
	std::fstream mapFile;

	mapFile.open(filePath);

	//parse the file
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(tile);
			UpperScreen::AddTile(atoi(&tile), x * (16 * 2), y * (16 * 2));
			mapFile.ignore();
		}
	}

	mapFile.close();
}
