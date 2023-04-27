#include <iostream>
#include <string>
using namespace std;

#include "Library.h" // <-- include header file

int main() {
    string UserInput = "";
    int TurnCounter = 0;
    //vector<Magazine> Mag02; // <-- working

    //Library* Capital = new Library();
    Library* UTC = new Library("Professional C++", "Marc Gregoire", 56248);
    UTC->setBookbyIndex("C++ Programming: An Object-Oriented Approach", "Behrouz A. Forouzan and Richard Gilberg", 77410);


    while (UserInput != "q") {
        cout << "  ++ option:  " << endl;
        cin >> UserInput;

        if (UserInput == "1") {
            TurnCounter++;
            cout << " Current turn is: " << TurnCounter << endl;
            //cout <<(UTC->GetBookLongDatabyIndex(0));
            cout <<(UTC->GetBookDatabyIndex(56248, 1)) << endl;
            cout <<(UTC->GetBookDatabyIndex(56248, 2)) << endl;
            cout <<(UTC->GetBookDatabyIndex(56248, 3)) << endl;
            cout <<(UTC->GetBookDatabyIndex(77410, 1)) << endl;
            cout << "\n\n";
            cout <<(UTC->GetBookFullDatabyIndex(77410));

        }
    }
}