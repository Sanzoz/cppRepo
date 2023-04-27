#pragma once // using to avoid adding (#include) header files number of time

#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>
using namespace std;

struct Magazine { // <-- can be implemented in main() as well 
    int id;
    string name;
    string date;
    string language;
    float price;
    string currency;
    string getData() {
        return to_string(id) + " " + name + " ";
    }
};


class Library{   
    public:
        //cons/dest
        Library(); 
        ~Library(); 
        Library(string title, string author, int id);  // overloaded const for one book
        
        // properties
        vector<string> Book_title;
        vector<string> Book_Author;
        vector<int> Book_ID;
        vector<Magazine> Mag;

        // methods
        // ++++++++++++++ book
        // updating a book by index
        void setBookbyIndex(string title, string author, int id);  // <-- populate vector container with data  
        string GetBookDatabyIndex(int index, int dataType); // return data by selection
        string GetBookFullDatabyIndex(int id); // return full details
    
        // ++++++++++++++ magazine
        // updating a magazine by index
        void setMagbyIndex(int index, int id, string name, string date, string language, float price, string currency);
        string GetMagFullDatabyIndex(int index); // return full details
};

