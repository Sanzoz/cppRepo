#pragma once
#include <raylib.h>

struct Asteroids {
public:
	Vector2 position;
	Vector2 direction;
	float radius;
	float rotateDirection;
	bool active;
	Color color;
};
