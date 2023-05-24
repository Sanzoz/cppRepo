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
	Clear(); //clears the records
}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str()); //loads an image to save to the record

	Record* r = new Record; //creates a new record in memory
	r->image = i; //allocates an image to the record
	r->name = name; //allocates a name to the record
	r->age = age; //allocates an age to the record

	//records.push_back(r);
	recordCount++; //ups the record counter
}

DataFile::Record* DataFile::GetRecord(int index) //gets the record via an index value -- needs to be changed as it hold all records in memory and crashes when a record cannot be obtained
{
	int filesize = 0, recordSize = 0, stringSize = 0;

	ifstream f("npc_data.dat", ios::in | ios::binary);
	Record* temp = new Record();

	f.seekg(0, ios::end);
	filesize = f.tellg();
	f.seekg(0, ios::beg);
	recordCount = f.get();
	f.seekg(sizeof(Record), ios::beg);
	recordSize = f.tellg();
	f.seekg(sizeof(string), ios::beg);
	stringSize = f.tellg();

	cout << "Binary File Size: " << filesize << "\n";
	cout << "Record Size: " << recordSize << "\n";
	cout << "Record Count: " << recordCount << "\n";
	cout << "String Size: " << stringSize << "\n";

	return temp;
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
	Clear(); //clears the records vector

	ifstream infile(filename, ios::in | ios::binary);

	recordCount = 0; //resets recordcount
	infile.read((char*)&recordCount, sizeof(int));

	//READ DATA
	for (int i = 0; i < recordCount; i++)
	{
		//CREATE TEMP VARS
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		//READ VALUES AND SET THEM
		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		char* imgdata = new char[imageSize];
		infile.read(imgdata, imageSize);

		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize];
		int age = 0;

		infile.read((char*)name, nameSize); //this is the cause of the name displaying incorrectly
		infile.read((char*)&age, ageSize);

		//CREATE RECORD 
		Record* r = new Record();
		r->image = img;
		r->name = string(name);
		//cheaty solution -- deletes the extra characters until the size is equal to the defined value, works while I try find the intended solution
		while (r->name.size() != nameSize) r->name.pop_back();
		r->age = age;
		//records.push_back(r);

		//cout << "NAME: " << r->name << "\n" << "AGE: " << r->age << "\n";
		//cout << "NAME SIZE: " << nameSize << "\n" << "AGE SIZE: " << ageSize << "\n\n";

		delete [] imgdata;
		delete [] name;
	}

	infile.close();
}

void DataFile::Clear()
{
	/*
	for (int i = 0; i < records.size(); i++)
	{
		delete records[i];
	}
	records.clear();
	recordCount = 0;
	*/
}