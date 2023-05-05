#pragma once
#include <raylib.h>

class FoodClass
{
	public:
		Vector2 position; //keeps position of the food
		Vector2 size; //keeps size of the food

		bool active; //whether the food is spawned or not

		Color color; //color of food
};
