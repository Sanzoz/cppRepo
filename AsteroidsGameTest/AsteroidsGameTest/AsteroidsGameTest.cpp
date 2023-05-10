#include <iostream>
#include <raylib.h>
#include "main.h"
#include "CustomColours.h"
using namespace std;

struct Player {
public:
	Vector2 position;
	Vector2 direction;
	float acceleration;
	float rotation;
	float speed;
	float shipSize;
	Vector3 collider;
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
struct Meteor {
public:
	Vector2 position;
	Vector2 direction;
	float radius;
	bool active;
	Color color;
};

bool gameOver;
bool paused;

Player player = { 0 };
Shoot shoot[] = { 0 };

Meteor smolMeteor[] = { 0 };
Meteor midMeteor[] = { 0 };
Meteor chonkMeteor[] = { 0 };

int main() {

	InitWindow(screenW, screenH, "ASTEROIDS TEST");
	SetTargetFPS(60);

	Initialise();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}
}

void Initialise() {
	gameOver = false;

	//PLAYER INITIALISATION
	player.shipSize = 20;
	player.position = Vector2{ screenW / 2, screenH / 2 - player.shipSize / 2 };
	player.direction = Vector2{ 0, 0};
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
	for (int i = 0; i < 50; i++) {
		smolMeteor[i].position = Vector2{ 0, 0 };
		smolMeteor[i].direction = Vector2{ 0, 0 };
		smolMeteor[i].radius = 6;
		smolMeteor[i].active = false;
		smolMeteor[i].color = LIGHTERGRAY;
	}
	//MID METEOR INITIALISATION
	for (int i = 0; i < 50; i++) {
		midMeteor[i].position = Vector2{ 0, 0 };
		midMeteor[i].direction = Vector2{ 0, 0 };
		midMeteor[i].radius = 13.5f;
		midMeteor[i].active = false;
		midMeteor[i].color = LIGHTERGRAY;
	}
	//CHONK METEOR INITIALISATION
	for (int i = 0; i < 50; i++) {
		chonkMeteor[i].position = Vector2{ 0, 0 };
		chonkMeteor[i].direction = Vector2{ 0, 0 };
		chonkMeteor[i].radius = 22;
		chonkMeteor[i].active = false;
		chonkMeteor[i].color = LIGHTERGRAY;
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
					shoot[i].position = Vector2 { player.position.x, player.position.y };
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
				if (shoot[i].position.x > GetScreenWidth() || shoot[i].position.x < 0 || 
					shoot[i].position.y > GetScreenHeight() || shoot[i].position.y < 0) {
					
					shoot[i].active = false;
				}
			}
		}

		smolMeteor[0].active;

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
		Vector2 v1{ player.position.x + sinf(player.rotation * DEG2RAD) * (player.shipSize * 2), player.position.y - cosf(player.rotation * DEG2RAD) * (player.shipSize * 2) };
		Vector2 v2{ player.position.x - cosf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f), player.position.y - sinf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f) };
		Vector2 v3{ player.position.x + cosf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f), player.position.y + sinf(player.rotation * DEG2RAD) * (player.shipSize * 0.75f) };
		DrawTriangle(v1, v2, v3, player.color);
		
		for (int i = 0; i < 256; i++) {
			if (shoot[i].active) {
				DrawCircleV(shoot[i].position, shoot[i].radius, shoot[i].color);
			}
		}
		for (int i = 0; i < 256; i++) {
			if (smolMeteor[i].active) {
				DrawCircleV(smolMeteor[i].position, smolMeteor[i].radius, smolMeteor[i].color);
			}
		}
		for (int i = 0; i < 256; i++) {
			if (midMeteor[i].active) {
				DrawCircleV(midMeteor[i].position, midMeteor[i].radius, midMeteor[i].color);
			}
		}
		for (int i = 0; i < 256; i++) {
			if (chonkMeteor[i].active) {
				DrawCircleV(chonkMeteor[i].position, chonkMeteor[i].radius, chonkMeteor[i].color);
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
