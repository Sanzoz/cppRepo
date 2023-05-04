#include <iostream>
#include "item_01.h"
#include <string>
#include <vector>
using namespace std;
/*
int main(){

    cout << "-1--- stack memory in use -\n";

    Item_01 object_01;
    Item_01 object_02(12.f);
    Item_01 object_03 = Item_01(12.f);

    cout << "-2--- heap memory in use -\n";

    Item_01* objectPointer_01 = new Item_01;
    // Item_01* object_02(12.f); //not working -> error message: a value of type ~~~ cannot be used to initialize an entity of type ~~~~  OR '~~objectA~~': '~~~~ *' differs in levels of indirection from '~~objectA~~'
    Item_01* objectPointer_02 = new Item_01(12.f); // <-- ok 

    cout << "-3--- array of objects -\n";
    Item_01 arrayOfObjects_01[3];
    Item_01* arrayOfObjects_02 = new Item_01[3];

    cout << "\n --------- end of code ------------ " << endl;
}
*/


//  ---function pointer basics 
void Talk() {
    cout << "  )) ++ talking code ++ (( " << endl;
}

bool isReady() {
    //code
    return false;
}

int makeReady(bool b, int i) {
    // code 
    return (i += 5);
}

// ---function pointer usage

bool isHuman(string s) {
    if (s == "Human") return true;
    else return false;
}

bool isOrc(string s) {
    if (s == "Orc") return true;
    else return false;
}

bool isElf(string s) {
    return (s == "Elf") ? true : false; // <-- Short Hand If/else (Ternary Operator)
}
// https://www.w3schools.com/cpp/cpp_conditions_shorthand.asp


void CheckHuman(vector<string> u) {
    bool temp = false;
    for (int i = 0; i < u.size(); i++) {
        if (isHuman(u[i])) {
            cout << " ++ Human found at index " << i << endl;
            temp = true;
        }
    }
    if (temp == false) cout << " ++ Human not found " << endl;
}

void CheckOrc(vector<string> u) {
    bool temp = false;
    for (int i = 0; i < u.size(); i++) {
        if (isOrc(u[i])) {
            cout << " ++ Orc found at index " << i << endl;
            temp = true;
        }
    }
    if (temp == false) cout << " ++ Orc not found " << endl;
}

void CheckElf(vector<string> u) {
    bool temp = false;
    for (int i = 0; i < u.size(); i++) {
        if (isElf(u[i])) {
            cout << " ++ Elf found at index " << i << endl;
            temp = true;
        }
    }
    if (temp == false) cout << " ++ Elf not found " << endl;
}


void CheckUnit(vector<string> u, bool (*funcPTR)(string), string unitName);

int main() {
    cout << "-4--- Function Pointers -\n";
    
    cout << "        |||||||||||||||  void ............... " << endl;
    void (*funcPTR_00)() = Talk;// implemenet void function pointer variable on the left, and assign it to a function on the right. void (*[variable name])([inputs]) = the real function`s name
    cout << "--- only title  : " << Talk << endl;
    cout << "--- actual function : ";
    Talk();
    cout << "--- function pointer: ";
    funcPTR_00();

    //cout << "\n        |||||||||||||||  with return value ............  " << endl;

    //bool(*funcPTR_01)() = isReady; // implemenet a return (bool) function pointer variable on the left, and assign it to a function on the right. [return type] (*[variable name])([inputs]) = the real function`s name
    //cout << "--- only title  : " << isReady << endl;
    //cout << "--- actual function : " << isReady() << endl;
    //cout << "--- function pointer: " << funcPTR_01() << endl;

    //cout << "\n        |||||||||||||||  with return value and input ..  " << endl;
    //int(*funcPTR_02)(bool, int) = makeReady;
    //cout << "--- function title  : " << makeReady << endl;
    //cout << "--- function itself : " << makeReady(true, 5) << endl;
    //cout << "--- function pointer: " << funcPTR_02(true, 5) << endl;

    // ////////////////////////////////////
    cout << "\n\n .... call functions: normal...... " << endl;
    vector<string> units_01 = { "Orc", "Human", "Human", "Orc", "Orc" };
    CheckHuman(units_01);
    CheckOrc(units_01);
    CheckElf(units_01);


    cout << "\n ...... call functions: pointer..... " << endl;
    vector<string> units_02 = { "Orc", "Human", "Human", "Orc", "Orc" };
    bool (*funcPTR_03)(string);
    
    // assign pointer variable to different functions of "same" signature
    funcPTR_03 = isHuman;
    CheckUnit(units_02, funcPTR_03, "Human");
    funcPTR_03 = isOrc;
    CheckUnit(units_02, funcPTR_03, "Orc");
    funcPTR_03 = isElf;
    CheckUnit(units_02, funcPTR_03, "Elf");
}
// c++ vectors
// https://cplusplus.com/reference/vector/vector/
// https://www.geeksforgeeks.org/vector-in-cpp-stl/

// ---------------------------- 
void CheckUnit(vector<string> u, bool (*funcPTR)(string), string unitName) {
    bool temp = false;
    for (int i = 0; i < u.size(); i++) {
        if (funcPTR(u[i])) {
            cout << "   --xx " << unitName << " found at index " << i << endl;
            temp = true;
        }
    }
    if (temp == false) cout << "   --xx " << unitName << " not found " << endl;
}


// function pointer
// https://www.geeksforgeeks.org/function-pointer-in-cpp/
// https://www.cprogramming.com/tutorial/function-pointers.html
// https://www.youtube.com/watch?v=Laiv_E2q_nQ
// https://www.youtube.com/watch?v=p4sDgQ-jao4
// https://learn.microsoft.com/en-us/cpp/cpp/functions-cpp?view=msvc-170