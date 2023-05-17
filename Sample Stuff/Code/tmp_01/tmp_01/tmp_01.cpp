#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

int main() {

    cout << " -- end of code -- " << endl;
}


/*
// function template // A

void Start(int value) {
    cout << " d " << value << endl;
}

void Start(string value) {
    cout << " S " << value << endl;
}

//void Start(bool value) { // <--- issue on remove comments
//    cout << " B " << value << endl;
//}

void Start(float value) {
    cout << " % " << value << endl;
}

//template <typename T>
//void Start(T value) {
//    cout << " TMP " << value << endl;
//}


int main(){

    Start(77);
    Start(" >> Game - round 4");
    Start(false);
    Start(.77f);

    cout << " -- end of code -- " << endl;
}

// function template // B

//int End(int value) {
//    return value;
//}
//
//string End(string value) {
//    return value;
//}
//
////bool End(bool value) { // <--- issue on remove comments
////    return value;
////}
//
//float End(float value) {
//    return value;
//}

template <typename T>
T End(T value) {
    //return (" TMP " + value); // <-- be carefull
    return value; // ok
}


int main(){

    cout << " -- | -- " << End(88) << endl;
    cout << " -- | -- " << End(" >> Game ends") << endl;
    cout << " -- | -- " << End(true) << endl;
    cout << " -- | -- " << End(.88f) << endl;

    cout << " -- end of code -- " << endl;
}




// function template // C

//int Middle(int value, int u) {
//    return value + u;
//}
//
//string Middle(string value , string s) {
//    return value + s;
//}
//
////bool Middle(bool value, bool b) { // <--- issue on remove comments
////    return value + b;
////}
//
//float Middle(float value, float f) {
//    return value + f;
//}

template <typename T1, typename T2>
T1 Middle(T1 value, T2 v) {
    //return (" TMP " + value); // <-- be carefull
    return (value + v); // ok
}


int main() {

    cout << " -- | -- " << Middle(88, 1000) << endl;
    //cout << " -- | -- " << Middle(" >> Game ends", "    |||<<<") << endl; // <-- problem
    //cout << " -- | -- " << Middle<string, string>(" >> Game ends", "    |||<<<") << endl; // <-- fix
    cout << " -- | -- " << Middle(false, false) << endl;
    cout << " -- | -- " << Middle(.88f, 1000.f) << endl;
    cout << " -- | -- " << Middle(8, .022f) << endl; // <-- careful


    cout << " -- end of code -- " << endl;
}

// https://vector-of-bool.github.io/2021/10/22/string-templates.html
// https://www.geeksforgeeks.org/templates-cpp/
// https://learn.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170
//

// function template - Variadic Function Templates // D


template <typename T> // Middle with one parameter
T Total(T value) {
    return value;
}


template <typename T, typename... Args> // Middle
T Total(T first_value, Args... arg) {
    return first_value + Total(arg...);
}


int main(){

    cout << " -- | -- " << Total(88, 1000, 3, 500, 3, 3) << endl;
    cout << " -- | -- " << Total<string, string, string, string>(" >> Game ends", "    |||<<<", " --- " , " HARD mode") << endl;
    cout << " -- | -- " << Total(false, false, true, true, false) << endl;
    cout << "\n";
    cout << " -- | a-- " << Total(1.f, 1.0f, 0.0003f, 1) << endl;
    cout << " -- | -b- " << Total(1, 1.f, 0.0003f, 1) << endl;
    cout << " -- | --c " << Total(1.f, 1, .0003f, 1.f) << endl; // <-- issue

    cout << " -- | -- " << Total(.88f, 1000, 10.0003f, 100.f) << endl; // <-- issue


    cout << " -- end of code -- " << endl;
}


// https://www.youtube.com/watch?v=irFkMavpL9A
// https://stackoverflow.com/questions/2183087/why-cant-i-use-float-value-as-a-template-parameter
// https://stackoverflow.com/questions/63694879/floating-point-types-as-template-parameter-in-c20








*/

