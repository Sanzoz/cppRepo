#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

    int AR[] = { 88, 22, 44}; // data
    
    fstream file_stream;    
    
    file_stream.open("data_01.dat", ios::out | ios::binary ); // open stream handler
    if (file_stream) {
        file_stream.write(reinterpret_cast<char*>(AR), sizeof(AR)); // write file
        file_stream.close();
    }else {
        cout << " -- error writing file -- " << endl;
    }

    int AR_reading[3]; // make temp array
    file_stream.open("data_01.dat", ios::in | ios::binary ); // open stream handler
    if (file_stream) {
        file_stream.read(reinterpret_cast<char*>(AR_reading), sizeof(AR_reading)); // read data
        file_stream.close();
        for (int i : AR_reading) {
            cout << "  --> " << i << endl;
        }

    }else {
        cout << " -- error reading file -- " << endl;
    }


    cout << " -- end of code -- " << endl;
}

// https://www.youtube.com/watch?v=fCvJ9Rsfy6c
// https://www.youtube.com/watch?v=Tew2tPznESY
// https://www.geeksforgeeks.org/set-position-with-seekg-in-cpp-language-file-handling/
// https://www.geeksforgeeks.org/ostreamseekppos-method-in-c-with-exmaples/
// https://www.geeksforgeeks.org/cpp-program-to-modify-the-content-of-a-binary-file/