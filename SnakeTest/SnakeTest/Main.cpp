#include <iostream>
#include <raylib.h>
#include <string.h>
#include "Game.h"
using namespace std;

int main() {
	InitWindow(screenW, screenH, "SNAKE GAME TEST"); //initial window
	SetTargetFPS(60); //sets the target framerate

	Initialize(); //calls initialize, starts the game

	//while loop to make the game actually run
	while (!WindowShouldClose()) {
		Update();
		Draw();
	}
}