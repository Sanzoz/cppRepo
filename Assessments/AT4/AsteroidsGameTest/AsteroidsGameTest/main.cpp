#include <iostream>
#include <raylib.h>
#include "main.h"
#include "Game.h"
using namespace std;

int WinMain() {
	InitWindow(screenW, screenH, "ASTEROIDS TEST");
	SetTargetFPS(60);

	Initialise();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}
}