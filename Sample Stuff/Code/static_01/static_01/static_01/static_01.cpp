#include <iostream>
#include <string>
using namespace std;

//// B
//class Sample {
//    public:
//        Sample() {}
//        ~Sample() {}
//
//        int Value_01 = 0;
//        static int Value_02; // <--- all instances will receive "change"
//
//        static void dbug_A() {
//            // cout << " ++ ShowValue_01   " << to_string(Value_01) << endl; // <-- error - cannot access none static property from a static method
//            cout << " ++ ShowValue_02   " << to_string(Value_02) << endl;
//        }
//
//};
//
//int Sample::Value_02; // <-- must be implemented outside of class

// A
void ShowValueA() {
    static int counter = 0;
    cout << " ++ ShowValueA   " << to_string(counter++) << endl;
}

void ShowValueB() {
    int counter = 0;
    cout << " ** ShowValueB   " << to_string(counter++) << endl;
}

int main(){
    
    // with function - A
    ShowValueA();
    ShowValueA();
    ShowValueA();
    cout << "\n\n\n";
    ShowValueB();
    ShowValueB();
    ShowValueB();

    cout << "\n\n";

    // with class - B
    //Sample S1;
    //S1.Value_01 = 25;
    //S1.Value_02 = 500;
    //cout << " -- S1  Value_01 " << S1.Value_01 << endl;
    //cout << " S1-- static Value_02 " << S1.Value_02 << endl;    
    //cout << "\n\n";
    //Sample S2;
    //S2.Value_01 = 14;
    //cout << " -- S2 Value_01  " << S2.Value_01 << endl;
    //cout << " S2-- static Value_02 " << S2.Value_02 << endl;
    //
    //cout << "\n\n";
    //S1.Value_02 = 888; // <-- change static in S1
    //cout << " S2 -- static Value_02 " << S2.Value_02 << endl;// <-- show static in S2


    cout << " -- end of code -- " << endl;
}

// https://en.cppreference.com/w/cpp/language/static
// https://www.youtube.com/watch?v=V-BFlMrBtqQ



