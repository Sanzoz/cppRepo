#include <iostream>
#include <raylib.h>
#include <string.h>
#include "Main.h"
#include "SnakeClass.h"
#include "FoodClass.h"
using namespace std;

const int screenW = 1280;
const int screenH = 768;

const int snakeLength = 256;
const int tileSize = 55;

bool gameOver = false;
int framesCounter = 0; 
int score = 0;

Color MLCHT {100, 233, 134, 255};
Color DMLCHT {70, 203, 104, 255};

Color DARKERGRAY{34, 34, 34, 255};
Color GRID {74, 74, 74, 255};

SnakeClass snake[snakeLength] = { 0 }; //used for snake
Vector2 snakePos[snakeLength] = { 0 }; //used for snake tail
int tailCounter = 0; //counts the tail length
bool canMove;

FoodClass food;
Vector2 offset;

int main() {
	InitWindow(screenW, screenH, "SNAKE GAME TEST"); //initial window
	SetTargetFPS(60); //sets the target framerate

	Initialize(); //calls initialize, starts the game

	//while loop to make the game actually run
	while (!WindowShouldClose()) {
		Update();
		Draw();
	}
	return 0;
}

void Initialize() {
	framesCounter = 0; //resets framecounter
	gameOver = false; //resets gameover
	tailCounter = 1; //resets snake size
	score = 0;

	offset.x = screenW % tileSize; //creates an offset for making the grid and grid movement
	offset.y = screenH % tileSize;

	for (int i = 0; i < snakeLength; i++) {
		snake[i].position = Vector2{ offset.x / 2, offset.y / 2 }; //snake starting position == offset / 2
		snake[i].size = Vector2{ tileSize, tileSize }; //sets size to be the size of the grid
		snake[i].speed = Vector2{ tileSize, 0 }; //sets default speed

		if (i == 0) snake[i].color = MLCHT; //sets snake color
		else snake[i].color = DMLCHT; //sets tail color
	}
	for (int i = 0; i < snakeLength; i++) {
		snakePos[i] = Vector2{ 0.0f, 0.0f };
	}

	food.size = Vector2{ tileSize, tileSize }; //sets size of food
	food.color = RED; //sets food color
	food.active = false; //makes inactive at first to generate
}

void Update() {
	if (!gameOver) {
		//INPUTS -- Gets the key pressed and checks that the movement can be done, ie hitting left while moving right
		if (IsKeyPressed(KEY_RIGHT) && (snake[0].speed.x == 0) && canMove) { //canMove prevents you from spamming inputs until an update has occured
			snake[0].speed = Vector2{ tileSize, 0 }; //sets speed to tileSize so we move within the grid
			canMove = false;
		}
		if (IsKeyPressed(KEY_LEFT) && (snake[0].speed.x == 0) && canMove) {
			snake[0].speed = Vector2{ -tileSize, 0 };
			canMove = false;
		}
		if (IsKeyPressed(KEY_UP) && (snake[0].speed.y == 0) && canMove) {
			snake[0].speed = Vector2{ 0, -tileSize };	
			canMove = false;
		}
		if (IsKeyPressed(KEY_DOWN) && (snake[0].speed.y == 0) && canMove) {
			snake[0].speed = Vector2{ 0, tileSize };
			canMove = false;
		}
		//if (IsKeyPressed(KEY_G)) gameOver = true; //debug, used to test the game over screen and resetting
		//SNAKE MOVEMENT -- Uses speed from inputs and moves each index within the snake array in the correct direction
		for (int i = 0; i < tailCounter; i++) snakePos[i] = snake[i].position; //sets the tails to follow the snake and moves them

		if ((framesCounter % 7) == 0) { // "(framesCounter % 6) == 0" sets the speed of the games updates by waiting until 
			for (int i = 0; i < tailCounter; i++) { // the remainder of frames passed is 0. once it is 0, it updates the snake and checks for collision
				if (i == 0) {
					snake[0].position.x += snake[0].speed.x; //moves snake based on speed x
					snake[0].position.y += snake[0].speed.y; //moves snake based on speed y
					canMove = true; //resets canMove to allow turning
				}
				else snake[i].position = snakePos[i - 1]; //tail movement: if not the head, moves the snake by following the piece in front of them
			}
		}
		//WALL COLLISION -- if off the grid, game over
		if ((snake[0].position.x) > (screenW - offset.x) || (snake[0].position.y) > (screenH - offset.y) || (snake[0].position.x) < 0 || (snake[0].position.y) < 0) {
			gameOver = true;
		}
		//TAIL COLLISION -- if you nom yourself, game over
		for (int i = 1; i < tailCounter; i++) {
			if (snake[0].position.x == snake[i].position.x && snake[0].position.y == snake[i].position.y) gameOver = true;
		}
		//FOOD SPAWNING -- spawnin that food yo
		if (!food.active) {
			food.active = true;
			food.position = Vector2{ GetRandomValue(0, (screenW / tileSize) - 1) * tileSize + offset.x / 2, GetRandomValue(0, (screenH / tileSize) - 1) * tileSize + offset.y / 2 }; //spawns food randomly

			for (int i = 0; i < tailCounter; i++) { //for loop to check if the food spawned inside the snake, and if it does, respawn it before ressetting i to 0.
				while ((food.position.x == snake[i].position.x) && (food.position.y == snake[i].position.y)) {
					food.position = Vector2{ GetRandomValue(0, (screenW / tileSize) - 1) * tileSize + offset.x / 2, GetRandomValue(0, (screenH / tileSize) - 1) * tileSize + offset.y / 2 };
					i = 0;
				}
			}
		}
		//FOOD COLLISION -- if you eat food, increase length and add score
		if (snake[0].position.x == food.position.x && snake[0].position.y == food.position.y) {
			snake[tailCounter].position = snakePos[tailCounter - 1]; //spawns the tail inside the snakes butt 
			tailCounter += 1; //increase tail length
			score += 10; //add score
			food.active = false; //set inactive to get it to respawn
		}
		framesCounter++;
	}
	else {
		if (IsKeyPressed(KEY_ENTER)) {
			Initialize();
			gameOver = false;
		}
	}
}

void Draw() {
	BeginDrawing();

	ClearBackground(DARKERGRAY); //sets background color to a darker gray than raylibs default DARKGRAY color

	if (!gameOver) {
		DrawRectangleV(food.position, food.size, food.color); //draws the food

		for (int i = 0; i < tailCounter; i++) DrawRectangleV(snake[i].position, snake[i].size, snake[i].color); //draws the snake

		//draws the grid, starting from top to bottom, then left to right. draws it on top of everything else
		for (int i = 0; i < screenW / tileSize + 2; i++) {
			DrawLineV(Vector2{ tileSize * i + offset.x / 2, offset.y / 2 }, Vector2{ tileSize * i + offset.x / 2, screenH - offset.y / 2 }, GRID); 
		}
		for (int i = 0; i < screenW / tileSize + 2; i++) {
			DrawLineV(Vector2{ offset.x / 2, tileSize * i + offset.y / 2 }, Vector2{ screenW - offset.x / 2, tileSize * i + offset.y / 2 }, GRID);
		}

		DrawText(TextFormat("Score: %05i", score), 7, 3, 26, WHITE); //draws the score
	}
	else DrawText("         GAME OVER\nPRESS [ENTER] TO PLAY", GetScreenWidth() / 4, GetScreenHeight() / 2, 50, LIME); //gameover text

	EndDrawing();
}