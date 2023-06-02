
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };

	/*
	TODO: Print each value of the array in order
	Expected:
		10, 20, 30, 40, 50,
	*/
	for (int i = 0; i < NUM_NUMBERS; i++) { //for loop
		cout << "" << numbers[i] << ", "; //loops through and prints each indices' value
	}
	cout << endl; //ends the line
	// ------------------------------------------------------------------------
	/*
	TODO: Print each value of the array in reverse order
	Expected:
		50, 40, 30, 20, 10,
	*/
	// Task 2: Write your Code here
	// ------------------------------------------------------------------------
	for (int i = NUM_NUMBERS - 1; i > -1; i--) { 
		cout << "" << numbers[i] << ", "; //loops through indices and prints them
	}
	// ------------------------------------------------------------------------

	return 0;
}