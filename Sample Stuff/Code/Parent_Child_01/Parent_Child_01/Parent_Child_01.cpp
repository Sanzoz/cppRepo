#include <iostream>
#include <string>
using namespace std;

class UnitBase {
    public:
        UnitBase() { cout << " -- UnitBase constructor" << endl; } // if commented, will not run
        ~UnitBase() {}

        int id = 0;
        string Name = "";
        virtual string Fire() { return  "\n UnitBase -Base  Fire "; }
};

class Agent_V : public UnitBase {
    public:
        Agent_V()  { cout << " -- Agent_V constructor" << endl; } // if commented, will not run
        ~Agent_V() {}
        virtual string Fire() override { return  "\n Agent_V  -vv  Fire"; }
        void MagicFire() { cout << " Agent_V  --VVVV-- >  Fire magic! \n\n"; }
};

class Agent_H458: public UnitBase {
    public:
        Agent_H458() { cout << " -- Agent_H458 constructor" << endl; }
        ~Agent_H458() {}
        virtual string Fire() override { return  "\n Agent_H458  - -hh  Fire"; }
        virtual void MagicFire() { cout << " Agent_H458 -HHHHH-->  Fire magic! \n\n"; }
};

// /// ////////////////////////////////////////////////
class Agent_SuperV : public Agent_V {
    public:
        Agent_SuperV() { cout << " -- Agent_SuperV constructor" << endl; }
        ~Agent_SuperV() {}
        virtual string Fire() override { return  "\n Agent_SuperV ---xvxvx  Fire "; }
        void MagicFire() { cout << " Agent_SuperV  --SVSVSVS-- >  Fire magic! \n\n"; }
};

class Agent_SuperH458 : public Agent_H458 {
    public:
        Agent_SuperH458() { cout << " -- Agent_SuperH458 constructor" << endl; }
        ~Agent_SuperH458() {}
        ///// virtual string Fire() override { return  "\n Agent_SuperV  .... Fire "; } // <-- comented out
        void MagicFire() { cout << " Agent_SuperH458  --hHhHhH-- >  Fire magic! \n\n"; }
};

class exampleAgent : public Agent_SuperH458 {
    public:
        exampleAgent() { cout << " -- exampleAgent constructor" << endl; }
        ~exampleAgent() {}
        void MagicFire() { cout << " exampleAgent  --exexexex-- >  Fire magic! \n\n"; }
};



int main(){

    cout << " --|||   define classes  |||-- " << endl;
    UnitBase* UB = new UnitBase();
    cout << "\n";
    Agent_V* V = new Agent_V();
    cout << "\n";
    Agent_H458* H = new Agent_H458();
    cout << "\n";
    Agent_SuperV* superV = new Agent_SuperV();
    cout << "\n";
    Agent_SuperH458* superH = new Agent_SuperH458();
    cout << "\n";
    exampleAgent* ex = new exampleAgent();
    cout << "\n";
    // /////////////////////////////////////////////////////////
    cout << "\n\n --|||  call Fire()  |||-- " << endl;

    //cout << UB->Fire() << endl;
    //cout << V->Fire() << endl;
    //cout << H->Fire() << endl;
    //cout << superV->Fire() << endl;
    //cout << superH->Fire() << endl; // <-- will use parent class Fire() 
    //cout << ex->Fire() << endl; // <-- will use parent class Fire() 

    //// /////////////////////////////////////////////////////////    
    //cout << "\n\n --|||  call MagicFire()  |||-- " << endl;
    ////UB->MagicFire(); // <-- not implemented, not working
    //V->MagicFire();
    //H->MagicFire();
    //superV->MagicFire();
    //ex->MagicFire();
}

