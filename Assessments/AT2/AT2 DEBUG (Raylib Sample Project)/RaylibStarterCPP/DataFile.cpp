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
//
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
	int filesize = 0;
	int width = 0, height = 0;
	int imageSize = 0, nameSize = 0, ageSize = 0;
	int seekPos = 0;

	ifstream f("npc_data.dat", ios::in | ios::binary);
	Record* temp = new Record();

	f.seekg(0, f.end);
	filesize = (int)f.tellg();
	f.seekg(0, f.beg);

	vector<char> buffer(filesize);
	f.read(&buffer[0], filesize);

	f.seekg(4, f.beg);
	f.seekg(index * 262167, f.cur); //img 1 = 4; img 2 = 262171; img 3 = 524340; img 4 = 786515; img 5 = 1048693
	
	seekPos = (int)f.tellg();
	
	f.read((char*)&width, sizeof(int));
	f.read((char*)&height, sizeof(int));

	imageSize = sizeof(Color) * width * height;
	
	f.read((char*)&nameSize, sizeof(int));
	f.read((char*)&ageSize, sizeof(int));

	char* imgDat = new char[imageSize + 1];
	imgDat[imageSize] = '\0';
	f.read((char*)imgDat, imageSize);
	
	Image image = LoadImageEx((Color*)imgDat, width, height);

	char* name = new char[nameSize + 1];
	name[nameSize] = '\0'; // \0 denotes a null terminator, which marks the end of a string.
	int age = 0;

	f.read((char*)name, nameSize);
	f.read((char*)&age, ageSize);
	
	temp->image = image;
	temp->name = string(name);
	temp->age = age;

	cout << "\nFile Size in Bytes: " << filesize << "\n";
	cout << "\nIndex: " << index << "\n";
	cout << "\nSeek Position: " << seekPos << "\n";

	imgDat = nullptr;
	name = nullptr;

	delete[] imgDat;
	delete[] name;

	f.close();
	
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
	//Clear(); //clears the records vector

	ifstream infile(filename, ios::in | ios::binary);

	recordCount = 0; //resets recordcount
	infile.read((char*)&recordCount, sizeof(int));

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
		char* name = new char[nameSize + 1]; //
		name[nameSize] = '\0'; // \0 denotes a null terminator, which marks the end of a string.
		int age = 0;

		infile.read((char*)name, nameSize);
		infile.read((char*)&age, ageSize);

		//CREATE RECORD 
		Record* r = new Record();
		r->image = img;
		r->name = string(name);
		r->age = age;
		//records.push_back(r);

		//cout << "NAME: " << r->name << "\n" << "AGE: " << r->age << "\n";
		//cout << "NAME SIZE: " << nameSize << "\n" << "AGE SIZE: " << ageSize << "\n\n";

		delete [] imgdata;
		delete [] name;

	infile.close();
}


void DataFile::Clear()
{
	//for (int i = 0; i < records.size(); i++)
	//{
	//	delete records[i];
	//}
	//records.clear();
	recordCount = 0;
}
