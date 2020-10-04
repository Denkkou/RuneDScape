#pragma once
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
		transform->velocity.Zero();

		//directional movement
		if (keystate[SDL_SCANCODE_W]) { transform->velocity.y = -1; }
		if (keystate[SDL_SCANCODE_A]) { transform->velocity.x = -1; }
		if (keystate[SDL_SCANCODE_S]) { transform->velocity.y = 1; }
		if (keystate[SDL_SCANCODE_D]) { transform->velocity.x = 1; }

		//other controls
		if (keystate[SDL_SCANCODE_E]) { /*interact*/ }
	}
};