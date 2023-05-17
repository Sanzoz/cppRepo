#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


int main() {

    cout << " -- end of code -- " << endl;
}


/*


// class template - problem // 00

class Mirror {
public:
    string signature;
    Mirror() {}
    Mirror(string s) { signature = s; }
    ~Mirror() {}
    string getSignature() { return signature; }
};

class Mirror {
public:
    int signature;
    Mirror() {}
    Mirror(int s) { signature = s; }
    ~Mirror() {}
    int getSignature() { return signature; }
};



int main() {

    Mirror* M1 = new Mirror("Iron Side");
    Mirror* M2 = new Mirror(740024); // <-- problem
    //Mirror_pro* M2 = new Mirror_pro(740024); // <-- possible fix, make new class

    cout << " -- | -- " << M1->getSignature() << endl;
    cout << " -- | -- " << M2->getSignature() << endl;


    cout << " -- end of code -- " << endl;
}




// class template - fix // 01

template <typename T>
class Mirror {
public:
    T signature;
    Mirror() {}
    Mirror(T s) { signature = s; }
    ~Mirror() {}
    T getSignature() { return signature; }
};




int main() {

    Mirror<string>* M1 = new Mirror<string>("Iron Side");
    Mirror<int>* M2 = new Mirror<int>(740024);

    cout << " -- | -- " << M1->getSignature() << endl;
    cout << " -- | -- " << M2->getSignature() << endl;


    cout << " -- end of code -- " << endl;
}


//
//// class template  // 02
//template <typename T>
//class Mirror {
//public:
//    T signature;
//    Mirror() {}
//    Mirror(T s) { signature = s; }
//    ~Mirror() {}
//    T getSignature() { return signature; }
//};
//
//// signatures of mirror
//class CzechMade {
//public:
//    CzechMade() {}
//    void dbug() { cout << " -- CzechMade -- " << endl; }
//    /* code */
//};
//
//
//class SilverMade {
//public:
//    void dbug() { cout << " -- SilverMade -- " << endl; }
//    /* code */
//};
//class HandMade { /* code */ };
//
//
//
//
//
//int main() {
//
//    CzechMade* CZ = new CzechMade();
//    SilverMade* SL = new SilverMade();
//    HandMade* HM = new HandMade();
//
//    Mirror<CzechMade>* M1 = new Mirror<CzechMade>(*CZ);
//    Mirror<SilverMade>* M2 = new Mirror<SilverMade>(*SL);
//    Mirror<HandMade>* M3 = new Mirror<HandMade>(*HM);
//
//    (M1->getSignature()).dbug();
//    (M2->getSignature()).dbug();
//    // (M3->getSignature()).dbug();
//
//    // expensive
//    //CzechMade CZ = CzechMade();
//    //SilverMade SL = SilverMade();
//    //HandMade HM = HandMade();
//
//    //Mirror<CzechMade>* M1 = new Mirror<CzechMade>(CZ);
//    //Mirror<SilverMade>* M2 = new Mirror<SilverMade>(SL);
//    //Mirror<HandMade>* M3 = new Mirror<HandMade>(HM);
//
//
//
//
//    cout << " -- end of code -- " << endl;
//}

//// class template - assign value // 03
//template <typename T, int PRC>
//class Mirror {
//public:
//    T signature;
//    int price = PRC;
//    Mirror() {}
//    Mirror(T s) { signature = s; }
//    ~Mirror() {}
//    T getSignature() { return signature; }
//    int getPrice() { return price; }
//    // int getPrice() { return PRC; } // <-- logicaly correct 
//};
//
//// signatures of mirror
//class CzechMade {
//public:
//    CzechMade() {}
//    void dbug() { cout << " -- CzechMade -- " << endl; }
//    /* code */
//};
//
//
//class SilverMade {
//public:
//    void dbug() { cout << " -- SilverMade -- " << endl; }
//    /* code */
//};
//class HandMade { /* code */ };
//
//
//
//
//
//int main() {
//
//    CzechMade* CZ = new CzechMade();
//    SilverMade* SL = new SilverMade();
//    HandMade* HM = new HandMade();
//
//    Mirror<CzechMade, 8000>* M1 = new Mirror<CzechMade, 8000>(*CZ);
//    Mirror<SilverMade, 6000>* M2 = new Mirror<SilverMade, 6000>(*SL);
//    Mirror<HandMade, 12000>* M3 = new Mirror<HandMade, 12000>(*HM);
//
//    (M1->getSignature()).dbug();
//    (M2->getSignature()).dbug();
//
//    cout << M1->getPrice() << endl;
//    cout << M2->getPrice() << endl;
//    cout << M3->getPrice() << endl;
//
//    cout << " -- end of code -- " << endl;
//}
//
//
//// https://www.youtube.com/watch?v=ttOM3HulFyU
//// https://www.youtube.com/watch?v=I-hZkUa9mIs
//// https://www.youtube.com/watch?v=mQqzP9EWu58
//// https://www.codeproject.com/Articles/229460/Dependant-Name-Hell
//// https://www.programiz.com/cpp-programming/class-templates

