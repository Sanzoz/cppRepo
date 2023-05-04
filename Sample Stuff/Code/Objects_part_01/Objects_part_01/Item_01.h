#pragma once // <-- telling visual studio to include this class "once" when the compiler, compiles the code

//#ifndef _ITEM_01_H_ //<-- same as #pragma once 
//#define _ITEM_01_H_

#include <iostream>
#include <string>
#include "inputCheck.h"
using namespace std;


class Item_01{
public:
	Item_01(); // constructor , same name as class , no return type
	// Default contructor, not take any argument 
	// when you make an array of class, you can "only" use the default contructor

	Item_01(float value); // overloaded constructor
	Item_01(string n, float value); // overloaded constructor

	~Item_01();

	inputCheck* inputReciver = new inputCheck();

public:
	void Move(float value);
	void Stop();
	float GetSpeed();
	
	string dbug();

	int id = 0;
	string Name = "";
	int Health = 100;

private:
	float speed = 1.f;
	float MAXspeed = 40.f;

};

//#endif !_ITEM_01_H_

// Preprocessor directives
// https://www.cplusplus.com/doc/tutorial/preprocessor/