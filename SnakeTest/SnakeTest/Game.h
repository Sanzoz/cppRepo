#pragma once
#include <raylib.h>

const int screenW = 1280; //screen width
const int screenH = 800; //screen height

const int snakeLength = 256; //max length of the snake
const int tileSize = 54; //each individual tile's sizes

static int gameSpeed; //speed of the game updates

static bool gameOver; //game over
static int framesCounter; //counts the frames that have passed
static int score; //tracks the amount of food eaten

static int tailCounter; //counts the tails of the snake
static bool canMove; //prevents inputting multiple inputs in each update

static Vector2 offset; //offset, used for offsetting the grid, and keeping 
					   //everything placed on the grid in a civilised manor

void Initialize();
void Update();
void Draw();
void Deinitialize();