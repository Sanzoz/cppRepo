

#include <iostream>


void SortArray(int* arr, int count);
bool IsArraySorted(const int* arr, int count);

int main(int argc, char** argv)
{
	const int NUM_ITEMS = 8;
	int numbers[NUM_ITEMS] = { 13, 1, 7, 5, 11, 9, 15, 3 };

	SortArray(numbers, NUM_ITEMS);

	// Test: all values should be sorted in ascending order
	if (IsArraySorted(numbers, NUM_ITEMS)) std::cout << "Pass: the array is sorted" << std::endl;
	else std::cout << "Fail: the array is not sorted" << std::endl;

	return 0;
}

bool IsArraySorted(const int* arr, int count)
{	
	for (int i = 0; i < count - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}


void SortArray(int* arr, int count)
{
	// TODO: 
	// modify the values in the array so that when this method returns
	// all values are sorted in ascending order
	
	bool ascending = false;

	while (!ascending) {

		ascending = true; //if sorted, this stays true and breaks the loop

		for (int i = 0; i < count - 1; i++) { //for loop

			if (arr[i] > arr[i + 1]) {
				int temp = arr[i]; //temp int holds number for swapping
				arr[i] = arr[i + 1]; //swaps indices
				arr[i + 1] = temp;
				ascending = false; //resets the loop
			}
		}
	}
}
