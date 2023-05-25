#include <iostream>
#include <string>
using namespace std;

class Root {
public:
    Root(){}
    ~Root(){}
    int value_Root = 12;
    void getName() { cout << " getName --- ROOT " << endl;  };
};

//class TypeA : virtual public Root { // solution 
class TypeA : public Root {
public:
    TypeA() { value_Root = 44; }
    ~TypeA() {}

};

//class TypeB : virtual public Root { // solution 
class TypeB : public Root {
public:
    TypeB() { value_Root = -44; }
    ~TypeB() {}
};


//class SpecialType : public TypeB, public TypeA { // be careful !
class SpecialType : public TypeA, public TypeB {
public:
    SpecialType() { 
        //value_Root = value_Root * 10; // <--- problem
        // getName();// <--- problem
    }
    ~SpecialType() {}
};


int main(){

    SpecialType* ST = new SpecialType();
    //cout << " -- value_Root -- " << ST->value_Root << endl;// <-- problem
    
    cout << " -- end of code -- " << endl;
}

// https://www.cprogramming.com/tutorial/virtual_inheritance.html
// https://stackoverflow.com/questions/2659116/how-does-virtual-inheritance-solve-the-diamond-multiple-inheritance-ambiguit
