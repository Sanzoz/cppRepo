#include <iostream>
#include <raylib.h>
#include "test.h"
#include "whyisitbroken.h"
//#include "Shoot.h"
//#include "Asteroids.h"
//#include "CustomColours.h"
using namespace std;

const int screenW = 1600;
const int screenH = 900;

bool gameOver;

const int smolAsteroidmax = 5;

struct Player {
public:
	Vector2 position;
	Vector2 direction;
	float acceleration;
	float rotation;
	float speed;
	float shipSize;
	float collisionRad;
	Color color;
};

struct Shoot {
public:
	Vector2 position;
	Vector2 direction;
	float radius;
	float rotation;
	float shotSpeed;
	int bulletLife;
	bool active;
	Color color;
};

struct Asteroids {
public:
	Vector2 position;
	Vector2 direction;
	float radius;
	bool active;
	Color color;
};

Color MALACHITE{ 100, 233, 134, 255 };
Color DARKMALACHITE{ 70, 203, 104, 255 };
Color DARKERMALACHITE{ 40, 173, 74, 255 };

Color DARKERGRAY{ 34, 34, 34, 255 };
Color LIGHTERGRAY{ 74, 74, 74, 255 };

Player player = { 0 };
Shoot shoot[] = { 0 };

Asteroids smolAsteroid[smolAsteroidmax] = { 0 };
Asteroids asteroid[] = { 0 };
Asteroids chonkAsteroid[] = { 0 };

int WinMain() {

	InitWindow(screenW, screenH, "ASTEROIDS TEST");
	SetTargetFPS(60);

	Initialise();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}
}

void Initialise() {
	int randX, randY;
	int dirX, dirY;
	bool validDir = false;

	gameOver = false;

	//PLAYER INITIALISATION
	player.shipSize = 20;
	player.position = Vector2{ (float)screenW / 2, (float)screenH / 2 - player.shipSize / 2 };
	player.direction = Vector2{ 0, 0 };
	player.collisionRad = 12;
	player.acceleration = 0;
	player.rotation = 0;
	player.color = MALACHITE;

	//SHOOTING INITIALISATION
	for (int i = 0; i < 256; i++) {
		shoot[i].position = Vector2{ 0, 0 };
		shoot[i].direction = Vector2{ 0, 0 };
		shoot[i].radius = 3.5f;
		shoot[i].shotSpeed = 7.5f;
		shoot[i].active = false;
		shoot[i].bulletLife = 0;
		shoot[i].color = WHITE;
	}

	//SMOL METEOR INITIALISATION
	for (int i = 0; i < smolAsteroidmax; i++) {
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

		smolAsteroid[i].position = Vector2{ (float)randX, (float)randY };

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

		smolAsteroid[i].direction = Vector2{ (float)dirX, (float)dirY };
		smolAsteroid[i].radius = 16;
		smolAsteroid[i].active = true;
		smolAsteroid[i].color = RAYWHITE;
	}

}

