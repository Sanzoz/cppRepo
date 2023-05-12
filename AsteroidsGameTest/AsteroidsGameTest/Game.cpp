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
	int randX, randY;
	int dirX, dirY;
	bool validDir = false;

	debugActive = false;
	gameOver = false;
	asteroidsDestroyed = 0;

	//PLAYER INITIALISATION
	player.shipSize = 20;
	player.position = Vector2{ screenW / 2, screenH / 2 - player.shipSize / 2 };
	player.direction = Vector2{ 0, 0 };
	player.collisionRad = 12;
	player.acceleration = 0;
	player.rotation = 0;
	player.color = MALACHITE;

	//SHOOTING INITIALISATION
	for (int i = 0; i < maxShots; i++) {
		shoot[i].position = Vector2{ 0, 0 };
		shoot[i].direction = Vector2{ 0, 0 };
		shoot[i].radius = 3.5f;
		shoot[i].shotSpeed = 7.5f;
		shoot[i].active = false;
		shoot[i].bulletLife = 0;
		shoot[i].color = WHITE;
	}

	//ASTEROID INITIALISATION
	for (int i = 0; i < smolAsteroidMax; i++) {
		smolAsteroid[i].position = Vector2{ -100, -100 };
		smolAsteroid[i].direction = Vector2{ 0, 0 };
		smolAsteroid[i].radius = 16;
		smolAsteroid[i].active = false;
		smolAsteroid[i].color = EVENLIGHTERGRAY;
	}
	for (int i = 0; i < asteroidMax; i++) {
		asteroid[i].position = Vector2{ -100, -100 };
		asteroid[i].direction = Vector2{ 0, 0 };
		asteroid[i].radius = 38;
		asteroid[i].active = false;
		asteroid[i].color = EVENLIGHTERGRAY;
	}
	for (int i = 0; i < chonkAsteroidAmount; i++) {
		randX = GetRandomValue(0, screenW);
		while (!validDir) {
			if (randX > screenW / 2 - 50 && randX < screenW / 2 + 50) randX = GetRandomValue(0, screenW);
			else validDir = true;
		}
		validDir = false;

		randY = GetRandomValue(0, screenH);
		while (!validDir) {
			if (randY > screenH / 2 - 50 && randY < screenH / 2 + 50) randY = GetRandomValue(0, screenH);
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
		chonkAsteroid[i].active = true;
		chonkAsteroid[i].color = LIGHTYELLOW;
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
			if (IsKeyDown(KEY_LEFT)) player.rotation -= 3.5f;
			if (IsKeyDown(KEY_RIGHT)) player.rotation += 3.5f;

			//PLAYER MOVEMENT INPUTS -- gets up and down keys and increases ships acceleration
			//slows down the ship by default if no key is pressed by half the deceleration speed
			if (IsKeyDown(KEY_UP)) {
				if (player.acceleration < 4) player.acceleration += 0.4f;
			}
			else {
				if (player.acceleration > 0) player.acceleration -= 0.04f;
				else if (player.acceleration < 0) player.acceleration = 0; //if the acceleration is lower than 0, set to 0
			}																//prevents ship from gliding backwards
			if (IsKeyDown(KEY_DOWN)) {

				if (player.acceleration > 0) player.acceleration -= 0.08f;
				else if (player.acceleration < 0) player.acceleration = 0;
			}

			//SHOOTING INPUTS -- gets the space bar to when to shoot
			if (IsKeyPressed(KEY_SPACE)) {
				for (int i = 0; i < maxShots; i++) {
					if (!shoot[i].active) {
						shoot[i].position = Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * player.shipSize * 2, player.position.y - cosf(player.rotation * PI / 180.0f) * player.shipSize * 2};
						shoot[i].active = true;
						shoot[i].direction.x = 1.5 * sin(player.rotation * PI / 180.0f) * shoot[i].shotSpeed;
						shoot[i].direction.y = 1.5 * cos(player.rotation * PI / 180.0f) * shoot[i].shotSpeed;
						shoot[i].rotation = player.rotation;
						break;
					}
				}
			}

			//PLAYER WALL COLLISION -- if you hit a wall, move to the opposite side
			if (player.position.x > screenW + player.shipSize) player.position.x = -(player.shipSize);
			else if (player.position.x < -player.shipSize) player.position.x = screenW + player.shipSize;
			if (player.position.y > screenH + player.shipSize) player.position.y = -(player.shipSize);
			else if (player.position.y < -player.shipSize) player.position.y = screenH + player.shipSize;

			//SHOT WALL COLLISION -- if your shot hits a wall, delete the projectile
			for (int i = 0; i < maxShots; i++) {
				if (shoot[i].active) {
					if (shoot[i].position.x > GetScreenWidth() + shoot[i].radius || shoot[i].position.x < 0 + shoot[i].radius ||
						shoot[i].position.y > GetScreenHeight() + shoot[i].radius || shoot[i].position.y < 0 + shoot[i].radius) {

						shoot[i].active = false;
					}
				}
			}

			//ASTEROID MOVEMENT AND WALL COLLISION -- Asteroids go weeeeeEEEEEEEEE and when the asteroid hits a wall, loop around like the player
			for (int i = 0; i < smolAsteroidMax; i++) {
				if (smolAsteroid[i].active) {

					smolAsteroid[i].position.x += smolAsteroid[i].direction.x;
					smolAsteroid[i].position.y -= smolAsteroid[i].direction.y;

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

			//ASTEROID BULLET COLLISION -- when you shoot an asteroid, explode it and split it into 2
			for (int i = 0; i < maxShots; i++) {
				if (shoot[i].active) {
					for (int j = 0; j < smolAsteroidMax; j++) {
						if (smolAsteroid[j].active && CheckCollisionCircles(shoot[i].position, shoot[i].radius, smolAsteroid[j].position, smolAsteroid[j].radius)) {
							shoot[i].active = false;
							smolAsteroid[j].active = false;
							asteroidsDestroyed += 1;
						}
					}
					for (int n = 0; n < asteroidMax; n++) {
						if (asteroid[n].active && CheckCollisionCircles(shoot[i].position, shoot[i].radius, asteroid[n].position, asteroid[n].radius)) {
							shoot[i].active = false;
							asteroid[n].active = false;
							asteroidsDestroyed += 1;

							int temp = smolAsteroidsCount;
							int target = temp + 2;

							for (int l = temp; l < target; l++) {
								smolAsteroid[l].position = asteroid[n].position;
								smolAsteroid[l].direction = Vector2{ cosf(shoot[i].rotation * PI / 180.0f) * 3 * -1, sinf(shoot[i].rotation * PI / 180.0f) * 3 * -1 };
								smolAsteroid[l].active = true;
								smolAsteroid[l].color = LIGHTRED;

								smolAsteroid[l + 1].position = asteroid[n].position;
								smolAsteroid[l + 1].direction = Vector2{ cosf(shoot[i].rotation * PI / 180.0f) * 3, sinf(shoot[i].rotation * PI / 180.0f) * 3 };
								smolAsteroid[l + 1].active = true;
								smolAsteroid[l + 1].color = LIGHTRED;

								smolAsteroidsCount += 2;
							}
						}
					}
					for (int m = 0; m < chonkAsteroidMax; m++) {
						if (chonkAsteroid[m].active && CheckCollisionCircles(shoot[i].position, shoot[i].radius, chonkAsteroid[m].position, chonkAsteroid[m].radius)) {
							shoot[i].active = false;
							chonkAsteroid[m].active = false;
							asteroidsDestroyed += 1;

							int temp = asteroidsCount;
							int target = temp + 2;

							for (int l = temp; l < target; l++) {
								asteroid[l].position = chonkAsteroid[m].position;
								asteroid[l].direction = Vector2{ cosf(shoot[i].rotation * PI / 180.0f) * 3 * -1, sinf(shoot[i].rotation * PI / 180.0f) * 3 * -1 };
								asteroid[l].active = true;
								asteroid[l].color = LIGHTORANGE;

								asteroid[l + 1].position = chonkAsteroid[m].position;
								asteroid[l + 1].direction = Vector2{ cosf(shoot[i].rotation * PI / 180.0f) * 3, sinf(shoot[i].rotation * PI / 180.0f) * 3 };
								asteroid[l + 1].active = true;
								asteroid[l + 1].color = LIGHTORANGE;

								asteroidsCount += 2;
							}
						}
					}
				}
			}

			//if an asteroid hits the player, kill them
			for (int i = 0; i < smolAsteroidMax; i++) {
				if (CheckCollisionCircles(Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f) },
					player.collisionRad, smolAsteroid[i].position, smolAsteroid[i].radius) && smolAsteroid[i].active) gameOver = true;
			}
			for (int i = 0; i < asteroidMax; i++) {
				if (CheckCollisionCircles(Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f) },
					player.collisionRad, asteroid[i].position, asteroid[i].radius) && asteroid[i].active) gameOver = true;
			}
			for (int i = 0; i < chonkAsteroidMax; i++) {
				if (CheckCollisionCircles(Vector2{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f) },
					player.collisionRad, chonkAsteroid[i].position, chonkAsteroid[i].radius) && chonkAsteroid[i].active) gameOver = true;
			}

			//ROTATION -- That epic rotate yo
			player.direction.x = sin(player.rotation * PI / 180.0f) * 1.2f;
			player.direction.y = cos(player.rotation * PI / 180.0f) * 1.2f;
			//facing direction ^^ -- dictates how where ship moves towards

			if (player.rotation > 360 || player.rotation < -360) player.rotation = 0;

			//MOVEMENT -- Moving the ship forwards
			player.position.x += (player.direction.x * player.acceleration);
			player.position.y -= (player.direction.y * player.acceleration);
			//constantly updates position in the facing direction x the ships acceleration

			//SHOOTING MOVEMENT -- Moves the bullets constantly
			for (int i = 0; i < maxShots; i++) {
				if (shoot[i].active) {
					shoot[i].position.x += shoot[i].direction.x;
					shoot[i].position.y -= shoot[i].direction.y;

					if (shoot[i].active) DrawText(TextFormat("SHOT ROTATION : %01i", smolAsteroidsCount), 50, 300 + (i * 10), 8, WHITE);
				}
			}


			if (asteroidsDestroyed >= asteroidsRequired) victory = true;
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

	ClearBackground(DARKERGRAY);

	if (!gameOver) {
		//DRAW PLAYER -- Draws the player based on math stuff to create a triangle
		Vector2 v1{ player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 2.0f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 2.0f) };
		Vector2 v2{ player.position.x - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f), player.position.y - sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f) };
		Vector2 v3{ player.position.x + cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f), player.position.y + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.7f) };

		DrawTriangleLines(v1, v2, v3, player.color);
		//v1 calculates the tip of the triangle in a vector 2 by feeding the x pos + Sin(rotation * Pi / 180), then offsetting it by the shipsize. we multiple the shipsize by 2 
		//to get a larger offset before doing the same thing with CoSine and the y position, this time subtracting the y pos to get a consistant triangle when rotating
		//v2 calculates the left point in a Vector 2 by running rotation through CoSine and subtracting that from the position. the smaller multiplier is to get a ship that looks
		//more similar to the original retro game one
		//v3 calculates the same way v2 does, but now adding the position to the rotation calculations
		//math hurts, and the calculations were adapted from https://stackoverflow.com/questions/3837266/finding-the-points-of-a-triangle-after-rotation 

		//DRAW ASTEROIDS -- draws the Asteroids using the position
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

		if (victory) DrawText("VICTORY  -- PRESS [ENTER]", 400, 450, 60, WHITE);

		DrawText("J - DEBUG STUFF", 50, 880, 16, WHITE);

		//DEBUGGING STUFF -- stuff used for debugging and general information
		if (debugActive) {
			DrawText(TextFormat("POS X: %01i", (int)player.position.x), 50, 50, 20, WHITE);
			DrawText(TextFormat("POS Y: %01i", (int)player.position.y), 50, 70, 20, WHITE);
			DrawText(TextFormat("ROTATION : %01i", (int)player.rotation), 50, 90, 20, WHITE);
			DrawText(TextFormat("CHONKERS : %01i", chonkAsteroidsCount), 50, 110, 20, WHITE);
			DrawText(TextFormat("REGULARS : %01i", asteroidsCount), 50, 130, 20, WHITE);
			DrawText(TextFormat("SMOLS : %01i", smolAsteroidsCount), 50, 150, 20, WHITE);
			DrawText(TextFormat("DESTROYED ASTROIDS : %01i", asteroidsDestroyed), 50, 170, 20, WHITE);
			DrawText(TextFormat("ASTROIDS REQUIRED: %01i", asteroidsRequired), 50, 190, 20, WHITE);
			DrawCircleLines(player.position.x + sinf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.position.y - cosf(player.rotation * PI / 180.0f) * (player.shipSize * 0.5f), player.collisionRad + 1, RED);
		}
	}
	else DrawText("GAME OVER -- PRESS [ENTER]", 350, 450, 60, WHITE); //gameover text

	EndDrawing();
}
