#include <iostream>
#include <string>
#include <list>
using namespace std;

class Enemy {    
    public: 
        Enemy(){}
        ~Enemy(){}
        
        Enemy(int i, string s, int h, float d) { // cons overloaded
            id = i;  Name = s; Health = h; Damage = d;
        }    
    
        int id = 0;
        string Name = "";
        int Health = 100;
        float Damage = 10.f;

        string dbug() {
            //cout << "Name: "<< Name << "  Health: "<< Health << "  Damage: "<< Damage << endl;
            return  "\n \n ID: " + to_string(id) +
                    "  \n Name: " + Name +
                    "  \n Health: " + to_string(Health) +
                    "  \n Damage: " + to_string(Damage) +
                    "  \n \n ";
        }

        // damage
        Enemy operator + (int RghtVar) { // + int overload 
            this->Health += RghtVar;
            return *this;
        }

        //     en_03 = en_03 - 85;

        Enemy operator - (int RghtVar) { // + int overload 
            this->Health -= RghtVar;
            return *this;
        }

        // assignment operator
        bool operator == (const Enemy& ed) const { //  == overload
            return (this->Name == ed.Name);
        }
        // const at the end -> this wont modify any class properties
        // https://www.youtube.com/watch?v=ehJKvbbe9hk
};

class EnemyGroupe {
    public:
        //con/des
        EnemyGroupe(){}
        ~EnemyGroupe(){}

        list<Enemy> EnemyDetailList;
        
        // B
        EnemyGroupe operator + (const Enemy& ed) { //  overload +
            this->EnemyDetailList.push_back(ed);
            return *this;
        }

        //     en_groupeA = en_groupeA + en_01;
        
        // D
        //void operator += (Enemy& ed) { //  overload +=
        //    this->EnemyDetailList.push_back(ed);
        //}

        void dbug() {
            if (EnemyDetailList.size() == 0) {
                cout << "  >> Enemy Groupe list is empty. " << endl;
                return; // <-- jump out of this function
            }
            
            for (Enemy ed : EnemyDetailList) {  cout << " Enemy Groupe: " << ed.Name << endl; }
            cout << " Enemy Groupe list size: " << EnemyDetailList.size() << endl;
        }
};


// overload << // D
//ostream& operator << (ostream& command, EnemyGroupe& eg) { // overload << 
//    eg.dbug();
//    return command;
//}

int main(){
    
    Enemy en_01 = Enemy(1, "Orc", 120, 5.f);
    Enemy en_02 = Enemy(2, "Human A", 80, 10.f);
    Enemy en_03 = Enemy(2, "Human B", 100, 25.f); 
    Enemy en_04 = Enemy(2, "Zerg", 100, 25.f);

    Enemy en_05 = Enemy(2, "Human A", 100, 25.f);

    // + and -   overloading
    cout << " I   -------- en_03 -------- " << en_03.Health << endl;
    en_03 = en_03 + 85;
    cout << " II  -------- en_03 -------- " << en_03.Health << endl;
    en_03 = en_03 - 10;
    cout << " III -------- en_03 -------- " << en_03.Health << endl;

    // ==   overloading
    cout << "\n-------- A -------- \n" << endl;    
    cout << "compare: " << (en_02 == en_03) << endl;
    cout << "compare: " << (en_02 == en_05) << endl;

    // ////////////////////////////////////////////////////


    cout << "\n-------- B -------- \n" << endl;
    EnemyGroupe en_groupeA;
    
    //cout << en_groupeA; // empty // D 
    en_groupeA.dbug();
    en_groupeA = en_groupeA + en_01;
    en_groupeA.dbug();
    //cout << en_groupeA;  // D

    cout << "\n-------- C -------- \n" << endl;
    en_groupeA = en_groupeA + en_03;
    en_groupeA = en_groupeA + en_03 + en_04;
    en_groupeA.dbug();
    //cout << en_groupeA; 
    
    //cout << "\n-------- D -------- \n" << endl;
    //en_groupeA += en_01;
    //en_groupeA += en_04;
    en_groupeA.dbug();
    ////cout << en_groupeA; 

}


// C++ operator overloading
// https://www.programiz.com/cpp-programming/operator-overloading
// https://en.cppreference.com/w/cpp/language/operators
// https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c

// C++ list
// https://www.geeksforgeeks.org/list-cpp-stl/
// https://www.youtube.com/watch?v=21KH3lJhoEs
// https://www.youtube.com/watch?v=6OoSgY6NVVk