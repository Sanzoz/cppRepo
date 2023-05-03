#include <iostream>
using namespace std;

int main() {
    
    // A - pointers
    // variables save data , pointers save address // <-- only rule
    // variables save data , pointers save address as an iteger // 

    //int value = 54; // save 54 integer number in "value" 
    //cout << "  Value        : " << value <<endl;
    //cout << "  Value address: " << &value <<endl;

    //int* PT = &value; // save address of "value" in PT integer pointer
    //cout << "  PT           : " << PT << endl;
    //cout << "  PT points to : " << *PT << endl; 
    //cout << " \n";

    //*PT = 74; // <-- change the value at that address
    //cout << "       PT           : " << PT << endl;
    //cout << "       PT points to : " << *PT << endl; // de-reference pointer
    //// magic is here !
    //cout << "       Value        : " << value << endl;

    //float val_02 = .025f;
    //// int* PT2 = &val_02; // <-- not working, data types are not the same 

    //int* pt4; // <-- uninitialised pointer
    ////*pt4 = 54; // <-- not working

    //int* pt8 = nullptr; // <-- null pointer, introdused in C++ 11 
    //// *pt8 = 54; // <-- not working
    //// cout << "       pt8 value : " << *pt8 << endl; // de-reference pointer
    //
    //int* pt9 = NULL; // <-- NULL is a macro and presents 0
    //// *pt9 = 54; // <-- not working
    //// cout << "       pt9 value : " << *pt9 << endl; // de-reference pointer
    // https://www.youtube.com/watch?v=eNofmKYzje4&list=PL43pGnjiVwgSSRlwfahAuIqoJ8TfDIlHq
    // https://www.youtube.com/watch?v=DTxHyVn0ODg
    // https://stackoverflow.com/questions/20509734/null-vs-nullptr-why-was-it-replaced
    // ////////////////////////////////////////////// more pointers /////////
    
    // B - assign other variable`s values
    
    //bool ActivateExtra = false;
    //int Health = 5400;
    //int SuperHealth = 200000;
    //
    //cout << "   %%%    BF Health      : " << Health << "   %%% "<< endl;
    //cout << "   %%%    BF SuperHealth : " << SuperHealth << "   %%% " << endl;
    //// code
    //ActivateExtra = true;
    //if (ActivateExtra) {
    //    int* ptr = &Health;
    //    *ptr = SuperHealth; // <-- assign other variable DATA to the de-referebnced pointer
    //}
    //cout << " \n";
    //cout << "   %%%    AF Health      : " << Health << "   %%% " << endl;
    //cout << "   %%%    AF SuperHealth : " << SuperHealth << "   %%% " << endl;

    // ///////////////////////////////////////////////////////
    // C - use pointer as an iterator
    //int InventoryItemsID[6] = { 40, 82, 120, 888, -12, 0 }; // arrays of intigers - integre is 4 bytes
    //int* ptArray = InventoryItemsID; // <- will save first element address
    //cout << "\n  A -        ptArray points to : " << *ptArray << endl; // de-reference pointer

    //cout << "\n  B - iterate forward  - \n";
    //for (int i = 0; i < 6; i++) {
    //    cout << " " << * (ptArray + i) << " ";
    //}
   
    //cout << "\n  C - iterate backward - \n";
    //for (int i = 3; i >= 0; i--) {
    //    cout << " " << *(ptArray + i) << " ";
    //}
    //
    //cout << " \n";

    //float UnitMagicPower[6] = { 4.0f, 8.2f, 1.20f, 8.88f, -1.2f, 0.f }; // arrays of floats - float is 4 bytes
    //float* ptA = UnitMagicPower; // save first element address
    //cout << "\n  D -        ptA points to : " << *ptA << endl; // de-reference pointer

    //cout << "\n  E - iterate forward  - \n";
    //for (int i = 0; i < 5; i++) {
    //    cout << " " << *(ptA + i) << " ";
    //}

    cout << "\n --------- end of code ------------ " << endl;
}

// D  - pass reference of variables to function

//#include <iostream>
//using namespace std;
//
//void Expo_typeA(int val_01, int val_02, int* e, int* e_sw) {// <-- accept pointer
//    for (int i = 0; i < (val_01 + 1); i++) {
//        *e = *e * val_02; // val_02 ^ val_01
//    }
//
//    for (int j = 0; j < (val_02 + 1); j++) {
//        *e_sw = *e_sw * val_01;// val_01 ^ val_02
//    }
//}
//
//
//int main() {
//    int Exponent = 1;
//    int Exponent_Swap = 1;
//
//    Expo_typeA(2 ,4 ,&Exponent , &Exponent_Swap); // <-- pass the address
//    
//    cout << "\n  Exponent  - " << Exponent << endl;
//    cout << "\n  Exponent_Swap  - " << Exponent_Swap << endl;
//    
//    cout << "\n --------- end of code ------------ " << endl;
//}

//
//// E  - dynamic size array 1D
//#include <iostream>
//using namespace std;
//
//int main() {
//    int array_size;
//    cout << "\n  Array size ? - ";
//    cin >> array_size;
//
//    //int array_01[array_size]; // <-- not working, size of array must be contant int number
//    int* array_02 = new int[array_size]; // <-- ok
//    for (int i = 0; i < array_size; i++) {
//        cout << " --> " << i << " ? ";
//        cin >> array_02[i];
//    }
//    for (int j = 0; j < array_size; j++) {
//        cout << "Array element " << j << "   " << array_02[j] << endl;
//    }
//
//    delete[] array_02; // delete pointer to array_02
//    array_02 = NULL; // remove array_02
//    
//    // dynamic size array 2D
//    // research - https://www.youtube.com/watch?v=mGl9LO-je3o&list=PL43pGnjiVwgSSRlwfahAuIqoJ8TfDIlHq&index=6
//
//    cout << "\n --------- end of code ------------ " << endl;
//}

