#pragma once
#include "ComponentHeader.h"

class KeyboardController : public Component {
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	enum directions {
		up,
		down,
		left,
		right
	};

	//by default, face down
	int lastFacing = down;

	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	void Init() override {
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	}

	void Update() override {
		//reset velocity
		transform->velocity.Zero();

		//idle animations
		switch (lastFacing) {
		case up:
			sprite->Play("IdleU");
			break;
		case right:
			//sprite->Play("IdleR");
			break;
		case down:
			sprite->Play("IdleD");
			break;
		case left:
			//sprite->Play("IdleL");
			break;
		}

		//directional movement
		if (keystate[SDL_SCANCODE_W]) { 
			transform->velocity.y = -1; 
			sprite->Play("WalkU");
			lastFacing = up;
		}

		if (keystate[SDL_SCANCODE_A]) { 
			transform->velocity.x = -1; 
			sprite->Play("WalkL");
			lastFacing = left;
		}

		if (keystate[SDL_SCANCODE_S]) { 
			transform->velocity.y = 1; 
			sprite->Play("WalkD");
			lastFacing = down;
		}

		if (keystate[SDL_SCANCODE_D]) { 
			transform->velocity.x = 1; 
			sprite->Play("WalkR");
			lastFacing = right;
		}

		//other controls
		if (keystate[SDL_SCANCODE_E]) { /*interact*/ }
	}
};