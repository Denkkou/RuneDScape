#pragma once

#include "Components.h"

class PositionComponent : public Component {
public:
	//constructors
	PositionComponent() {
		posX = 0;
		posY = 0;
	}

	PositionComponent(int x, int y) {
		posX = x;
		posY = y;
	}

	//expose x and y
	int x() { return posX; }
	int y() { return posY; }

	//set x and y
	void x(int x) { posX = x; }
	void y(int y) { posY = y; }
	void setPos(int x, int y) { posX = x; posY = y; }

	//override update for testing purposes
	void Update() override {
		posX++;
		posY++;
	}

private:
	int posX;
	int posY;
};