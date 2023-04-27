#include <iostream>
#include <string>
using namespace std;

class Car {

public:
    // cons/dest
    Car() {
        cout << "C|  ++ Car constructor  " << endl;
    }
    Car(int val) {
        cout << "C|  ++ Car constructor - overload for id" << endl;
        id = val;
    }
    Car(string st, int val) {
        cout << "C|  ++ Car constructor - overload for name and id" << endl;
        name = st;
        id = val;
    }
    ~Car() {
        cout << "C|  ++ Car destructor " << id << endl;
    }

    // properties
    int id = 0;
    string name = "";
    string model = "";
    int speed = 0;
    int capacity_person = 0;
    int capacity_total = 0;

private:
    int Security_Code = 0;
    bool Security_Code_Validated = false;

    // methods
public:
    void Drive(string destination) {
        cout << "C| destination: " << destination << endl;
        if (Security_Code_Validated) Move(destination);
        else cout << "C| ]] invalid code - please contact management --  " << endl;
    }

    void Stop() {       speed = 0;      }
    int GetSpeed() {    return speed;   }
    void TurnOn(int code) {
        if (Security_Code == 0) Security_Code = code * 10; // generate security number by using code
        else cout << "C| Security code already set.  \n";          
    }

    bool ValidateDriver(int code) {       
        if (Security_Code == code) Security_Code_Validated = true;
        else Security_Code_Validated = false;
        return Security_Code_Validated;
    }

private:
    void Move(string dest) {
        cout << "C| .... ## " << name << " " << model << " is moving to " << dest << endl;
        // animation & sound code
    }

}; // <-- ; at the end


int main() {

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

// https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
// https://www.codementor.io/@supernerdd7/constructor-and-destructor-in-c-1r8kkogm6j
