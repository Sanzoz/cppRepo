#include <iostream>
#include <raylib.h>
#include "main.h"
#include "Game.h"
#include "Player.h"
#include "Shoot.h"
#include "Asteroids.h"
#include "CustomColours.h"
using namespace std;

Player player{ 0 };
Shoot shoot[maxShots]{ 0 };
Asteroids smolAsteroid[smolAsteroidMax]{ 0 };
Asteroids asteroid[asteroidMax]{ 0 };
Asteroids chonkAsteroid[chonkAsteroidMax]{ 0 };

void Initialise() {
	int randX = 0, randY = 0;
	int dirX = 0, dirY = 0;
	float rotX = 0;
	bool validDir = false;

	debugActive = false;
	gameOver = false;
	asteroidsDestroyed = 0;
	chonkAsteroidAmount = 5;
	asteroidAmount = 5;
	smolAsteroidAmount = 5;

	//PLAYER INITIALISATION
	player.shipSize = 20;
	player.position = Vector2{ screenW / 2, screenH / 2 - player.shipSize / 2 };
	player.direction = Vector2{ 0, 0 };
	player.collisionRad = 12;
	player.acceleration = 0;
	player.speedMax = 6.5f;
	player.rotation = 0;
	player.score = 0;
	player.livesGained = 1;
	player.lifeCount = 4;
	player.lifeMax = 6;
	player.immunityTimer = 120;
	player.hittable = false;
	player.canGainLife = false;
	player.color = MALACHITE;

	//SHOOTING INITIALISATION
	for (int i = 0; i < maxShots; i++) {
		shoot[i].position = Vector2{ 0, 0 };
		shoot[i].direction = Vector2{ 0, 0 };
		shoot[i].radius = 2.5f;
		shoot[i].shotSpeed = 7.5f;
		shoot[i].active = false;
		shoot[i].bulletLife = 0;
		shoot[i].lifeSpanMax = 120;
		shoot[i].color = LIGHTRED;
	}

	//ASTEROID INITIALISATION
	for (int i = 0; i < smolAsteroidMax; i++) {
		smolAsteroid[i].position = Vector2{ -100, -100 };
		smolAsteroid[i].direction = Vector2{ 0, 0 };
		smolAsteroid[i].radius = 16;
		smolAsteroid[i].scoreIncrease = 25;
		smolAsteroid[i].active = false;
		smolAsteroid[i].color = LIGHTRED;
		//smolAsteroid[i].image = LoadImage("smolAsteroid.png");
	}
	for (int i = 0; i < asteroidMax; i++) {
		asteroid[i].position = Vector2{ -100, -100 };
		asteroid[i].direction = Vector2{ 0, 0 };
		asteroid[i].radius = 38;
		asteroid[i].scoreIncrease = 100;
		asteroid[i].active = false;
		asteroid[i].color = LIGHTORANGE;
		//asteroid[i].image = LoadImage("medAsteroid.png");
	}
	for (int i = 0; i < chonkAsteroidAmount; i++) {
		randX = GetRandomValue(0, screenW); //gets 2 random values and sets them as the direction to travel
		while (!validDir) {
			if (randX > screenW / 2 + 500 && randX < screenW / 2 + 500) randX = GetRandomValue(0, screenW);
			else validDir = true;
		}
		validDir = false;

		randY = GetRandomValue(0, screenH);
		while (!validDir) {
			if (randY > screenH / 2 - 450 && randY < screenH / 2 + 450) randY = GetRandomValue(0, screenH);
			else validDir = true;
		}

		chonkAsteroid[i].position = Vector2{ (float)randX, (float)randY };

		validDir = false;

		dirX = GetRandomValue(-3, 3);
		dirY = GetRandomValue(-3, 3);

		while (!validDir) {
			if (dirX == 0 && dirY == 0) {
				dirX = GetRandomValue(-3, 3);
				dirY = GetRandomValue(-3, 3);
			}
			else validDir = true;
		}

		validDir = false;

		chonkAsteroid[i].direction = Vector2{ (float)dirX, (float)dirY };
		chonkAsteroid[i].radius = 68;
		chonkAsteroid[i].scoreIncrease = 250;
		chonkAsteroid[i].active = true;
		chonkAsteroid[i].color = LIGHTYELLOW;
		//chonkAsteroid[i].image = LoadImage("chonkAsteroid.png");
	}

}