void Update() {
	if (!gameOver) {
		//PLAYER ROTATION INPUTS -- gets left and right keys to rotate the ship
		if (IsKeyDown(KEY_LEFT)) player.rotation -= 2.5f;
		if (IsKeyDown(KEY_RIGHT)) player.rotation += 2.5f;

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
			for (int i = 0; i < 256; i++) {
				if (!shoot[i].active) {
					shoot[i].position = Vector2{ player.position.x, player.position.y };
					shoot[i].active = true;
					shoot[i].direction.x = sin(player.rotation * DEG2RAD) * shoot[i].shotSpeed;
					shoot[i].direction.y = cos(player.rotation * DEG2RAD) * shoot[i].shotSpeed;
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
		for (int i = 0; i < 50; i++) {
			if (shoot[i].active) {
				if (shoot[i].position.x > GetScreenWidth() + shoot[i].radius || shoot[i].position.x < 0 + shoot[i].radius ||
					shoot[i].position.y > GetScreenHeight() + shoot[i].radius || shoot[i].position.y < 0 + shoot[i].radius) {

					shoot[i].active = false;
				}
			}
		}

		//ASTEROID WALL COLLISION -- 
		for (int i = 0; i < smolAsteroidmax; i++) {
			if (smolAsteroid[i].active) {
				if (smolAsteroid[i].position.x > screenW + smolAsteroid[i].radius) smolAsteroid[i].position.x = -(smolAsteroid[i].radius);
				else if (smolAsteroid[i].position.x < -smolAsteroid[i].radius) smolAsteroid[i].position.x = screenW + smolAsteroid[i].radius;
				if (smolAsteroid[i].position.y > screenH + smolAsteroid[i].radius) smolAsteroid[i].position.y = -(smolAsteroid[i].radius);
				else if (smolAsteroid[i].position.y < -smolAsteroid[i].radius) smolAsteroid[i].position.y = screenH + smolAsteroid[i].radius;
			}
		}

		for (int i = 0; i < smolAsteroidmax; i++) {
			if (CheckCollisionCircles(Vector2{ player.position.x, player.position.y }, player.collisionRad, smolAsteroid[i].position, smolAsteroid[i].radius) && smolAsteroid[i].active) gameOver = true;
		}

		//ROTATION -- That epic rotate yo
		player.direction.x = sin(player.rotation * DEG2RAD) * 1;
		player.direction.y = cos(player.rotation * DEG2RAD) * 1;
		//facing direction ^^ -- dictates how where ship moves towards

		if (player.rotation >= 360 || player.rotation <= -360) player.rotation = 0;
		//if the rotation is greater than 360­­­° or less than -360°, reset it to 0 -- makes the rotation debug look neat

		//MOVEMENT -- Moving the ship forwards
		player.position.x += (player.direction.x * player.acceleration);
		player.position.y -= (player.direction.y * player.acceleration);
		//constantly updates position in the facing direction x the ships acceleration

		//SHOOTING MOVEMENT -- Moves the bullets constantly
		for (int i = 0; i < 50; i++) {
			if (shoot[i].active) {
				shoot[i].position.x += shoot[i].direction.x;
				shoot[i].position.y -= shoot[i].direction.y;
			}
		}

		//ASTEROID MOVEMENT -- asteroid go weeeeeeeeeeeEEEEEEEEEEEEEEEEEEEEE
		for (int i = 0; i < smolAsteroidmax; i++) {
			if (smolAsteroid[i].active) {
				smolAsteroid[i].position.x += smolAsteroid[i].direction.x;
				smolAsteroid[i].position.y -= smolAsteroid[i].direction.y;
			}
		}
	}
	else {
		if (IsKeyPressed(KEY_ENTER)) {
			Initialise();
			gameOver = false;
		}
	}
}

void Draw() {
	BeginDrawing();

	ClearBackground(DARKERGRAY);

	if (!gameOver) {
		//DRAW PLAYER -- Draws the player based on math stuff to create a triangle
		Vector2 v1{ player.position.x + sinf(player.rotation * DEG2RAD) * (player.shipSize * 2), player.position.y - cosf(player.rotation * DEG2RAD) * (player.shipSize * 2) };
		Vector2 v2{ player.position.x - cosf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f), player.position.y - sinf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f) };
		Vector2 v3{ player.position.x + cosf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f), player.position.y + sinf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f) };

		//v1 calculates the tip of the triangle and stores it into a Vector 2 -- | x + sin(z * (pi / 180) * (s * 2)), y - cos(z * (pi / 180) * (s * 2)) |
		//v2 calculates the left point on the triangle and stores it into a Vector 2 -- | x - sin(z * (pi / 180) * (s * 0.75)), y - cos(z * (pi / 180) * (s * 0.75)) |
		//v3 calculates the right point on the triangle and stores it into a Vector 2 -- | x + sin(z * (pi / 180) * (s * 2)), y + cos(z * (pi / 180) * (s * 2)) |

		DrawTriangle(v1, v2, v3, player.color);

		//DRAW METEORS -- draws circles
		for (int i = 0; i < smolAsteroidmax; i++) {
			if (smolAsteroid[i].active) DrawCircleV(smolAsteroid[i].position, smolAsteroid[i].radius, smolAsteroid[i].color);
		}

		//DRAW SHOTS -- Whenever a shot is active, draw it
		for (int i = 0; i < 50; i++) {
			if (shoot[i].active) {
				DrawCircleV(shoot[i].position, shoot[i].radius, shoot[i].color);
			}
		}

		//DEBUGGING STUFF -- stuff used for debugging and general information
		DrawText(TextFormat("POS X: %01i", (int)player.position.x), 100, 100, 20, WHITE);
		DrawText(TextFormat("POS Y: %01i", (int)player.position.y), 100, 120, 20, WHITE);
		DrawText(TextFormat("ROTATION : %01i", (int)player.rotation), 100, 140, 20, WHITE);
	}
	else DrawText("GAME OVER", 800, 450, 50, WHITE); //gameover text

	EndDrawing();
}
