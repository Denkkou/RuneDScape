#ifndef aGameObjectFile
#define aGameObjectFile

/*A generic/tutorial Game Object class*/
#include "GameManager.h"

class GameObject {
public:
	GameObject(const char* textureSheet);
	~GameObject();

	void Update();
	void Render();

private:
	int posX;
	int posY;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, dstRect;
};

#endif