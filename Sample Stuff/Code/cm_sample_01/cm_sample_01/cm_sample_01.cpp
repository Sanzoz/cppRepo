#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

struct EnemyDetails {
    int id = 0;
    string Name = "";
    int Health = 100;
    float Damage = 10.f;

    EnemyDetails(int i, string s, int h, float d) { id = i;  Name = s; Health = h; Damage = d; }
    
    string dbug() {
        //cout << "Name: "<< Name << "  Health: "<< Health << "  Damage: "<< Damage << endl;
        return  "\n \n ID: " + to_string(id) +
            "  \n Name: " + Name +
            "  \n Health: " + to_string(Health) +
            "  \n Damage: " + to_string(Damage) +
            "\n \n ";
    }

    bool operator==(const EnemyDetails& ed) const { return (this->Name == ed.Name); }
};

class EGroupe_ID {
public:

    int* myContainer;
    int size = 0;

    EGroupe_ID() { } // default empty constructor

    EGroupe_ID(int s) {// overloaded constructor
        size = s;
        myContainer = new int[size] {0}; // <-- make arrays of integers with dynamic size in runtime
    }

    
    // /////////   operator overloading /////////// 
    int& operator[](int i) { // array operators
        return myContainer[i];      
    }    



    EGroupe_ID operator+(const EGroupe_ID& otherEGroupe) {    // _A + _B // add class values with each other
        EGroupe_ID tempObject(size + otherEGroupe.size); // new object with size of both A and B
        for (int i = 0; i < size; i++)      tempObject[i] = myContainer[i];
        for (int j = 0; j < otherEGroupe.size; j++)   tempObject[size + j] = otherEGroupe.myContainer[j];
        return tempObject;
    }

    // --------------copy-------------------  /////////////////////////////////////////////////////////// 
    // copy assignment operator  -->_A = _B  
    EGroupe_ID& operator=(const EGroupe_ID& otherEGroupe) {
        cout << " --using ---- Copy >> assign operator" << endl;
        
        if (this == &otherEGroupe) { //  if copy itself 
            return *this; // return itself and finished
        }

        if (myContainer) delete[] myContainer;
        size = otherEGroupe.size;
        myContainer = new int[size];
        for (int i = 0; i < size; i++) myContainer[i] = otherEGroupe.myContainer[i];
        return *this;
    }

    //// copy constructor ---> EGroupe_ID temp_01 = temp_02; -->  temp_01 is a EGroupe_ID
    EGroupe_ID(const EGroupe_ID& otherEGroupe) {
        cout << " --using ---- Copy >> constructor" << endl;
        size = otherEGroupe.size;
        myContainer = new int[size]; // <-- make arrays of integer with dynamic size in runtime
        for (int i = 0; i < size; i++) {
            myContainer[i] = otherEGroupe.myContainer[i];
        }
    }

    // --------------move------------------- 
    //// move constructor ---> EGroupe_ID temp_01 = temp_02; -->  temp_01 is a EGroupe_ID
    EGroupe_ID(EGroupe_ID&& otherEGroupe) {
        cout << " --using ---- Move >> constructor" << endl;
        size = otherEGroupe.size;
        myContainer = otherEGroupe.myContainer;
        otherEGroupe.myContainer = nullptr;
    }

    //////// move assignment operator  -->_A = _B  
    EGroupe_ID& operator=(EGroupe_ID&& otherEGroupe) {
        cout << " --using ---- Move >> assign operator" << endl;
        size = otherEGroupe.size;
        myContainer = otherEGroupe.myContainer;
        otherEGroupe.myContainer = nullptr;
        return *this;
    }



    void dbug() {
        if (size) for (int i = 0; i < size; i++)  cout << " debug ID at  " << i << "  -- > " << to_string(myContainer[i]) << endl;
        else   cout << " >Countainer is empty" << endl;
    }

    ~EGroupe_ID() {
        if (myContainer) delete[] myContainer;
        myContainer = nullptr;
    }
};



ostream& operator<<(ostream& command, EGroupe_ID& eg) {
    eg.dbug();
    return command;
}


int main() {


    // 01 --- show details 
    EnemyDetails Orc_01 = EnemyDetails(101, "Orc", 120, 5.f);
    cout << Orc_01.dbug();
    
    EGroupe_ID en_groupeB = EGroupe_ID(1); // make empty groupe with size 1
    en_groupeB.dbug();
    
    en_groupeB[0] = Orc_01.id; // [] operator will replaced by an integer, them assign works as default
    en_groupeB.dbug();

    //cout << en_groupeB;

    cout << "\n\n"; 

    EnemyDetails Human_01 = EnemyDetails(2, "Human", 80, 10.f);
    EGroupe_ID en_groupeC;
    ////en_groupeC[0] = Human_01.id; // <-- crash
    en_groupeC.dbug();

    cout << "\n\n\n\n";



    // ---------------------copy vs move--------------------------

    //cout << "\n -- make groups with teams  -- A \n";
    //EnemyDetails Elves_01 = EnemyDetails(24, "Elves_01", 80, 10.f);
    //EGroupe_ID en_groupeD = EGroupe_ID(1);  // make empty groupe with size 1
    //en_groupeD[0] = Elves_01.id;
    //en_groupeD.dbug();

    //EnemyDetails Dorf_01 = EnemyDetails(700, "Dorf", 80, 10.f);
    //EGroupe_ID en_groupeE = EGroupe_ID(1);
    //en_groupeE[0] = Dorf_01.id;
    //en_groupeE.dbug();


    //cout << "\n -- assign groupes to each  -- B \n";

    ////en_groupeE = en_groupeD;
    //en_groupeD = en_groupeE; 
    //en_groupeD.dbug();


    //cout << "\n -- empty groupe assign and +  -- C \n";
    //EGroupe_ID en_groupeF;
    //en_groupeF = en_groupeD + en_groupeE;
    //en_groupeF.dbug();

    //cout << "\n -- empty groupe assign with constructor  -- D \n";
    //EGroupe_ID en_groupeG = en_groupeF;
    //en_groupeG.dbug();

}

// move constructor
// https://pspdfkit.com/blog/2019/when-cpp-doesnt-move/
// https://stackoverflow.com/questions/62097789/why-copy-constructor-is-used-while-move-constructor-has-been-removed
// https://stackoverflow.com/questions/13099603/c11-move-constructor-not-called-default-constructor-preferred
// https://stackoverflow.com/questions/71448625/copy-move-constructor-is-not-called-when-storing-result-of-overloaded-operator
// move and copy
// https://www.youtube.com/watch?v=E4MWxaUy3zo
// https://www.youtube.com/watch?v=F-7Rpt2D-zo


