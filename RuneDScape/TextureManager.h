#ifndef aTextureManagerFile
#define aTextureManagerFile

/*A Texture Manager*/
#include "GameManager.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip);
};

#endif
