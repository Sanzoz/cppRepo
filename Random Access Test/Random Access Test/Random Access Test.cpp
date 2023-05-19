#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Record {
	string name = "";
	int age = 0;
};

int main()
{
	string input = "";
	int inputNum;

	Record records[]{ {"James", 17}, {"Thomas", 22}, {"Gabby", 20}, {"Betty", 29}, {"Ram", 24} };

	fstream f("records.dat", ios::out | ios::in | ios::binary);

	f.write(reinterpret_cast<char*>(records), 5 * sizeof(Record));
	f.close();

	f.open("records.dat", ios::in | ios::out | ios::binary);

	cin >> input;
	inputNum = stoi(input);

	if (inputNum == 0 || inputNum == 1 || inputNum == 2 || inputNum == 3 || inputNum == 4) {
		f.seekg(inputNum * sizeof(Record), ios::beg);
		Record temp;
		f.read(reinterpret_cast<char*>(&temp), sizeof(Record));

		cout << temp.name << ", " << temp.age << "\n\n";
	}
	else if (inputNum == 5) {
		for (int i = 0; i < size(records); i++) {
			f.seekg(i * sizeof(Record), ios::beg);
			Record temp;
			f.read(reinterpret_cast<char*>(&temp), sizeof(Record));

			cout << temp.name << ", " << temp.age << "\n\n";
		}
	}
	f.close();

	cin.ignore();
	cin.get();

	return 0;
}
