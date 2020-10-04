#pragma once
#include "Animation.h"
#include "ComponentHeader.h"
#include <map>

class SpriteComponent : public Component {
public:
	int animIndex = 0;
	std::map<const char*, Animation> animations;

	//flip flag
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteComponent() = default;

	SpriteComponent(const char* filePath) {
		SetTexture(filePath);
	}

	//animated overload currently only for player
	SpriteComponent(const char* filePath, bool isAnimated) {
		animated = isAnimated;

		//player animations
		Animation idleD = Animation(0, 2, 600);
		animations.emplace("IdleD", idleD);

		Animation idleU = Animation(1, 2, 600);
		animations.emplace("IdleU", idleU);

		Animation walkR = Animation(2, 4, 200);
		animations.emplace("WalkR", walkR);

		Animation walkL = Animation(3, 4, 200);
		animations.emplace("WalkL", walkL);

		Animation walkD = Animation(4, 4, 200);
		animations.emplace("WalkD", walkD);

		Animation walkU = Animation(5, 4, 200);
		animations.emplace("WalkU", walkU);

		//default state
		Play("IdleD");

		SetTexture(filePath);
	}

	~SpriteComponent() {
		//deallocate memory
		SDL_DestroyTexture(texture);
	}

	void SetTexture(const char* filePath) {
		texture = TextureManager::LoadTexture(filePath);
	}

	void Init() override {
		//reference to position component
		transform = &entity->getComponent<TransformComponent>();

		//16x16 sprites
		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void Update() override {
		if (animated) {
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		//set index
		srcRect.y = animIndex * transform->height;

		dstRect.x = static_cast<int>(transform->position.x) - UpperScreen::camera.x;
		dstRect.y = static_cast<int>(transform->position.y) - UpperScreen::camera.y;
		dstRect.w = transform->width * transform->scale;
		dstRect.h = transform->height * transform->scale;
	}

	void Draw() override {
		TextureManager::Draw(texture, srcRect, dstRect, spriteFlip);
	}

	void Play(const char* animName) {
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}

private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect;

	bool animated = false;
	int frames = 0;
	int speed = 100; //delay in ms
};