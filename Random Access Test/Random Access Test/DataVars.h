#pragma once

#include <iostream>
#include <string>
using namespace std;

class Data {

public:
	struct Record {
		string name;
		int age;
	};

private:
	int recordCount;


public:
	void Processing();

};