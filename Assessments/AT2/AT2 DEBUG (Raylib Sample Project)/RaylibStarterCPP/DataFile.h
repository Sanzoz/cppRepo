#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
	//defines the Record
public:
	struct Record {
		Image image;
		string name;
		int age;
	};

private:
	//record count: how many records are within the data
	int recordCount;
	//std::vector<Record*> records;	// delete this vector. Load only the required record 



public:
	//initialization of methods
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index);



	int GetRecordCount() { return recordCount; };

	void Save(string filename);
	void Load(string filename, int index);

	//vector to hold the position of each record
	vector<int>currentPos;

private:
	void Clear();

};

