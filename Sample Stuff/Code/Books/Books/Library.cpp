#include "Library.h"

// constructor
Library::Library() { } 
Library::~Library() { } 
Library::Library(string title, string author, int id) { // overloaded const for one book
    Book_title.insert(Book_title.end(), title);
    Book_Author.insert(Book_Author.end(), author);
    Book_ID.insert(Book_ID.end(), id);
}

// methods
// ++++++++++++++ book
// updating a book by index
void Library::setBookbyIndex(string title, string author, int id) { // <-- populate data with arrays
    Book_title.insert(Book_title.end(), title);
    Book_Author.insert(Book_Author.end(), author);
    Book_ID.insert(Book_ID.end(), id);  
}
// return data by selection
string Library::GetBookDatabyIndex(int id, int dataType) {
    string result = "";
    int counter = 0;
    int index = -1;
    for( int bookID : Book_ID) { // for any int bookID inside vector Book_ID
        if (bookID == id) {
            index = counter;
            break;
        }
        counter++;
    }
    //cout << " ---- " << to_string(index) << endl;
    switch (dataType) {
        case 1:
            result = " Book Title by ID: " + Book_title[index];
            break;                    
        case 2:                       
            result = " Book Author by ID: " + Book_Author[index];
            break;
        case 3:
            result = " Book ID: " + to_string(Book_ID[index]);
            break;
    }
    return result;
}
// return full details
string Library::GetBookFullDatabyIndex(int id) {
    int counter = 0;
    int index = -1;
    for (int bookID : Book_ID) { // for any int bookID inside vector Book_ID
        if (bookID == id) {
            index = counter;
            break;
        }
        counter++;
    }
    string result = (" Book details by ID: " + Book_title[index] + " . " + Book_Author[index] + " -[ " + to_string(Book_ID[index]) + "\n\n");
    return result;
}
// ++++++++++++++ magazine
// populate data with struct
void Library::setMagbyIndex(int index, int id, string name, string date, string language, float price, string currency) {
    Mag[index].id = id;
    Mag[index].name = name;
    Mag[index].date = date;
    Mag[index].language = language;
    Mag[index].price = price;
    Mag[index].currency = currency;
}
// return full details
string Library::GetMagFullDatabyIndex(int index) { 
    string result = "This item is not exist. Try different index.";
    if (index < Mag.size()) { // to check existance of index, use size 
        result = Mag[index].getData();
    }
    return result;
    // https://stackoverflow.com/questions/7395161/what-is-the-fastest-way-to-check-if-stdvector-index-is-not-out-of-bounds
}
