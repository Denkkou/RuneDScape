#pragma once

#include "UpperScreen.h"
#include "ECS.h"
#include "ComponentHeader.h"

class KeyboardController : public Component {
public:
	TransformComponent* transform;
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	void Init() override {
		transform = &entity->getComponent<TransformComponent>();
	}

	void Update() override {
		//reset velocity
		transform->velocity.x = 0;
		transform->velocity.y = 0;

		//directional movement
		if (keystate[SDL_SCANCODE_W]) { transform->velocity.y = -1; }
		if (keystate[SDL_SCANCODE_A]) { transform->velocity.x = -1; }
		if (keystate[SDL_SCANCODE_S]) { transform->velocity.y = 1; }
		if (keystate[SDL_SCANCODE_D]) { transform->velocity.x = 1; }

		//other controls
	}
};