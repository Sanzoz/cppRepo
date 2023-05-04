#pragma once
	
	const int screenW = 1280;
	const int screenH = 768;

	const int snakeLength = 256;
	const int tileSize = 55;

	bool gameOver;
	int framesCounter;
	int score;

	int tailCounter; //counts the tail length
	bool canMove;

	void Initialize();
	void Update();
	void Draw();
