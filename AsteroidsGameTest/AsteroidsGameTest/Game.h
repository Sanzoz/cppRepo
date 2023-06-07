#pragma once
#include <raylib.h>
#include "Player.h"
#include "Shoot.h"
#include "Asteroids.h"

const int smolAsteroidMax = 2000;
static int smolAsteroidAmount = 0;

const int asteroidMax = 2000;
static int asteroidAmount = 0;

const int chonkAsteroidMax = 2000;
static int chonkAsteroidAmount = 5;

const int maxShots = 120;

static bool gameOver;
static bool victory;
static bool debugActive;

static int asteroidsDestroyed = 0;
static int asteroidSpawner = 0;
static int asteroidsRequired = 3000;
static int gainLifeScore = 10000;

static int smolAsteroidsCount = smolAsteroidAmount;
static int asteroidsCount = asteroidAmount;
static int chonkAsteroidsCount = chonkAsteroidAmount;

void Initialise();
void Update();
void Draw();