#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Support {
public:
    Support(){}
    ~Support(){}


    virtual void GetSupport() = 0; //  pure virtual function <-- this class (Support) is an abstract class
    //virtual void GetSupport() {} 

    void GetService_paid(int fee){ cout << " -- GetService_paid -- $" << fee << endl; }
    void GetService_free(){ cout << " ++ GetService_free ++ " << endl; }
    void GetService_Extra(int fee, int type){ cout << " -- GetService_Extra -- $" << fee << " on type: "<< type << endl; }
    void GetService_follow(int fee, string Helper){ cout << " -- GetService_follow -- $" << fee << " with help of " << Helper << endl; }

    // virtual void GetSupport_Cost() = 0;
};

class EngineerUnit : public Support {
public:
    EngineerUnit() {}
    ~EngineerUnit() {}

    void GetSupport() {} // <-- MUST be implemented

    void CheckUnit(){}
};

class Medical : public Support {
public:
    Medical() {}
    ~Medical() {}

    void GetSupport() {} // <-- MUST be implemented
};

class BankSyetem : public Support {
public:
    BankSyetem(){}
    ~BankSyetem(){}

    void GetSupport() {} // <-- MUST be implemented
};


int main(){

    //  -- A
    //Support s1 = Support(); // <-- error "cannot instantiate abstract class"
    //Support* s1 = new Support(); // <-- error "cannot instantiate abstract class"
    Support* sup_01 = new EngineerUnit(); // <-- ok
    
    sup_01->GetService_free();
    sup_01->GetSupport(); // <-- run inherited GetSupport 
    // sup_01->CheckUnit(); // <-- not working


    //  -- B

    // -----------------map-------------------- // 
    //// <key, element> or <key, data> or <element 1, element 2>
    //map<int, string> ESL_RankBoard; 

    //ESL_RankBoard.insert(pair<int, string>(4, "Outsiders"));
    //ESL_RankBoard.insert(pair<int, string>(3, "G2 Esports"));
    //// .. delay
    //ESL_RankBoard.insert(pair<int, string>(1, "Fnatic"));
    //ESL_RankBoard.insert(pair<int, string>(2, "Cloud9"));

    //
    //for (auto pairValue : ESL_RankBoard) { // <-- automatically sorted by "Key" element 
    //    cout <<"m   " << pairValue.first << " - " << pairValue.second << endl;
    //}

    //cout << "\n";

    //// --------unordered map-------------------- // 

    //unordered_map<int, string> uESL_RankBoard;

    //uESL_RankBoard.insert(pair<int, string>(4, "Outsiders"));
    //uESL_RankBoard.insert(pair<int, string>(3, "G2 Esports"));
    //// .. delay
    //uESL_RankBoard.insert(pair<int, string>(1, "Fnatic"));
    //uESL_RankBoard.insert(pair<int, string>(2, "Cloud9"));


    //for (auto pairValue : uESL_RankBoard) { // <-- no sorting 
    //    cout << " um   " << pairValue.first << " - " << pairValue.second << endl;
    //}

    //cout << "size : " << uESL_RankBoard.size() << endl;


    //cout << "\n";

    //// ------------------------- // 
    //map<string, float> Temp_Summer;

    //Temp_Summer.insert(pair<string, float>("Melborne", 42.18));
    //Temp_Summer.insert(pair<string, float>("Melborne", 22.09));

    //cout << " >>    " << Temp_Summer["Melborne"] << endl; // <-- problem: key MUST be unique

    //map<string, float> Temp_Spring;
    //Temp_Spring.insert(pair<string, float>("Melborne_DEC12", 24.08));
    //Temp_Spring.insert(pair<string, float>("Melborne_DEC10", 22.09));
    //cout << " >>    " << Temp_Spring["Melborne_DEC12"] << endl; // <-- ok
    //
    //Temp_Spring.erase("Melborne_DEC10"); //  delete element from that key
    //cout << " >>    " << Temp_Spring["Melborne_DEC10"] << endl; // 


    cout << " -- end of code -- " << endl;
}


// https://www.youtube.com/watch?v=Ui7Dca5Kbvw
// https://www.youtube.com/watch?v=UWAdd13EfM8
// https://www.youtube.com/watch?v=rECcII1Mdfc
// https://www.programiz.com/cpp-programming/map


// 8 minuts research : https://www.youtube.com/watch?v=Rr1NX1lH3oE Implicit Conversion and the Explicit Keyword in C++