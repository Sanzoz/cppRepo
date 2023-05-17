#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class Fortress {
    
    int Sheild; // <- private by default
    int Resistance;// <- private by default

public: // <-- error ---- A
    bool Active = false;
    int TotalUnit = 0;
    Fortress() {
        cout << " -- Fortress --- Cosnt --: default " << endl;
    }
    Fortress(int rs) {
        cout << " -- Fortress --- Cosnt --: overloaded " << endl;
        Resistance = rs;
    }
    Fortress(bool a, int u) { 
        cout << " -- Fortress --- Cosnt --: overloaded Active and Total units" << endl;
        Active = a; TotalUnit = u;
    }

    ~Fortress() { }

public:

    void dbug() { cout << " -- Fortress --- dbug --:  SHL> " << Sheild << " -  RST>" << Resistance<< endl; }
    void dbug_pro() { cout << " -- Fortress --- dbug_pro --:  TotalUnit> " << TotalUnit << " -  Active>" << Active << endl; }
    
    //// set private property - getter/setter method  // ---- B 
    /*
    void set_Sheild(int sh){ 
        if ((sh > 0) && (sh < 10000)) {
            Sheild = sh;
        }else if (sh < 0) {
            Sheild = 0;
        } else {
            Sheild = 10000;
        }
    }
    int get_Sheild() { return Sheild; }
    */

    // use friend function // ---- C1

    //friend void setSheild_byFriend(Fortress&, int); // global function
    //friend int getSheild_byFriend(Fortress&); // global function
    
    // use friend in class // ---- C2
    //friend class Hack_Monitor; // class

};


// ---- C1
/*
// void setSheild_byFriend(Fortress ft, int sh) { // error , pass reference
void setSheild_byFriend(Fortress& ft, int sh) {
    ft.Sheild = sh;
}
int getSheild_byFriend(Fortress& ft) {
    return ft.Sheild;
}
*/


// ---- C2
/*
class Hack_Monitor {
    public:
        Hack_Monitor() {}
        ~Hack_Monitor() {}
        void setSheild_byFriendClass(Fortress& ft, int sh) {
            ft.Sheild = sh;
        }
        int getSheild_byFriendClass(Fortress& ft) {
            return ft.Sheild;
        }
};
*/


// call base class constructor //  ---- D
/*
class Farmer_Fortress : public Fortress { //  info: make 200 units and is Active
public: 
    Farmer_Fortress() : Fortress(true, 200){}
    ~Farmer_Fortress(){}
};
class Monster_Fortress : public Fortress { //  info: make 5 units and is not Active
public:
    Monster_Fortress() : Fortress(false, 5) {}
    ~Monster_Fortress() {}
};
class Royal_Fortress : public Fortress { //  info: IF we create this with a name , then make 5000 units and is Active 
public:
    Royal_Fortress() {}
    Royal_Fortress(string n) : Fortress(true, 5000) { frotressName = n; }
    ~Royal_Fortress() {}
    string frotressName = "";
};
*/


int main(){
    
    // class public and private keyword // ---- A
    /*
     Fortress f1 = Fortress();  // <-- error
     Fortress f2 = Fortress(45, 88);  // <-- error 
     Fortress* f3 = new Fortress();  // <-- error 
     Fortress* f4 = new Fortress(45, 88);  // <-- error 
    */
    
    
    
    // class get and set for privates //  ---- B 
    /*    
    Fortress f5_A = Fortress();  
    Fortress* f5_B = new Fortress(); 
    Fortress f6_M = Fortress(88);  
    Fortress* f6_N = new Fortress(88);

    //cout << " -- f5_A -Sheild- " << f5_A.get_Sheild() << endl; // <-- unusual result
    //cout << " -- f5_B -Sheild- " << f5_B->get_Sheild() << endl; // <-- unusual result
    ////
    //f6_M.set_Sheild(200);
    //cout << " -- f6_M -Sheild- " << f6_M.get_Sheild() << endl; // <-- ok
    //f6_N->set_Sheild(5000);
    //cout << " -- f6_N -Sheild- " << f6_N->get_Sheild() << endl; // <-- ok
    ////
    //f6_N->set_Sheild(-6);
    //cout << " --   f6_N -Sheild- >> " << f6_N->get_Sheild() << endl; 
    //f6_N->set_Sheild(12121212121212121212);
    //cout << " --   f6_N -Sheild- >> >>  " << f6_N->get_Sheild() << endl; 
    */



    // use function friend  //  ---- C1
    /*
    Fortress f7_00 = Fortress(88);  
    setSheild_byFriend(f7_00, 56);
    cout << " -f7_00 -Sheild-  " << getSheild_byFriend(f7_00) << endl;
    
    Fortress* f7_01 = new Fortress(88);
    setSheild_byFriend((*f7_01), 56);
    cout << " -f7_01 -Sheild-  " << getSheild_byFriend((*f7_01)) << endl;
    */
    // use class friend  //  ---- C2
    /*
    Hack_Monitor* HM = new Hack_Monitor();
    
    Fortress f8_01 = Fortress(88);
    HM->setSheild_byFriendClass(f8_01, 56);
    Fortress* f8_02 = new Fortress(88);
    HM->setSheild_byFriendClass((*f8_02), 56);

    cout << " - Hack and Monitor ! -  " << HM->getSheild_byFriendClass(f8_01) << endl;
    cout << " - Hack and Monitor ! -  " << HM->getSheild_byFriendClass((*f8_02)) << endl;
    */
    //



    // call parent constructor from child class //  ---- D
    /*
    Farmer_Fortress* FR = new Farmer_Fortress();
    Monster_Fortress* MR = new Monster_Fortress();
    Royal_Fortress* RR = new Royal_Fortress("Aces");
    Royal_Fortress* RR2 = new Royal_Fortress(); // <-- no call on base class

    FR->dbug_pro();
    MR->dbug_pro();
    RR->dbug_pro();
    RR2->dbug_pro();
    */


    cout << " -- end of code -- " << endl;
}


// getter/setter
// https://www.w3schools.com/cpp/cpp_encapsulation.asp
// https://www.youtube.com/watch?v=vFIxFMNNejA
// 
// 
// friend
// global
// class 
// too many friends breaks the encapsulation
// no inhiritation 
// https://www.youtube.com/watch?v=KXDzBglp83M&t=946s


// call base class constructor
// https://www.youtube.com/watch?v=7ucLWfWzqg8
// https://www.youtube.com/watch?v=MmR_qpYthP8