void Update() {
	if (!victory) {
		if (!gameOver) {
			//DEBUG ACTIVATER
			if (IsKeyPressed(KEY_J)) {
				if (debugActive) debugActive = false;
				else debugActive = true;
			}
			//PLAYER ROTATION INPUTS -- gets left and right keys to rotate the ship
			if (IsKeyDown(KEY_LEFT)) player.rotation -= 4;
			if (IsKeyDown(KEY_RIGHT)) player.rotation += 4;

			//PLAYER MOVEMENT INPUTS -- gets up and down keys and increases ships acceleration
			//slows down the ship by default if no key is pressed by half the deceleration speed
			if (IsKeyDown(KEY_UP)) {
				if (player.acceleration < player.speedMax) player.acceleration += 0.20f;
				player.direction.x = sin(player.rotation * PI / 180.0f) * 1.2f;
				player.direction.y = cos(player.rotation * PI / 180.0f) * 1.2f;
			}
			else {
				if (player.acceleration > 0) player.acceleration -= 0.02f;
				else if (player.acceleration < 0) player.acceleration = 0; //if the acceleration is lower than 0, set to 0
			}															   //prevents ship from gliding backwards when you stop accelerating
			if (IsKeyDown(KEY_DOWN)) {
				//force slows the ship
				if (player.acceleration > 0) player.acceleration -= 0.08f;
				else if (player.acceleration < 0) player.acceleration = 0;
			}

			//SHOOTING INPUTS -- gets the space bar to when to shoot
			if (IsKeyPressed(KEY_SPACE)) {
				for (int i = 0; i < maxShots; i++) {
					if (!shoot[i].active) {
						shoot[i].position = Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * player.shipSize * 2, player.position.y - cosf(player.rotation * PI / 180.0f) * player.shipSize * 2};
						shoot[i].active = true;
						shoot[i].direction.x = 1.5f * sin(player.rotation * PI / 180.0f) * shoot[i].shotSpeed;
						shoot[i].direction.y = 1.5f * cos(player.rotation * PI / 180.0f) * shoot[i].shotSpeed;
						shoot[i].rotation = player.rotation;
						shoot[i].bulletLife = 0;
						break;
					}
				}
			}

			//PLAYER WALL COLLISION -- if you hit a wall, move to the opposite side
			if (player.position.x > screenW + 50 + player.shipSize) player.position.x = -(player.shipSize);
			else if (player.position.x < -50 + -player.shipSize) player.position.x = screenW + player.shipSize;
			if (player.position.y > screenH + 50 + player.shipSize) player.position.y = -(player.shipSize);
			else if (player.position.y < -50 + -player.shipSize) player.position.y = screenH + player.shipSize;

			////SHOT WALL COLLISION -- if your shot hits a wall, wrap it around -- mostly used for fun
			//for (int i = 0; i < maxShots; i++) {
			//	if (shoot[i].active) {
			//		if (shoot[i].position.x > screenW + shoot[i].radius) shoot[i].position.x = -shoot[i].radius;
			//		else if (shoot[i].position.x < 0 + shoot[i].radius) shoot[i].position.x = screenW + shoot[i].radius;
			//		if (shoot[i].position.y > screenH + shoot[i].radius) shoot[i].position.y = -shoot[i].radius;
			//		else if (shoot[i].position.y < 0 + shoot[i].radius) shoot[i].position.y = screenH + shoot[i].radius;
			//	}
			//}

			//SHOT WALL COLLISION 2 -- if your shot hits a wall, delete it
			for (int i = 0; i < maxShots; i++) {
				if (shoot[i].active) {
					if (shoot[i].position.x > screenW + shoot[i].radius) shoot[i].active = false;
					else if (shoot[i].position.x < 0 + shoot[i].radius) shoot[i].active = false;
					if (shoot[i].position.y > screenH + shoot[i].radius) shoot[i].active = false;
					else if (shoot[i].position.y < 0 + shoot[i].radius) shoot[i].active = false;
				}
			}

			//ASTEROID MOVEMENT AND WALL COLLISION -- Asteroids go weeeeeEEEEEEEEE and when the asteroid hits a wall, loop around like the player
			for (int i = 0; i < smolAsteroidMax; i++) {
				if (smolAsteroid[i].active) {
					//moves the asteroid in the chosen direction
					smolAsteroid[i].position.x += smolAsteroid[i].direction.x;
					smolAsteroid[i].position.y -= smolAsteroid[i].direction.y;
					
					//teleports the asteroid to the opposite side when hitting the sides of the screen
					if (smolAsteroid[i].position.x > screenW + smolAsteroid[i].radius)
						smolAsteroid[i].position.x = -(smolAsteroid[i].radius);
					else if (smolAsteroid[i].position.x < -smolAsteroid[i].radius)
						smolAsteroid[i].position.x = screenW + smolAsteroid[i].radius;
					if (smolAsteroid[i].position.y > screenH + smolAsteroid[i].radius)
						smolAsteroid[i].position.y = -(smolAsteroid[i].radius);
					else if (smolAsteroid[i].position.y < -smolAsteroid[i].radius)
						smolAsteroid[i].position.y = screenH + smolAsteroid[i].radius;
				}
			}
			for (int i = 0; i < asteroidMax; i++) {
				if (asteroid[i].active) {
					asteroid[i].position.x += asteroid[i].direction.x;
					asteroid[i].position.y -= asteroid[i].direction.y;

					if (asteroid[i].position.x > screenW + asteroid[i].radius)
						asteroid[i].position.x = -(asteroid[i].radius);
					else if (asteroid[i].position.x < -asteroid[i].radius)
						asteroid[i].position.x = screenW + asteroid[i].radius;
					if (asteroid[i].position.y > screenH + asteroid[i].radius)
						asteroid[i].position.y = -(asteroid[i].radius);
					else if (asteroid[i].position.y < -asteroid[i].radius)
						asteroid[i].position.y = screenH + asteroid[i].radius;
				}
			}
			for (int i = 0; i < chonkAsteroidMax; i++) {
				if (chonkAsteroid[i].active) {
					chonkAsteroid[i].position.x += chonkAsteroid[i].direction.x;
					chonkAsteroid[i].position.y -= chonkAsteroid[i].direction.y;

					if (chonkAsteroid[i].position.x > screenW + chonkAsteroid[i].radius)
						chonkAsteroid[i].position.x = -(chonkAsteroid[i].radius);
					else if (chonkAsteroid[i].position.x < -chonkAsteroid[i].radius)
						chonkAsteroid[i].position.x = screenW + chonkAsteroid[i].radius;
					if (chonkAsteroid[i].position.y > screenH + chonkAsteroid[i].radius)
						chonkAsteroid[i].position.y = -(chonkAsteroid[i].radius);
					else if (chonkAsteroid[i].position.y < -chonkAsteroid[i].radius)
						chonkAsteroid[i].position.y = screenH + chonkAsteroid[i].radius;
				}
			}

			//ASTEROID BULLET COLLISION -- when you shoot an asteroid, explode it and split it into 2 -- for and if loop spam time
			for (int i = 0; i < maxShots; i++) {
				if (shoot[i].active) {
					for (int m = 0; m < chonkAsteroidMax; m++) {
						if (chonkAsteroid[m].active && CheckCollisionCircles(shoot[i].position, shoot[i].radius, chonkAsteroid[m].position, chonkAsteroid[m].radius)) {
							shoot[i].bulletLife = 0;
							shoot[i].active = false;
							chonkAsteroid[m].active = false;
							asteroidsDestroyed++;
							player.score += chonkAsteroid[m].scoreIncrease;
							if (player.score >= (player.livesGained * gainLifeScore)) player.canGainLife = true;

							for (int a = 0; a < 2; a++) {
								if (asteroidsCount % 2 == 0) {
									asteroid[asteroidsCount].position = Vector2{ chonkAsteroid[m].position.x + chonkAsteroid[i].radius / 2, chonkAsteroid[m].position.y + chonkAsteroid[i].radius / 2 };
									asteroid[asteroidsCount].direction = Vector2{ cos(shoot[i].rotation * PI / 180) * 2, -sin(shoot[i].rotation * PI / 180) * 2};
								}
								else {
									asteroid[asteroidsCount].position = Vector2{ chonkAsteroid[m].position.x + chonkAsteroid[i].radius / 2, chonkAsteroid[m].position.y + chonkAsteroid[i].radius / 2 };
									asteroid[asteroidsCount].direction = Vector2{ -cos(shoot[i].rotation * PI / 180) * 2, sin(shoot[i].rotation * PI / 180) * 2};
								}

								asteroid[asteroidsCount].active = true;
								asteroidsCount++;
							}
						}
					}
					for (int m = 0; m < asteroidMax; m++) {
						if (asteroid[m].active && CheckCollisionCircles(shoot[i].position, shoot[i].radius, asteroid[m].position, asteroid[m].radius)) {
							shoot[i].bulletLife = 0;
							shoot[i].active = false;
							asteroid[m].active = false;
							asteroidsDestroyed++;
							player.score += asteroid[m].scoreIncrease;
							if (player.score >= (player.livesGained * gainLifeScore)) player.canGainLife = true;

							for (int a = 0; a < 2; a++) {
								if (smolAsteroidsCount % 2 == 0) {
									smolAsteroid[smolAsteroidsCount].position = Vector2{ asteroid[m].position.x, asteroid[m].position.y };
									smolAsteroid[smolAsteroidsCount].direction = Vector2{ cos(shoot[i].rotation * PI / 180) * 2, -sin(shoot[i].rotation * PI / 180) * 2};
								}
								else {
									smolAsteroid[smolAsteroidsCount].position = Vector2{ asteroid[m].position.x, asteroid[m].position.y };
									smolAsteroid[smolAsteroidsCount].direction = Vector2{ -cos(shoot[i].rotation * PI / 180) * 2, sin(shoot[i].rotation * PI / 180) * 2};
								}

								smolAsteroid[smolAsteroidsCount].active = true;
								smolAsteroidsCount++;
							}
						}
					}
					for (int m = 0; m < smolAsteroidMax; m++) {
						if (smolAsteroid[m].active && CheckCollisionCircles(shoot[i].position, shoot[i].radius, smolAsteroid[m].position, smolAsteroid[m].radius)) {
							shoot[i].bulletLife = 0;
							shoot[i].active = false;
							smolAsteroid[m].active = false;
							asteroidsDestroyed++;
							player.score += smolAsteroid[m].scoreIncrease;
							if (player.score >= (player.livesGained * gainLifeScore)) player.canGainLife = true;
							asteroidSpawner++;

							if (asteroidSpawner % 4 == 0) {
								asteroidSpawner = 0;
								
								chonkAsteroidAmount++;
								
								for (int i = chonkAsteroidAmount + 1; i < chonkAsteroidAmount + 2; i++) {
									if (chonkAsteroidAmount < chonkAsteroidMax) {
										int randX, randY;
										bool validDir = false;

										randX = GetRandomValue(0, screenW); //gets 2 random values and sets them as the direction to travel
										while (!validDir) {
											if (randX > screenW / 2 - 500 && randX < screenW / 2 + 500) randX = GetRandomValue(0, screenW);
											else validDir = true;
										}
										validDir = false;

										randY = GetRandomValue(0, screenH);
										while (!validDir) {
											if (randY > screenH / 2 - 400 && randY < screenH / 2 + 400) randY = GetRandomValue(0, screenH);
											else validDir = true;
										}

										chonkAsteroid[i].position = Vector2{ (float)randX, (float)randY };
										chonkAsteroid[i].direction = Vector2{ (float)GetRandomValue(-3, 3), (float)GetRandomValue(-3, 3) };
										if (chonkAsteroid[i].direction.x == 0 && chonkAsteroid[i].direction.y == 0) chonkAsteroid[i].direction = Vector2{ (float)GetRandomValue(-3, 3), (float)GetRandomValue(-3, 3) };

										chonkAsteroid[i].radius = 68;
										chonkAsteroid[i].color = LIGHTYELLOW;
										chonkAsteroid[i].scoreIncrease = 250;
										chonkAsteroid[i].active = true;
									}
								}
							}
						}
					}
				}
			}

			//if an asteroid hits the player, kill them -- 3 of these cause I couldn't combine them without errors
			for (int i = 0; i < smolAsteroidMax; i++) {
				//checks the collision using circles, creates a circle around the bottom portion of the player, and checks if it overlaps with an asteroid
				if (CheckCollisionCircles(Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f) },
					player.collisionRad, smolAsteroid[i].position, smolAsteroid[i].radius) && smolAsteroid[i].active) {
					if (player.hittable) {
						player.hittable = false;
						player.lifeCount--;
						player.immunityTimer = 120;
					}
				}
			}
			for (int i = 0; i < asteroidMax; i++) {
				if (CheckCollisionCircles(Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f) }, 
					player.collisionRad, asteroid[i].position, asteroid[i].radius) && asteroid[i].active) {
					if (player.hittable) {
						player.hittable = false;
						player.lifeCount--;
						player.immunityTimer = 120;
					}
				}
			}
			for (int i = 0; i < chonkAsteroidMax; i++) {
				if (CheckCollisionCircles(Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f) }, 
					player.collisionRad, chonkAsteroid[i].position, chonkAsteroid[i].radius) && chonkAsteroid[i].active) {
					if (player.hittable) {
						player.hittable = false;
						player.lifeCount--;
						player.immunityTimer = 120;
					}
				}
			}

			//ROTATION -- That epic rotate yo
			/*player.direction.x = sin(player.rotation * PI / 180.0f) * 1.2f;
			player.direction.y = cos(player.rotation * PI / 180.0f) * 1.2f;*/

			//resets the player direction if it goes over a 360 / below -360
			if (player.rotation > 360 || player.rotation < -360) player.rotation = 0;

			//IMMUNITY -- so you dont just instantly die when getting bonked by an asteroid
			if (player.immunityTimer <= 0) player.hittable = true;
			else if (player.immunityTimer > 0) player.immunityTimer--;

			//LIVES -- get lives when reaching a certain score threshold
			if (player.score >= (player.livesGained * gainLifeScore) && player.canGainLife && player.lifeCount != player.lifeMax) {
				player.lifeCount++;
				player.livesGained++;
				player.canGainLife = false;
			}

			//MOVEMENT -- Moving the ship forwards
			player.position.x += (player.direction.x * player.acceleration);
			player.position.y -= (player.direction.y * player.acceleration);
			//constantly updates position in the facing direction x the ships acceleration

			//SHOOTING MOVEMENT -- Moves the bullets constantly
			for (int i = 0; i < maxShots; i++) {
				if (shoot[i].active) {
					shoot[i].position.x += shoot[i].direction.x;
					shoot[i].position.y -= shoot[i].direction.y;
					shoot[i].bulletLife++;
				}
				if (shoot[i].bulletLife >= shoot[i].lifeSpanMax) {
					shoot[i].active = false;
				}
			}

			//victory / game over condition: if you run out of lives, die | if you destroy the asteroids, win
			if (asteroidsDestroyed >= asteroidsRequired) victory = true;
			if (player.lifeCount <= 0) gameOver = true;
		}
		else {
			if (IsKeyPressed(KEY_ENTER)) {
				Initialise();
				gameOver = false;
				victory = false;
			}
		}
	}
	else {
		if (IsKeyPressed(KEY_ENTER)) {
			Initialise();
			gameOver = false;
			victory = false;
		}
	}
}

