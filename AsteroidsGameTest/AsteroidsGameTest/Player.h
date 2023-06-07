#pragma once
#include <raylib.h>

struct Player {
public:
	Vector2 position;
	Vector2 direction;
	float acceleration;
	float speedMax;
	float rotation;
	float shipSize;
	float collisionRad;
	int lifeCount;
	int lifeMax;
	int immunityTimer;
	int score;
	int livesGained;
	bool hittable;
	bool canGainLife;
	Color color;
};