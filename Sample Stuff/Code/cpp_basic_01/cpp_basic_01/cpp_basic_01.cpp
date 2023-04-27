#include <iostream>
using namespace std;

int main(){
	

	//// A ////////////////////////////

	//int value_01 = 2147483647;
	//short int value_02 = 2147483647;
	//long int value_03 = 2147483647;
	//signed int value_04 = -3;
	//unsigned int value_05 = -3;

	//cout << " ajhsdgajhsgdjhasgdjahgsdj" << endl;
	//cout << " ---- value_01 :  " << value_01 << endl; // <-- ok
	//cout << " ---- value_02 :  " << value_02 << endl; // <-- error - short int can map "-32 768" to "32 767"
	//cout << " ---- value_03 :  " << value_03 << endl; // <-- ok
	//cout << " ---- value_04 :  " << value_04 << endl; // <-- ok
	//cout << " ---- value_05 :  " << value_05 << endl; // <-- error - "0" to "4 294 967 295"

	//// fix
	////set “Value_02” to 32767 which is maximum number allowed for “int” using “short modifier
	////set “value_05” to 3, which is a right match for “unsigned” modifier with “int” data type.

	//// int vs long int
	//// https://stackoverflow.com/questions/7456902/long-vs-int-c-c-whats-the-point


	// B ////////////////////////////
	//cout << "\n ......... type casting .......  " << endl;

	//float value_float = 30.6f;
	//cout << "value_float :  " << value_float << endl;
	//int value_01 = value_float; // assign float to int
	//int value_02 = (int)value_float; // cast int from float
	//cout << "value_01 :  " << value_01 << endl;
	//cout << "value_02 :  " << value_02 << endl;
	//value_02 += .2f;
	//cout << "value_02 : I   - " << value_02 << endl; // <-- not working, float values will be removed
	//value_02 += .9f;
	//cout << "value_02 : II  - " << value_02 << endl; // <-- not working, float values will be removed
	//value_02 += 4.9f;
	//cout << "value_02 : III - " << value_02 << endl; // <-- not working correct again, float values will be removed
	//cout << "\n ................  " << endl;

	//int value_int = 74;
	//cout << "value_int :  " << value_int << endl;
	//float value_10 = value_int; // assign int to float
	//float value_11 = (float)value_int; // cast float from int
	//cout << "value_10 :  " << value_10 << endl;
	//cout << "value_11 :  " << value_11 << endl;
	//value_11 += 0.2f;
	//cout << "value_11 :  " << value_11 << endl;

	//// https://cplusplus.com/doc/oldtutorial/typecasting/
	//// https://www.youtube.com/watch?v=TAB86Bt8Xi4
	//// https://www.cprogramming.com/tutorial/lesson11.html

	// C ////////////////////////////
	//cout << "\n .......... input ......  " << endl;

	//string name_Player = "Jane";
	//string name_Enemy = "Zombie_Hunter";

	//cout << " player: " + name_Player << endl;
	//cout << " enemy title: " + name_Enemy << endl; // <-- using +
	//cout << " enemy title: " << name_Enemy << endl; // <-- using <<

	//cout << " \n "<< endl; // <-- next line
	//cout << " --- ";  // <-- no next line without ( << endl )
	//cout << " enemy class: \n" "[" + name_Enemy + "]" << endl; // <-- not safe ( " "[" ) , use ( " + "[" )

	//cout << " \n\n\n ";
	//int Player_ID = 0;
	//cout << "Enter your ID please." << endl;
	//cin >> Player_ID; // <-- input data
	//
	//string Player_name = "";
	//cout << "please enter your name." << endl;
	//cin >> Player_name; // <-- input data

	////cout << " ID: " + Player_ID + " - " + Player_name << endl; // <-- error !
	//cout << " ID: " << Player_ID << " - " << Player_name << endl; // <-- ok 
	
	// D ////////////////////////////
	//cout << "\n .......... branching ......  " << endl;

	//int a = 75;
	//int b = 2;

	//if (a > b) {
	//	cout << " a > b   " << endl;
	//}
	//if (a < b) {
	//	cout << " a less than b   " << endl;
	//}
	//if (a == b) {
	//	cout << " a is equal to b   " << endl;
	//}

	//string name_02 = "";
	//cout << "   01 ++ enter Supreme Commander fraction:  " << endl;
	//cin >> name_02;

	//if (name_02 == "Cybran") {
	//	cout << "  >>>>    Same team ...  " << endl;
	//}
	//else if (name_02 == "UEF") {
	//	cout << "  >>>>    Enemy detected !  " << endl;
	//}
	//else if (name_02 == "Aeon") {
	//	cout << "  >>>>    .. friendly unit.  " << endl;
	//}
	//else {
	//	cout << " unknown >>>> " << name_02 << endl;
	//}

	//int EnemyRank = 0;
	//cout << "\n   ++ enter Enemy Rank (1 - 4):  " << endl;
	//cin >> EnemyRank;

	//switch (EnemyRank) {
	//case 4:
	//	cout << "  xx  Total damage to sheild.\n\n\n";
	//	break;
	//case 3:
	//	cout << "  xx  Serious damage to sheild.\n\n\n";
	//	break;
	//case 2:
	//	cout << "  xx  Sheild disabled for 5 sec, no damage.\n\n\n";
	//	break;
	//case 1:
	//	cout << "  xx  Minor damage to sheild.\n\n\n";
	//	break;
	//default:
	//	cout << "-- no effect --- \n\n\n";
	//}

	//// research: https://stackoverflow.com/questions/650162/why-cant-the-switch-statement-be-applied-to-strings
	//
	////bool Air = true;
	////bool Watre = true;

	////if (Air && Watre) { // AND operator 
	////	cout << "  ++ LIFE is possible ++   " << endl;
	////} else {
	////	cout << "  ++ we need AIR and WATER ++   " << endl;
	////}

	////bool Train = true;
	////bool AirPlane = true;

	////if (Train || AirPlane) { // OR operator 
	////	cout << "  ++ Traveling possible ++   " << endl;
	////	if (Train) { /* train messages */ }
	////	if (AirPlane) { /* plane messages */ }
	////} else {
	////	cout << "  ++ sorry, there is no empty seat ++   " << endl;
	////}
	
	cout << "\n --------- end of code ------------ " << endl;

}



/*
C++ variables short notes:
int: Store integer numbers in 4 bytes without decimals, between -2,147,483,648 to 2,147,483,647.
float: Store floating point numbers with decimals in 4 bytes, such as 1.618 or -1.618.
char: Store single characters, such as 'n' or 'M, it hold 8 bits in memory which stores
and encoded character and mostly used ASCII standard encoding scheme.

string: Store text data.
bool: Takes "one byte" in memory of value of true as 1 or false as 0.
// https://stackoverflow.com/questions/19351483/how-is-a-bool-represented-in-memory

C++ Modifiers:
singed: Include the “sign” of the variable.
unsinged: Remove the “sign” of the variable.
short: Use 2 bytes in memory to store data belong to variable.
long: Use 4 bytes in memory to store data belong to variable.
long long: Use 8 bytes in memory to store data belong to variable.

*/

/*
 Supreme Commander
 https://en.wikipedia.org/wiki/Supreme_Commander_(video_game)
 https://en.wikipedia.org/wiki/Supreme_Commander:_Forged_Alliance
 Community
 https://www.faforever.com/
*/