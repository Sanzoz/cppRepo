#include <iostream>
#include <string>

#include "Car.h" // <-- include class header file

using namespace std;

int main(){
    // use pointer '*' for create instance of class
    Car* Lamborghini = new Car();
    Car* Ford = new Car();
    Car* Truck = new Car(245);
    //Car* Truck = new Car("Hammer", 245);
    // use '->' to access public variables and methods
    Lamborghini->id = 44;
    Lamborghini->speed = 320;
    Lamborghini->model = "Huracan";

    Lamborghini->Drive("Rome");
    cout << " Speed: " << Lamborghini->GetSpeed();

    cout << " \n\n\n"; // /////////////////////////////////////////

    Ford->id = 24;
    Ford->speed = 65;
    Ford->model = "MODEL T";

    Ford->Drive("NY");
    cout << " Speed: " << Ford->GetSpeed();

    // -- B
    string player_input_01 = "";
    int player_input_02 = 0;

    while (player_input_01 != "quit") {
        cout << "\n  ++ Please enter your option: 1) manager 2)customer " << endl;
        cin >> player_input_01;

        if (player_input_01 == "1") {
            cout << "  --- ++ Wellcome manager. Please enter security Code:  " << endl;
            cin >> player_input_02;
            Lamborghini->TurnOn(player_input_02);// save code in object
        }

        if (player_input_01 == "2") {
            cout << "  --- ++ Good day! Please enter your code:  " << endl;
            cin >> player_input_02;
            if (Lamborghini->ValidateDriver(player_input_02)) Lamborghini->Drive("Milan"); // check code and activate object
            else cout << "  +++++++ Access Denied!  " << endl;
        }
    }

    cout << " \n\n--- end of code ---  " << endl;

    // delete pointer <--- must do in C++!
    delete Lamborghini;
    Lamborghini = nullptr;
    delete Ford;
    Ford = nullptr;

    delete Truck;
    Truck = nullptr;
}

