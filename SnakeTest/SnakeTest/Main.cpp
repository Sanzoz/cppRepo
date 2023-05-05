#include <iostream>
#include <raylib.h>
#include <string.h>
#include "Game.h"
using namespace std;

int WinMain() {
	InitWindow(screenW, screenH, "SNAKE GAME TEST"); //initial window
	SetTargetFPS(60); //sets the target framerate

	Initialize(); //calls initialize, starts the game

	//while loop to make the game actually run until ESC is pressed
	while (!WindowShouldClose()) {
		Update();
		Draw();
	}
}