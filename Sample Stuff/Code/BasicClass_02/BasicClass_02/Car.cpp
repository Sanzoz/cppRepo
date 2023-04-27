#include "Car.h"

Car::Car(){ // constructor
    cout << "C|  ++ Car constructor  " << endl;
}  

Car::Car(int val) {
    cout << "C|  ++ Car constructor - overload for id" << endl;
    id = val;
}
Car::Car(string st, int val) {
    cout << "C|  ++ Car constructor - overload for name and id" << endl;
    name = st;
    id = val;
}

Car::~Car() { // destructor
    cout << "C|  ++ Car destructor " << id << endl;
} 


void Car::Drive(string destination){ // <-- name of class  + :: name of method
    cout << "C| destination: " << destination << endl;
    if (Security_Code_Validated) Move(destination);
    else cout << "C| ]] invalid code - please contact management --  " << endl;
}

void Car::Stop(){    speed = 0;    }
int Car::GetSpeed(){ return speed; }

void Car::Move(string dest){
    cout << "C| .... ## " << name << " " << model << " is moving to " << dest << endl;
    // animation & sound code
}

 // -- B
void Car::TurnOn(int code){
    if (Security_Code == 0) Security_Code = code * 10; // generate security number by using code
    else cout << "C| Security code already set.  \n";
}

bool Car::ValidateDriver(int code) {
    if (Security_Code == code) Security_Code_Validated = true;
    else Security_Code_Validated = false;
    return Security_Code_Validated;
}
