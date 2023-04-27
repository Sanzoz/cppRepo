#include <iostream>
using namespace std;

int main(){
	
	// A ///////////////////////////////// 
	//cout << " ---------- const---------- " << endl;
	//int Player_damage = 0;
	//int EnemyBoss_health = 10000;
	//bool isEnemyAlive = true;
	//bool securePrint = true;

	//const int MAX_COUNT = 16;
	////cin >> MAX_COUNT; // <-- conversion error
	//
	////int userInput = 0;
	////cin >> userInput; // get user input
	////const int MAX_COUNT_NEW = userInput + MAX_COUNT; // <---  make a const from a max number and userinput

	//cout << " ---------- loop 01---------- " << endl;

	//for (int i = 0; i < MAX_COUNT; i++) { // forward loop
	//	if (i < 5) {
	//		cout << "loop A >> condition A  ## " << i << " \n";
	//		continue; // <-- continue runing code 
	//		//break; // <-- break the rest and return to "for"
	//	}

	//	if ((i > 5) && (i < 10)) {
	//		cout << "loop A  >>> condition B ##         " << i << endl;
	//	}
	//	if ((i > 10)) {
	//		cout << "loop A  >>> condition C ##  " << i * 100 << endl;
	//	}
	//}
	//cout << " \n \n";
	//for (int i = MAX_COUNT; i > 0; i--) { // backward loop
	//	if (i < 5) { cout << "loop B - \n"; continue; }
	//	if ((i > 5) && (i < 10)) { cout << "  loop B <<<        " << i << endl; }
	//	if ((i > 10)) {	cout << "  loop B <<< " << i * 100 << endl; }
	//}

	// B ///////////////////////////////////
	cout << " ---------- loop 02---------- " << endl;
	string player_fiction_01 = "";
	string player_name_01 = "";
	int player_gold_01 = 0;


	cout << "  ++ Please enter fiction name:  " << endl;
	cin >> player_fiction_01;

	while ((player_fiction_01 == "Orc") || (player_fiction_01 == "orc")) {
		cout << "  ++ enter gold:  " << endl;
		cin >> player_gold_01;
		cout << "  ++ enter name:  " << endl;
		cin >> player_name_01;
		//if (player_gold_01 < 0) break; //<-- break the loop
		if (player_gold_01 > 10) {
			cout << player_name_01 << " can enter the castle." << endl;
			cout << " we need all your golds! " << endl;
			player_gold_01 = 0;
		} else {
			cout << player_name_01 << " sorry!, get more gold." << endl;
		}
	}

	int Player_damage = 0;
	int EnemyBoss_health = 10000;
	bool isEnemyAlive = true;

	do {
		cout << "  ++ enter Player_damage:  " << endl;
		cin >> Player_damage;

		// if (Player_damage > EnemyBoss_health) break; //<-- break the loop
		EnemyBoss_health = EnemyBoss_health - Player_damage; // EnemyBoss_health -= Player_damage; // <-same
		if (EnemyBoss_health > 0) {
			cout << EnemyBoss_health << " enemy health." << endl;
		} else {
			isEnemyAlive = false;
			cout << " =-- enemy boss destroyed --= " << endl;
		}
	} while (isEnemyAlive);


	// C ///////////////
	//cout << " ---------- const again!---------- " << endl;
	//const int KL1 = 5;
	////const int KL2; //<-- MUST de decalred

	//// 02
	//int UR = 24;
	//UR = 84; // <-- no problem

	//// 03
	//const int UL = 24;
	////UL = 84; // <-- problem, const variables can NOT change.

	//// 04
	//const int maxHealth = 600; //<-- not good naming for const variables
	//const int MAX_HEALTH = 600; //<-- proper good naming for const variables

	//// 05

	//int val01 = 0;
	//const int res_01 = val01 + 1; //<-- ok

	//int val02 = 0;
	////constexpr int val02 = 0;
	////constexpr int res_02 = val02 + 1; //<-- <-- error val02 is not a constexpr

	//const int val03 = 0;
	//constexpr int res_03 = val03 + 1; //<-- ok

	// https://learn.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=msvc-170
	// https://www.youtube.com/watch?v=4fJBrditnJU

	cout << "\n --------- end of code ------------ " << endl;

}
