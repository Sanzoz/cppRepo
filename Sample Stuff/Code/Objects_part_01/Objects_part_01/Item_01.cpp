#include "Item_01.h"
// :: scope resolution operator
Item_01::Item_01() { // no return type 
    cout << "Item_01>> --Default contructor---\n";
    // code

}

Item_01::Item_01(float value) { // overloaded 
    cout << "Item_01>>  ++overloaded contructor++++\n";
    MAXspeed = value;
    // code

}

Item_01::Item_01(string n, float value) { // overloaded 
    cout << "Item_01>>  ++overloaded contructor++++\n";
    Name = n;
    MAXspeed = value;
    // code

}



void Item_01::Move(float value) {
    speed += value;
    if (speed > MAXspeed) {
        speed = MAXspeed;
    }
}

void Item_01::Stop() {
    speed = 0;
    // this->speed = 0; // same result
}

float Item_01::GetSpeed() {
    return speed;
}


/// destructor
Item_01::~Item_01() {  // ~ tilde - no return value - no argument
    delete inputReciver; // <-- clean heap memory
    inputReciver = nullptr;// <-- clean heap memory
    cout << "Item_01>> -- destructor execution complete---\n";
}

// /////////////////////////////////

string Item_01::dbug() {
    //cout << "Name: "<< Name << "  Health: "<< Health << "  Damage: "<< Damage << endl;
    return  "\n \n Item_01 >>> ID: " + to_string(id) +
            "  \n Name: " + Name +
            "  \n Health: " + to_string(Health) +
            "\n \n ";
}
