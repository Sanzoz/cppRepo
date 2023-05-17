#pragma once
#include <raylib.h>

struct SnakeClass
{
	public:
		Vector2 position; //keeps position of the snake
		Vector2 size; //keeps the size of each piece of the snake
		Vector2 direction; //this keeps the direction the snake should move

		Color color; //keeps the color of the snake
};
