#include <iostream>
#include <string>
using namespace std;

#include <vector>
#include <unordered_map>

int main(){
	
	// A //////////////////////////////
	//cout << " ---------- array ----------- " << endl;
	//
	//int CPPArray[6]; // <-- data type array_name[size]
	//
	//float floatArray_A[2] = { 2, 7 }; // <-- inline 
	//cout << " floatArray_A: " << floatArray_A[0] << " - ";
	////cout << " floatArray_A: " <<  floatArray_A[0] << '  '; // <-- error, strange output with '
	//
	//float floatArray_B[2] = { {3.14} , {1.089} };
	//cout << " floatArray_B:  " << floatArray_A[0] << endl;

	//cout << "\n ========================================= \n";

	//float floatArray_C[] = { 2.0, 7, 3, 0.2 };
	//cout << " floatArray_C: " << sizeof(floatArray_C) << "\n"; // 16 -> float is 4 byte
	//float floatArray_D[] = { 2.0, 7, 3, 0.2, 0.1 };
	//cout << " floatArray_D: " << sizeof(floatArray_D) << "\n"; // 20 -> float is 4 byte
	//
	//cout << "\n ========================================= \n";

	//int HighScore[6]; // sizeof(floatArray_D) = 24 -> int is 4 byte
	//HighScore[0] = 40;
	//HighScore[1] = 82;
	//HighScore[2] = 120;
	//HighScore[3] = 888;
	//HighScore[4] = -12;
	//HighScore[5] = 0;

	//for (int i = 0; i < sizeof(HighScore); i++) { // <-- issue
	//	cout << HighScore[i] << " | ";
	//}

	//cout << "\n ========================================= \n";

	//size_t arraySize = sizeof(HighScore) / sizeof(HighScore[0]);
	////for (int i = 0; i < 6; i++) { // <-- use fix number
	//for (size_t i = 0; i < arraySize; i++) { // <-- works fine
	//	cout << HighScore[i] << " | ";
	//}
	////// https://en.cppreference.com/w/cpp/types/size_t

	//int main_Array_01[12] = {}; // empty array
	//int main_Array_02[12]{}; // empty array

	//cout << "\n ========================================= \n";

	////// 2d array // save in memory as "contiguous" address
	//int table_A[3][2] = {
	//	{ 4, 8 },
	//	{ 0, -1 },
	//	{ 12, 24}
	//};
	//cout << " \n++++     table_B[2][1]  [row][col]:  " << table_A[2][1] << endl;

	//int City_Hospital_Data[5][4][52][3];	// nd array building, section, room, bed
	//int Patient_Bed[5][4][52][3];			// nd array building, section, room, bed


	//// copy array
	//int highScore[10] = { 20, 70, 0, 71, 12, 07, 4, 47 };
	//int newScore[10] = { 1, 1, 1, 1, 1, 1, 1, 1 };
	//
	//int a = 12;
	//int b = 125;
	//
	//b = a; // copy is ok
	//a = b; // copy is ok
	////highScore = newScore; // <-- copy is not allowed

	//size_t arraySize1 = sizeof(highScore) / sizeof(highScore[0]);
	//for (size_t i = 0; i < arraySize1; i++) {
	//	highScore[i] = newScore[i]; // copy array values with same size
	//}

	// B //////////////////////////////
	//cout << " ---------- other data containers ----------- " << endl;

	//pair<string, int> pairExample;
	//pairExample.first = " Alexandra ";
	//pairExample.second = 428511;
	//cout << " pair - example: " << pairExample.first << " : " << pairExample.second << endl;

	//// list https://www.guru99.com/cpp-list.html
	//// Pair is used to combine together two values of same or different data types.
	//// https://www.cplusplus.com/reference/utility/pair/pair/
	//// https://www.geeksforgeeks.org/pair-in-cpp-stl/
	//// https://marknelson.us/posts/2011/09/03/hash-functions-for-c-unordered-containers.html


	//cout << "\n ========================================= \n";

	//vector<int> PlayerAmmo = { 60, 34, 600, 12, 8, 1, 1, 2 }; // <-- no size is needed in vector
	//cout << "\n --------------------- I " << endl;		
	//// common way of looping
	//for (int i = 0; i < PlayerAmmo.size(); i++) // vector has methods to use like .size()
	//	cout << " iterator - example - A: " << PlayerAmmo[i] << endl;

	//cout << "\n --------------------- II" << endl;
	//// range based for loop
	//for (int Ammo : PlayerAmmo) {
	//	cout << " iterator - example - B: " << Ammo << endl;
	//}

	//cout << "\n --------------------- III " << endl;
	//// use iterator and "de-refrence" it to get values
	//for (vector<int>::iterator itr = PlayerAmmo.begin(); itr != PlayerAmmo.end(); itr++)
	//	cout << " iterator - example - C: " << *itr << endl;


	//cout << "\n ========================================= \n";
	//// use iterator with unordered map and use "first" and "second" elements
	//unordered_map<string, float> PlayerMagicAmmo;
	//PlayerMagicAmmo["Healing"] = 43.2f;
	//PlayerMagicAmmo["Blue Spell"] = 2074.45f;
	//PlayerMagicAmmo["Green Spell"] = 10.00f;

	//for (
	//	unordered_map<string, float>::const_iterator itr = PlayerMagicAmmo.begin();
	//	itr != PlayerMagicAmmo.end();
	//	itr++
	//	) {

	//	auto& key = itr->first;
	//	auto& value = itr->second;

	//	cout << " iterator - example - D: " << key << " : " << value << endl;
	//}
	//// simplified version
	//for (auto itr : PlayerMagicAmmo) {
	//	auto& key = itr.first;
	//	auto& value = itr.second;
	//	cout << " iterator - example - E: " << key << " : " << value << endl;

	//}

	//// more simplified !  --- only in C++ 17
	////for (auto[key , value] : PlayerMagicAmmo) {
	////  cout << " iterator - example - F: " << key << " : " << value << endl
	////}

	//// https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/


	cout << "\n --------- end of code ------------ " << endl;
}

