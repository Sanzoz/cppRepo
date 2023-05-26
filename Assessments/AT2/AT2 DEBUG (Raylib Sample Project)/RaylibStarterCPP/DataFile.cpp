#include "DataFile.h"
#include <fstream>
#include <iostream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0; //default value
}

DataFile::~DataFile()
{
	Clear(); //clear the records
}

//void DataFile::AddRecord(string imageFilename, string name, int age)
//{
//	Image i = LoadImage(imageFilename.c_str()); //loads an image to save to the record
//
//	Record* r = new Record; //creates a new record in memory
//	r->image = i; //allocates an image to the record
//	r->name = name; //allocates a name to the record
//	r->age = age; //allocates an age to the record
//
//	//records.push_back(r);
//	recordCount++; //ups the record counter
//}

DataFile::Record* DataFile::GetRecord(int index) //gets the record via an index value -- needs to be changed as it hold all records in memory and crashes when a record cannot be obtained
{
	//temporary vars to hold data about the size of vars
	int nameSize = 0;
	int ageSize = 0;
	int width = 0, height = 0, format = 0, imageSize = 0;
	 
	//open the file and get the correct position to start reading from
	ifstream infile("npc_data.dat", ios::in | ios::binary);
	infile.seekg(currentPos[index], ios::beg);

	//read the height & width of the image
	infile.read((char*)&width, sizeof(int));
	infile.read((char*)&height, sizeof(int));
	
	//calculate size
	imageSize = sizeof(Color) * width * height;

	//read name and age size
	infile.read((char*)&nameSize, sizeof(int));
	infile.read((char*)&ageSize, sizeof(int));

	//create char* for the image data and read it from file
	char* imgdata = new char[imageSize];
	infile.read(imgdata, imageSize);
	
	//create the image
	Image img = LoadImageEx((Color*)imgdata, width, height);

	//create a char* for the name and an int for age
	char* name = new char[nameSize + 1]; //adds an extra byte to the namesize to show the end of the string
	name[nameSize] = '\0'; // \0 = null terminator; denotes the end of a string;
	int age = 0;

	//reads the name and age from the file
	infile.read((char*)name, nameSize);
	infile.read((char*)&age, ageSize);

	//creates a record to send back to main to be displayed
	Record* r = new Record();
	r->image = img;
	r->name = string(name);
	r->age = age;

	//sets pointers to null and deletes them
	imgdata = nullptr;
	name = nullptr;

	delete[] imgdata;
	delete[] name;

	infile.close();

	return r;
}

//void DataFile::Save(string filename)
//{
//	ofstream outfile(filename, ios::out | ios::binary);
//
//	int recordCount = DataFile::recordCount; //sets the record count to the amount of records
//	outfile.write((char*)&recordCount, sizeof(int)); //writes the record count out 
//
//	for (int i = 0; i < recordCount; i++)
//	{		
//		Color* imgdata = GetImageData(); //gets the image data
//				
//		//GET SIZES OF VALUES
//		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
//		int nameSize = records[i]->name.length();
//		int ageSize = sizeof(int);
//
//		//WRITE SIZES INTO DATA FILE
//		outfile.write((char*)&records[i]->image.width, sizeof(int));
//		outfile.write((char*)&records[i]->image.height, sizeof(int));
//		
//		outfile.write((char*)&nameSize, sizeof(int));
//		outfile.write((char*)&ageSize, sizeof(int));
//
//		outfile.write((char*)imgdata, imageSize);
//		outfile.write((char*)records[i]->name.c_str(), nameSize);
//		outfile.write((char*)&records[i]->age, ageSize);
//	}
//	//close the file
//	outfile.close();
//}

void DataFile::Load(string filename, int index)
{
	Clear();

	//open the file
	ifstream infile(filename, ios::in | ios::binary); 

	//resets record count; reads the first int and sets the record count accordingly
	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	//for each record, pushes back the current position within the record
	for (int i = 0; i < recordCount + 1; i++) {
		currentPos.push_back(0);
	}
	//sets the first position in 4 bytes so you aren't reading invalid data
	currentPos[0] = sizeof(int);

	//main loop; rund through the record to set the size of each index and set their locations
	for (int j = 1; j < recordCount + 1; j++) {
		//Temporary variables
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		//reading variables
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		//creates a var to hold the size of each record chunk, and gets the current location of each record
		int recordSize = imageSize + nameSize + ageSize;
		int location = infile.tellg();

		//sets the location by bumping it up from current position + the record chunk size
		infile.seekg(recordSize, infile.cur);
		currentPos[j] = location + recordSize;
	}
	//closes the file
	infile.close();
}

void DataFile::Clear()
{
	//resets the record count
	recordCount = 0;
}
