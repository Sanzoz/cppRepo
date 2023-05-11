#pragma once
#include <raylib.h>

struct Asteroids {
public:
	Vector2 position;
	Vector2 direction;
	float radius;
	bool active;
	Color color;
};
