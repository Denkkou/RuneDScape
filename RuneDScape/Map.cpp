#include "Map.h"
#include "UpperScreen.h"
#include <fstream>
#include "ComponentHeader.h"
#include "UpperScreen.h"

extern Manager manager;

Map::Map(const char* mfp, int ms, int ts) : mapFilePath(mfp), mapScale(ms), tileSize(ts) {
	scaledSize = ms * ts;
}

Map::~Map(){
}

void Map::LoadMap(std::string filePath, int sizeX, int sizeY){
	char c;
	std::fstream mapFile;

	mapFile.open(filePath);

	int srcX, srcY;

	//parse the file
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapFile.get(c);
			srcX = atoi(&c) * tileSize;

			AddTile(srcX, srcY, x * (tileSize * mapScale), y * (tileSize * mapScale));
			mapFile.ignore();
		}
	}

	mapFile.ignore();

	//load next part
	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			if (c == '1') {
				//create collider
				auto& tcol(manager.addEntity());
				tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
				tcol.addGroup(UpperScreen::groupColliders);
			}
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int posX, int posY) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, posX, posY, tileSize, mapScale, mapFilePath);
	tile.addGroup(UpperScreen::groupMap);
	
}
