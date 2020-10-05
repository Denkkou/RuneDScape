#ifndef aMapFile
#define aMapFile

#include <string>

class Map {
public:
	Map(const char* mFilePath, int mScale, int tScale);
	~Map();

	void LoadMap(std::string filePath, int sizeX, int sizeY);
	void AddTile(int srcX, int srcY, int posX, int posY);

private:
	const char* mapFilePath;
	int mapScale;
	int tileSize;
	int scaledSize;
};

#endif