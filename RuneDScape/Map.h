#ifndef aMapFile
#define aMapFile

#include <string>

class Map {
public:
	Map();
	~Map();

	static void LoadMap(std::string filePath, int sizeX, int sizeY);

private:

};

#endif