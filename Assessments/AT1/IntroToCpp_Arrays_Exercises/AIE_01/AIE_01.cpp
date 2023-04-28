
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	//int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };
	int numbers[NUM_NUMBERS] = { 20, 10, 40, 50, 30 }; //same lineup but shifted for testing purposes

	bool ascending = false;
	bool descending = false;
	/*
	TODO: Print each value of the array in order
	Expected:
		10, 20, 30, 40, 50,
	*/
	// Task1: Write your Code here
	// ------------------------------------------------------------------------
	while (!ascending) {

		ascending = true; //if sorted, this stays true and breaks the loop

		for (int i = 0; i < NUM_NUMBERS - 1; i++) { //for loop

			if (numbers[i] > numbers[i + 1]) {
				int temp = numbers[i]; //temp int holds number for swapping
				numbers[i] = numbers[i + 1]; //swaps indices
				numbers[i + 1] = temp; 
				ascending = false; //resets the loop
			}
		}
	}
	cout << "BUBBLESORT ASCENDING" << endl;

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
	while (!descending) {

		descending = true; //breaks loop if sorted

		for (int i = 0; i < NUM_NUMBERS; i++) {

			if (numbers[i] < numbers[i + 1]) {
				int temp = numbers[i]; //temp int to hold number for swapping
				numbers[i] = numbers[i + 1]; //swaps indices
				numbers[i + 1] = temp;
				descending = false; //resets loop
			}
		}
	}
	cout << "BUBBLESORT DESCENDING" << endl;

	for (int i = 0; i < NUM_NUMBERS; i++) { 
		cout << "" << numbers[i] << ", "; //loops through indices and prints them
	}
	// ------------------------------------------------------------------------

	return 0;
}