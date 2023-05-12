#pragma once
#include <raylib.h>
#include "Player.h"
#include "Shoot.h"
#include "Asteroids.h"

const int smolAsteroidMax = 200;
static int smolAsteroidAmount = 0;

const int asteroidMax = 200;
static int asteroidAmount = 0;

const int chonkAsteroidMax = 200;
static int chonkAsteroidAmount = 5;

const int maxShots = 200;

static bool gameOver;
static bool victory;
static bool debugActive;

static int asteroidsDestroyed = 0;
static int asteroidsRequired = 63;

static int smolAsteroidsCount = smolAsteroidAmount;
static int asteroidsCount = asteroidAmount;
static int chonkAsteroidsCount = chonkAsteroidAmount;



void Initialise();
void Update();
void Draw();