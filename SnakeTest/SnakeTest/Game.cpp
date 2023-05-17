#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "SnakeClass.h"
#include "FoodClass.h"
#include "CustomColors.h"
using namespace std;

SnakeClass snake[snakeLength] = { 0 }; //used for snake
Vector2 snakePos[snakeLength] = { 0 }; //used for snake tail

FoodClass food;

void Initialize() {
	framesCounter = 0; //resets framecounter
	gameOver = false; //resets gameover
	tailCounter = 1; //resets snake size
	score = 0; //resets score
	gameSpeed = 10; //resets game update rate

	offset.x = screenW % tileSize; //creates an offset for making the grid and grid movement
	offset.y = screenH % tileSize;

	for (int i = 0; i < snakeLength; i++) {
		snake[i].position = Vector2{ offset.x / 2, offset.y / 2 }; //snake starting position == offset / 2
		snake[i].size = Vector2{ tileSize, tileSize }; //sets size to be the size of the grid
		snake[i].direction = Vector2{ tileSize, 0 }; //sets default speed

		if (i == 0) snake[i].color = MALACHITE; //sets snake color
		else if (i % 2 == 0) snake[i].color = DARKERMALACHITE; //sets tail color
		else snake[i].color = DARKMALACHITE; //sets a second tail color
	}
	for (int i = 0; i < snakeLength; i++) { //
		snakePos[i] = Vector2{ 0.0f, 0.0f };
	}

	food.size = Vector2{ tileSize, tileSize }; //sets size of food
	food.color = RED; //sets food color
	food.active = false; //makes inactive at first to generate
}

void Update() {
	if (!gameOver) {
		//INPUTS -- Gets the key pressed and checks that the movement can be done, ie hitting left while moving right
		if (IsKeyPressed(KEY_RIGHT) && (snake[0].direction.x == 0) && canMove) { //canMove prevents you from spamming inputs until an update has occured
			snake[0].direction = Vector2{ tileSize, 0 }; //sets speed to tileSize so we move within the grid
			canMove = false;
		}
		if (IsKeyPressed(KEY_LEFT) && (snake[0].direction.x == 0) && canMove) {
			snake[0].direction = Vector2{ -tileSize, 0 };
			canMove = false;
		}
		if (IsKeyPressed(KEY_UP) && (snake[0].direction.y == 0) && canMove) {
			snake[0].direction = Vector2{ 0, -tileSize };
			canMove = false;
		}
		if (IsKeyPressed(KEY_DOWN) && (snake[0].direction.y == 0) && canMove) {
			snake[0].direction = Vector2{ 0, tileSize };
			canMove = false;
		}
		
		//switch case: as the snake gets longer, you go faster by increasing how often the game updates
		switch (tailCounter) {
		case(11): if (tailCounter == 11 && gameSpeed == 10) gameSpeed = 9;
		case(21): if (tailCounter == 21 && gameSpeed == 9) gameSpeed  = 8;
		case(31): if (tailCounter == 31 && gameSpeed == 8) gameSpeed = 7;
		case(41): if (tailCounter == 41 && gameSpeed == 7) gameSpeed = 6;
		case(51): if (tailCounter == 51 && gameSpeed == 6) gameSpeed = 5;
		}		// ^^ if statement double checks the switch case, and makes sure the snake is the correct size

		//SNAKE MOVEMENT -- Uses speed from inputs and moves each index within the snake array in the correct direction
		for (int i = 0; i < tailCounter; i++) snakePos[i] = snake[i].position; //sets the tails to follow the snake and moves them

		if ((framesCounter % gameSpeed) == 0) { // "(framesCounter % 6) == 0" sets the speed of the games updates by waiting until 
			for (int i = 0; i < tailCounter; i++) { // the remainder of frames passed is 0. once it is 0, it updates the snake and checks for collision
				if (i == 0) {
					snake[0].position.x += snake[0].direction.x; //moves snake based on speed x
					snake[0].position.y += snake[0].direction.y; //moves snake based on speed y
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
			food.position = Vector2{ GetRandomValue(0, (screenW / tileSize) - 1) * tileSize + offset.x / 2, GetRandomValue(0, (screenH / tileSize) - 1) * tileSize + offset.y / 2 }; //spawns food randomly within the grid

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
			DrawLineV(Vector2{ tileSize * i + offset.x / 2, offset.y / 2 }, Vector2{ tileSize * i + offset.x / 2, screenH - offset.y / 2 }, LIGHTERGRAY);
		}
		for (int i = 0; i < screenW / tileSize + 2; i++) {
			DrawLineV(Vector2{ offset.x / 2, tileSize * i + offset.y / 2 }, Vector2{ screenW - offset.x / 2, tileSize * i + offset.y / 2 }, LIGHTERGRAY);
		}

		DrawText(TextFormat("Score: %05i", score), 20, 1, 26, WHITE); //draws the score
		DrawText(TextFormat("Update Rate: %02i", gameSpeed), 220, 1, 26, WHITE); //speed of the snake
	}
	else DrawText("         GAME OVER\nPRESS [ENTER] TO PLAY", GetScreenWidth() / 4, GetScreenHeight() / 2, 50, LIME); //gameover text

	EndDrawing();
}
