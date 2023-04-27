#include <iostream>
#include <string>
using namespace std;
int main() { }
// A -  functions send/receive Reference 
// 
//void passByValue(int val);
//void passByRefrence(int& val);
//
//int returnOneValue(int value, int multiplayer);
//void returnMultipleValues(int& a, int& b, int& c, int multiplayer);
//
//int setTotalMark(int& val); // <-- be careful !!
//
//int main() {
//    // //////////////////////////////////////////////////////
//    cout << "\n- 00 --------------------------- passByValue \n";
//
//    int Value = 4;
//    passByValue(Value);
//    cout << "A) -- Value  |  " << Value << endl;
//
//    cout << "\n- 00 --------------------------- passByRefrence \n";
//    passByRefrence(Value);
//    cout << "B) -- Value  |  " << Value << endl;
//
//
//    // //////////////////////////////////////////////////////
//
//    int Shield = 400;
//    int Speed = 75;
//    int Damage = 5000;
//
//    cout << "\n\n- 01 ---------------------------returnOneValue \n";
//    Shield = returnOneValue(Shield, 2);
//    Speed = returnOneValue(Speed, 2);
//    Damage = returnOneValue(Damage, 2);
//
//    cout << "A) -- Shield        |" << Shield << endl;
//    cout << "A) -- Speed         |" << Speed << endl;
//    cout << "A) -- Damage        |" << Damage << endl;
//    cout << "----------\n";
//
//    cout << "\n\n- 01 ---------------------------returnMultipleValues \n";
//    returnMultipleValues(Shield, Speed, Damage, 2);
//    cout << "B) -- Shield        |" << Shield << endl;
//    cout << "B) -- Speed         |" << Speed << endl;
//    cout << "B) -- Damage        |" << Damage << endl;
//
//
//    // //////////////////////////////////////////////////////
//
//    cout << "\n\n- 02 ---------------------------setTotalMark \n";
//    cout << "xx -- Result         x " << Damage << endl;
//    cout << "xx -- setTotalMark   x " << setTotalMark(Damage) << endl;
//    cout << "xx -- Result         x " << Damage << endl;
//
//}
//
//// research --> Stack vs Heap in C++
//// https://www.educba.com/c-stack-vs-heap/
//// https://stackoverflow.com/questions/39706296/how-is-c-compiled
//
//void passByValue(int val) {
//    val += 100; // val will goes to stack
//    cout << "            passByValue > " << val << endl;
//} // val will be removed from stack
//
//
//void passByRefrence(int& val) {
//    val += 100;
//    cout << "         passByRefrence > " << val << endl;
//}
//
//// ------------------------
//int returnOneValue(int value, int multiplayer) {
//    value *= multiplayer;
//    return value;
//}
//
//void returnMultipleValues(int& a, int& b, int& c, int multiplayer) {
//    a *= multiplayer;
//    b *= multiplayer;
//    c *= multiplayer;
//}
//
//// ------------------------
//int setTotalMark(int& val) {
//    val = val * 12800; //or  val *= 12800;
//    return val;
//    // unsafe and dangerous -> val will get destroyed after return, so the return object (the int) will be null
//
//    //val = val * 12800; // use refrence in code;
//    //int output = val; // save result in temporay variable
//    //return output; // return temporay variable
//}


// B apssing array to function 

//void checkArray(int arr[]) {
//	arr[0] = 85;
//}
//
//int main() {
//	int anArray[4] = { 1,2,2,2 };
//	cout << anArray[0] << " --A-- \n";
//	checkArray(anArray);
//	cout << anArray[0] << " --B-- default: arrays are passing by reference. \n";
//}
//// https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
 


