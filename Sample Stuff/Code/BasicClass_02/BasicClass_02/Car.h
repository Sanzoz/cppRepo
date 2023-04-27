#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car{ // <-- always capital letter at the begining for class name
    public:
        // cons/dest
        Car();
        Car(int val);
        Car(string st, int val);
        ~Car();
    
        // property list
        int id = 0;
        string name = "";
        string model = "";
        int speed = 0;
        int capacity_person = 0;
        int capacity_total = 0;
    private:
        int Security_Code = 0;
        bool Security_Code_Validated = false;


    public:
        // method   
        void Drive(string destination);
        void Stop();
        int GetSpeed();
        void TurnOn(int code);
        bool ValidateDriver(int code);
    private:
            void Move(string dest);

};

// https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
// https://www.codementor.io/@supernerdd7/constructor-and-destructor-in-c-1r8kkogm6j


