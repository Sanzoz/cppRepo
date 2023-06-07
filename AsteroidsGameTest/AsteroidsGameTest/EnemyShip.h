#pragma once
#include "raylib.h"

struct EnemyShip {
public:	
	Vector2 position;
	Vector2 direction;
	float maxSpeed;
	float shipSize;
	int spawnTimer;
	int shotCooldown;
	int scoreValue;
	int hp;
	bool active;
	bool hasShot;
	Color color;
};
