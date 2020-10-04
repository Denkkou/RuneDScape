#pragma once
#include "ComponentHeader.h"
#include "Vector2D.h"

class TransformComponent : public Component {
public:
	Vector2D position;
	Vector2D velocity;

	int height = 16;
	int width = 16;
	int scale = 2;

	int speed = 3;

	//constructors
	TransformComponent() {
		position.Zero();
	}

	TransformComponent(int s) {
		position.Zero();
		scale = s;
	}

	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int w, int h, int s) {
		position.x = x;
		position.y = y;
		width = w;
		height = h;
		scale = s;
	}

	void Init() override {
		velocity.Zero();
	}

	void Update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};