#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int initX, int initY) {
	objTexture = TextureManager::LoadTexture(textureSheet);

	posX = initX;
	posY = initY;
}

GameObject::~GameObject() {}

void GameObject::Update() {
	posX++;
	posY++;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 20;
	srcRect.w = 16;

	dstRect.x = posX;
	dstRect.y = posY;
	dstRect.w = srcRect.w;
	dstRect.h = srcRect.h;
}

void GameObject::Render() {
	SDL_RenderCopy(GameManager::gameRenderer, objTexture, &srcRect, &dstRect);
}
