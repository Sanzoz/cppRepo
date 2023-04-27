
#include <iostream>

int MinValue(const int* arr, int count);
int MaxValue(const int* arr, int count);
int CountOccurrencesOfValue(const int* arr, int count, int search);


int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 10;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 };

	// In C++, an array is simply a pointer to the first value
	// when passing an array through a function parameter, we loose the length information
	// therefore we need to pass the array size in as well

	// implement the above methods
	// so that the expected output is printed to the console

	std::cout << "Expected: 10 - Got: " << MinValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 50 - Got: " << MaxValue(numbers, NUM_NUMBERS) << std::endl;
	std::cout << "Expected: 2 - Got: " << CountOccurrencesOfValue(numbers, NUM_NUMBERS, 10) << std::endl;
	std::cout << "Expected: 0 - Got: " << CountOccurrencesOfValue(numbers, NUM_NUMBERS, 8) << std::endl;

	return 0;
}


int MinValue(const int* arr, int count)
{
	int num = arr[4]; //sets to the highest value in the array for testing

	for (int i = 0; i < count; i++) { //loops through to find the lowest value, and sets 'num' to that
		if (num > arr[i]) {
			num = arr[i];
		}
	}

	return num;
}

int MaxValue(const int* arr, int count)
{
	int num = arr[0]; //set to the lowest value in the array for testing

	for (int i = 0; i < count; i++) { //loops through to find the highest value, and sets 'num' to it
		if (num < arr[i]) {
			num = arr[i];
		}
	}

	return num;
}

int CountOccurrencesOfValue(const int* arr, int count, int search)
{ 
	int num = 0;

	for (int i = 0; i < count; i++) { //loops through to find if 'search' is in any of the array indices, and counts how many
		if (search == arr[i]) {
			num++;
		}
	}

	return num;
}

