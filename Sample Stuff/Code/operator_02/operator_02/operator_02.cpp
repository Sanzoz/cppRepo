#include <iostream>
#include <string>
#include <list>
using namespace std;

class Unit_Base {
    //con/des
public:
    Unit_Base() {   ItemDamage = 5; }
    ~Unit_Base() {}
    // properties
    string ItemName = "0";
    int ItemCount = 0;
    int ItemDamage = 0;
    int ItemSheild = 0;

    void PlayReport(string txt) {
        if (ItemSheild <= 0) {
            ItemSheild = 0;
            cout << "  " << txt << " xx House is destroyed xx " << endl;
        } else {
            cout << "  " << txt << " House sheild: " << ItemSheild << endl;
        }
    }
};

class Catapult : public Unit_Base {
public:
    Catapult() {            ItemName = "Rising Hell";   }
    Catapult(int damage) {  ItemDamage = damage;        }  // cons overloaded
    ~Catapult() {}
};


class CivHouse : public Unit_Base {
public:
    CivHouse() {  // cons overloaded
        ItemName = "House level 2";
        ItemSheild = 12000;
    }
    ~CivHouse() {}

    void GetDamage(Catapult ct) { ItemSheild -= ct.ItemDamage; }

    void operator += (Catapult& ct) { //  += overload 
        this->ItemSheild -= ct.ItemDamage;
    }

    CivHouse operator + (int RghtVar) { // + int overload 
        this->ItemSheild -= RghtVar;
        return *this;
    }
};



CivHouse operator + (const CivHouse& leftVar, const Catapult& RghtVar) {
    CivHouse* C = new CivHouse();
    C->ItemSheild = leftVar.ItemSheild;
    C->ItemSheild -= RghtVar.ItemDamage;
    return *C;
}

CivHouse operator + (const Catapult& leftVar, const CivHouse& RghtVar) {
    CivHouse* C = new CivHouse();
    C->ItemSheild = RghtVar.ItemSheild;
    C->ItemSheild -= leftVar.ItemDamage;
    return *C;
}



int main(){

    CivHouse* House = new CivHouse();
    Catapult* Catapult_01 = new Catapult(1000);

    // 01
    House->PlayReport(" -start: ");

    *House += *Catapult_01; // House = House + Catapult_01
    House->PlayReport(" -A: ");
    
    *House = *House + 85;
    House->PlayReport(" -B: ");
      

    *House = *House + *Catapult_01;
    House->PlayReport(" -C: ");
    
    *House = *Catapult_01 + *House; 
    House->PlayReport(" -D: ");


    *House = *House + *Catapult_01 + *Catapult_01; 
    House->PlayReport(" -D: ");

    // make new instance 
    Catapult* Catapult_02 = new Catapult(2000);
    *House += *Catapult_02; // House = House + Catapult_02
    House->PlayReport(" -G: ");

    
    
    //*House = *House + *Catapult_01 + *Catapult_01 + *House; // <-- problem  *House + *House 
    //*House = (*House + *Catapult_01) + (*Catapult_01 + *House); // <-- problem  *House + *House 
    //*House = *House + *Catapult_01 + *Catapult_01 + *Catapult_02; // no problem
    //House->PlayReport(" -F: ");
}
