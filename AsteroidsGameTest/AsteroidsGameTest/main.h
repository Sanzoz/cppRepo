#pragma once
#include <raylib.h>

const int screenW = 1600;
const int screenH = 900;

const int smolAsteroidMax = 5;
const int asteroidMax = 5;
const int chonkAsteroidMax = 5;

const int maxShots = 200;

static bool gameOver;
static bool victory;

static int asteroidsDestroyed = 0;
static int asteroidsRequired = 15;

static int smolAsteroidsCount;
static int asteroidsCount;
static int chonkAsteroidsCount;

void Initialise();
void Update();
void Draw();
