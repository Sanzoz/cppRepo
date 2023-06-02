#pragma once
#include <raylib.h>

struct Shoot {
public:
	Vector2 position;
	Vector2 direction;
	float radius;
	float rotation;
	float shotSpeed;
	int bulletLife;
	int lifeSpanMax;
	bool active;
	Color color;
};
