#include <iostream>
#include <string>
using namespace std;
int main() { }


// A -  units damage - function

//void TakeDamage(int health, int damage, string name); // <-- signature at beginning
//
//int main() {
//
//    // enemy units
//    string EnemyCharacter_01_Name = "Orc";
//    int EnemyCharacter_01_id = 0;
//    int EnemyCharacter_01_Health = 100;
//
//    string EnemyCharacter_02_Name = "Undead";
//    int EnemyCharacter_02_id = 1;
//    int EnemyCharacter_02_Health = 200;
//
//    string EnemyCharacter_03_Name = "Human";
//    int EnemyCharacter_03_id = 2;
//    int EnemyCharacter_03_Health = 50;
//
//    // take damage
//    TakeDamage(EnemyCharacter_01_Health, 25, EnemyCharacter_01_Name);
//    TakeDamage(EnemyCharacter_02_Health, 40, EnemyCharacter_02_Name);
//    TakeDamage(EnemyCharacter_03_Health, 20, EnemyCharacter_03_Name);
//
//}
//
//void TakeDamage(int health, int damage, string name) { // <-- implementation at beginning
//    health -= damage;
//    cout << "unit name: " << name << " -  Health: " << health << endl;
//}


// ///////////////////////////////////////////////////////////////////////////
// B -  units damage - structur

//struct EnemyCharacter {
//    int id;
//    string Name;
//    int Health;
//
//    void TakeDamage(float damage) {
//        Health -= damage;
//        cout << "Enemy " << Name << " - Health: " << Health << endl;
//    };
//};
//
//// C++ struct https://www.youtube.com/watch?v=9j5KkOC_goQ
//// https://www.youtube.com/watch?v=-IrueTrxNHA
//
//int main() {
//    EnemyCharacter enemyUnit_01;
//    enemyUnit_01.id = 0;
//    enemyUnit_01.Name = "Orc";
//    enemyUnit_01.Health = 100;
//
//    EnemyCharacter enemyUnit_02 = { 1, "Undead", 100 }; // inline implementations
//
//    enemyUnit_01.TakeDamage(10);
//    enemyUnit_01.TakeDamage(10);
//    enemyUnit_01.TakeDamage(10);
//    
//    enemyUnit_02.TakeDamage(40);
//}

// ///////////////////////////////////////////////////////////////////////////
// C -  return value from function
//
//void GetMinimum_typeA(int a, int b);
//int GetMinimum_typeB(int a, int b);
//string GetMinimum_typeC(int a, int b);
//
//int main() {
//
//    cout << "\n  A) -- Value 7 and 10 | ";
//    GetMinimum_typeA(7, 10);
//    cout << "\n\n";
//    cout << "\n  B) -- Value 7 and 10 | ";
//    GetMinimum_typeB(7, 10); // <-- no result
//    cout << "\n  B) -- Value 7 and 10 | " << GetMinimum_typeB(7, 10) << " higest" << endl; // <-- has result
//    cout << "\n\n";
//    cout << "\n  C) -- Value 7 and 10 | " << GetMinimum_typeC(7, 10) << endl;
//
//}
//
//void GetMinimum_typeA(int a, int b) {
//    if (a > b) {
//        cout << a << " higest";
//    } else if (a < b) {
//        cout << b << " higest";
//    } else {
//        cout << " equal";
//    }
//}
//
//int GetMinimum_typeB(int a, int b) {
//    if (a > b) {
//        return a;
//    } else if (a < b) {
//        return b;
//    }
//    return 0;
//}
//
//string GetMinimum_typeC(int a, int b) {
//    string result = "equal";
//    if (a > b) {
//        result = to_string(a) + " higest"; // <-- use "to_string" to convert int to string
//    } else if (a < b) {
//        result = to_string(b) + " higest";
//    }
//    return result;
//}


// E - global variables

//void Attack_Land();
//int Attack_Air();
//int Attack_Sonic();
//int Attack_Space();
//
//
//int GLOBAL_Rank = 100; // <--- global variable
//
//int main() {
//
//    cout << "-----Land Attack-----\n";
//    int PlayerRank = 100;
//    Attack_Land();
//    Attack_Land();
//    Attack_Land();
//    Attack_Land();
//
//    cout << "--A--      Rank------" << GLOBAL_Rank << endl;
//
//    cout << "\n    ++++    \n";
//    GLOBAL_Rank++;
//    GLOBAL_Rank++;
//    GLOBAL_Rank++;
//    cout << "--B--      Rank------" << GLOBAL_Rank << endl;
//
//    cout << "\n    ++++    \n";
//    cout << "--C--Attack_Air------" << Attack_Air() << endl;
//    cout << "--C--Attack_Air------" << Attack_Air() << endl;
//    cout << "--C--Attack_Air------" << Attack_Air() << endl;
//    cout << "--C--      Rank------" << GLOBAL_Rank << endl;
//
//    cout << "\n    ++++    \n";
//    cout << "--D--Attack_Sonic------" << Attack_Sonic() << endl;
//    cout << "--D--Attack_Sonic------" << Attack_Sonic() << endl;
//    cout << "--D--Attack_Sonic------" << Attack_Sonic() << endl;
//    cout << "--D--      Rank------" << GLOBAL_Rank << endl;
//
//    cout << "\n    ++++    \n";
//    cout << "--E--Attack_Space------" << Attack_Space() << endl;
//    cout << "--E--Attack_Space------" << Attack_Space() << endl;
//    cout << "--E--Attack_Space------" << Attack_Space() << endl;
//    cout << "--E--      Rank------" << GLOBAL_Rank << endl;
//
//}
//
//void Attack_Land() {
//    //cout << "-----Land Attack--------------\n";
//    GLOBAL_Rank++;
//    //PlayerRank++; // <--- not working
//}
//
//int Attack_Air() {
//    //cout << "-----Air Attack--------------\n";
//    return GLOBAL_Rank++; // <-- return GLOBAL_Rank first, then apply ++ operation
//}
//int Attack_Sonic() {
//    //cout << "-----Sonic Attack--------------\n";
//    return ++GLOBAL_Rank; // <-- first apply ++ operation, then return GLOBAL_Rank
//}
//
//int Attack_Space() {
//    //cout << "-----Space Attack--------------\n";
//    int tempRank = GLOBAL_Rank;
//    tempRank++;
//    return tempRank;
//}


// F return issue
//
//int FunctionA() {
//    int a = 20;
//    if (a < 10) {
//        return a;
//    }
//               // <-- no return!
//}
//
//int FunctionB() {
//    int a = 20;
//    if (a < 10) {
//        return a;
//    }
//    return 0; // <-- using return
//}
//
//int main() {
//    cout << FunctionA(); // <-- issue 
//    cout << "\n\n"; 
//    cout << FunctionB(); // <-- ok 
//}

// G enums

//enum class animState {
//	anim_Idle,
//	anim_Walk,
//	anim_Run,
//	anim_Shoot
//};
//// https://en.cppreference.com/w/cpp/language/enum
//// https://www.youtube.com/watch?v=x55jfOd5PEE
//
//int main() {
//
//	animState anim = animState::anim_Idle;
//	// animState anim = anim_Idle; // <-- not working
//
//	switch (anim){
//		case(animState::anim_Idle):
//			cout << "Player state: Idle." << endl;
//			break;
//
//		case(animState::anim_Run):
//			cout << "Player state: Running." << endl;
//			break;
//
//		case(animState::anim_Shoot):
//			cout << "Player state: Shooting" << endl;
//			break;
//
//		default:
//			break;
//	}
//}

