#pragma once
#include "ComponentHeader.h"
#include "Vector2D.h"

class TransformComponent : public Component {
public:
	Vector2D position;

	//constructors
	TransformComponent() {
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	void Update() override {
		
	}
};