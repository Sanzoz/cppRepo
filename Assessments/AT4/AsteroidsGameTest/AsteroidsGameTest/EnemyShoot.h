#pragma once
#include <raylib.h>

struct EnemyShoot{
public: 
	Vector2 position;
	Vector2 direction;
	float shotSpeed;
	float radius;
	int shotTimer;
	bool shotActive;
	Color color;
};