#include <iostream>
#include <string>
using namespace std;

class Unit {
public:
    Unit(){}
    ~Unit(){}

    virtual void isReady(){}
};

class Hunter : public Unit {
public:
    Hunter() {}
    ~Hunter() {}
};

class Charger : public Unit {
public:
    Charger() {}
    ~Charger() {}
};



int main(){
    // implicit casting --> you tell C++ compiler what to do
    // explicit casting --> the C++ compiler will do the cast by its own

    // implicit casting
    float Distance_def = 125.25;
    int Distance_00 = (int)Distance_def; // C style casting

    cout << " ----- A: " << Distance_def << endl;
    cout << " ----- A: " << Distance_00 << endl;

    int Distance = static_cast<int>(Distance_def); // C++ style casting
    cout << " ----- B: " << Distance_00 << endl;

    // https://www.youtube.com/watch?v=pWZS1MtxI-A - casting

    cout << "\n\n\n"; /////////////////////////////////////////////////////

    Hunter* H1 = new Hunter();
    Unit* unit_A = H1; // <-- no problem
    
    
    Unit* unit_B = new Hunter(); 
    Unit* unit_C = new Charger();
    
    Hunter* H2 = dynamic_cast<Hunter*>(unit_B); // dynamic_cast only works with polymorphic class
    Hunter* H3 = dynamic_cast<Hunter*>(unit_C); 

    if (H2) cout << " dynamic_cast<Hunter*>(unit_B)  is succesful " << endl;
    else    cout << " dynamic_cast<Hunter*>(unit_B)  NOT possible " << endl;

    if (H3) cout << "   dynamic_cast<Hunter*>(unit_C)  is succesful " << endl;
    else    cout << "   dynamic_cast<Hunter*>(unit_C)  NOT possible " << endl;

    // https://www.youtube.com/watch?v=2h2hdRqRIRk - dynamic cast
    // https://learn.microsoft.com/en-us/cpp/cpp/dynamic-cast-operator?view=msvc-170
    // https://www.bogotobogo.com/cplusplus/dynamic_cast.php



    cout << "\n\n\n"; /////////////////////////////////////////////////////
    // const_cast is used to cast away constness from variable

    int U = 777;
    const int* Y = &U;
    cout << " ---- " << Y << " ---- " << &U << " ---- " << U << " ---- " << *Y<< endl;

    //int* U2 = Y; // <-- problem -- can not initialise value
    int* U2 = const_cast<int*>(Y); // <-- ok 
    cout << " --|-- " << Y << " --|-- " << U2 << " --|-- " << *U2 << " --|-- " << *Y << endl;


    cout << "\n\n\n"; /////////////////////////////////////////////////////

    // reinterpret_cast converts any pointer to any other pointer, even if unrelated
    // https://www.ascii-code.com/
    int secretKey_01 = 76;  // L
    int secretKey_02 = 69;  // E
    int secretKey_03 = 102; // f
    int secretKey_04 = 84;  // T

    int* unLock = &secretKey_01; // copy the address to pointer
    cout << " .. a secret character : " << reinterpret_cast<char*>(unLock) << endl;
    
    
    string unLockMessage =  std::string(reinterpret_cast<char*>(&secretKey_01)) +
                            std::string(reinterpret_cast<char*>(&secretKey_02)) +
                            std::string(reinterpret_cast<char*>(&secretKey_03)) +
                            std::string(reinterpret_cast<char*>(&secretKey_04));
    cout << " The secret direction : " << unLockMessage << endl;

    // https://www.youtube.com/watch?v=jQR2doi51Bo
    // https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast


    cout << " -- end of code -- " << endl;
}

// https://www.youtube.com/watch?v=CiHfz6pTolQ - casts


// project> properties> c++> language
// In C++, RTTI (Run-time type information) is a mechanism 
// that exposes information about an object’s data type at runtime 
// and is available only for the classes which have at least one virtual function. 
// It allows the type of an object to be determined during program execution.
// https://www.geeksforgeeks.org/rtti-run-time-type-information-in-cpp/
// 



