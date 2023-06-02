#pragma once
#include <raylib.h>

struct Player {
public:
	Vector2 position;
	Vector2 direction;
	float acceleration;
	float speedMax;
	float rotation;
	float speed;
	float shipSize;
	float collisionRad;
	int lifeCount;
	int immunityTimer;
	int score;
	bool hittable;
	Color color;
};