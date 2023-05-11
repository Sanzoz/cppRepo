#pragma once
#include <raylib.h>

struct Player {
public:
	Vector2 position;
	Vector2 direction;
	float acceleration;
	float rotation;
	float speed;
	float shipSize;
	float collisionRad;
	Color color;
};