void Draw() {
	BeginDrawing();

	ClearBackground(DARKERDEEPBLUE);
	DrawRectangle(0, 0, screenW, 300, DEEPBLUE);
	DrawRectangle(0, 300, screenW, 300, DARKDEEPBLUE);

	if (!gameOver) {
		//DRAW PLAYER -- Draws the player based on math stuff to create a triangle
		Vector2 v1{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 2.0f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 2.0f) };
		Vector2 v2{ player.position.x - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f), player.position.y - sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f) };
		Vector2 v3{ player.position.x + cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f), player.position.y + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f) };

		if (player.hittable) DrawTriangleLines(v1, v2, v3, player.color);
		else DrawTriangleLines(v1, v2, v3, RED);
		//mansplaining time on these calculations because I WILL forget what they do later.
		//v1 calculates the tip of the triangle in a vector 2 by feeding the x pos + Sin(rotation * Pi / 180), then offsetting it by the shipsize. we multiple the shipsize by 2 
		//to get a larger offset before doing the same thing with CoSine and the y position, this time subtracting the y pos to get a consistant triangle when rotating
		//v2 calculates the left point in a Vector 2 by running rotation through CoSine and subtracting that from the position. the smaller multiplier is to reduce the width of the ship
		//v3 calculates the same way v2 does, but now adds the position to the rotation calculations, rather than subtracts, and the smaller multi reduces the width
		// finally, DrawTriangleLines draws lines between the 3 vectors using the players color. 
		//math hurts. these calculations were adapted from https://stackoverflow.com/questions/3837266/finding-the-points-of-a-triangle-after-rotation 

		//SCORE & LIFE DISPLAY -- time to copy paste some math stuff
		DrawText(TextFormat("SCORE: %05i", player.score), 50, 50, 20, WHITE);

		DrawText("LIVES: ", 210, 50, 20, WHITE);
		for (int i = 0; i < player.lifeCount - 1; i++) {
			Vector2 lv1{ (290 + (i * 30)) + sinf(45 * PI / 180.0f) * ((player.shipSize - 4) * 1.5f), 65 - cosf(45 * PI / 180.0f) * ((player.shipSize - 4) * 1.5f) };
			Vector2 lv2{ (290 + (i * 30)) - cosf(45 * PI / 180.0f) * ((player.shipSize - 4) * 0.5f), 65 - sinf(45 * PI / 180.0f) * ((player.shipSize - 4) * 0.5f) };
			Vector2 lv3{ (290 + (i * 30)) + cosf(45 * PI / 180.0f) * ((player.shipSize - 4) * 0.5f), 65 + sinf(45 * PI / 180.0f) * ((player.shipSize - 4) * 0.5f) };

			DrawTriangleLines(lv1, lv2, lv3, player.color);
		}

		//DRAW ASTEROIDS -- draws the Asteroids as cicles using the position
		for (int i = 0; i < smolAsteroidMax; i++) {
			if (smolAsteroid[i].active) DrawCircleLines(smolAsteroid[i].position.x, smolAsteroid[i].position.y, smolAsteroid[i].radius, smolAsteroid[i].color);
		}
		for (int i = 0; i < asteroidMax; i++) {
			if (asteroid[i].active) DrawCircleLines(asteroid[i].position.x, asteroid[i].position.y, asteroid[i].radius, asteroid[i].color);
		}
		for (int i = 0; i < chonkAsteroidMax; i++) {
			if (chonkAsteroid[i].active) DrawCircleLines(chonkAsteroid[i].position.x, chonkAsteroid[i].position.y, chonkAsteroid[i].radius, chonkAsteroid[i].color);
		}

		//DRAW SHOTS -- Whenever a shot is active, draw it
		for (int i = 0; i < maxShots; i++) {
			if (shoot[i].active) {
				DrawCircleV(shoot[i].position, shoot[i].radius, shoot[i].color);
			}
		}

		//DEBUGGING STUFF -- stuff used for debugging and general information
		if (debugActive) {
			DrawText(TextFormat("POS X: %01i", (int)player.position.x), 50, 90, 20, WHITE);
			DrawText(TextFormat("POS Y: %01i", (int)player.position.y), 50,110, 20, WHITE);
			DrawText(TextFormat("ROTATION : %01i", (int)player.rotation), 50, 130, 20, WHITE);
			DrawText(TextFormat("CHONKERS : %01i", chonkAsteroidsCount), 50, 150, 20, WHITE);
			DrawText(TextFormat("REGULARS : %01i", asteroidsCount), 50, 170, 20, WHITE);
			DrawText(TextFormat("SMOLS : %01i", smolAsteroidsCount), 50, 190, 20, WHITE);
			DrawText(TextFormat("DESTROYED ASTROIDS : %01i", asteroidsDestroyed), 50, 210, 20, WHITE);
			DrawText(TextFormat("ASTROIDS REQUIRED: %01i", asteroidsRequired), 50, 230, 20, WHITE);
			DrawText(TextFormat("IMMUNITY TIMER: %01i", player.immunityTimer), 50, 250, 20, WHITE);
			DrawCircleLines(player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.collisionRad + 1, RED);
		}

		if (victory) DrawText("VICTORY  -- PRESS [ENTER]", 400, 450, 60, WHITE);
	}
	else DrawText("GAME OVER -- PRESS [ENTER]", 350, 450, 60, WHITE); //gameover text

	EndDrawing();
}
