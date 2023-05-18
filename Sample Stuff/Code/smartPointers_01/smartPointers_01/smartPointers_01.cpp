
#include <iostream>
#include <string>
#include<memory> // <-- include when use smart pointers
using namespace std;

class item_TypeA {
public:
    string Item_name = "";
    item_TypeA() {
        cout << "   ++ con>> ---- " << endl;
    }
    item_TypeA(string name) {
        Item_name = name;
        cout << "   +x con-ov>> --- " << endl;
    }
    ~item_TypeA() {
        cout << "             %% des>> x x x  " << endl;
    }

    void printName() {
        if (Item_name != "")    cout << "  +++ item name: " << Item_name << endl;
        else                    cout << "  +++ no name    " << endl;
    }
};

void checkPointer_00() {
    unique_ptr<item_TypeA> item_0a(new item_TypeA());
    unique_ptr<item_TypeA> item_0b(new item_TypeA(" silver block "));
    unique_ptr<item_TypeA> item_0c = make_unique<item_TypeA>(" iron block ");

    item_0a->printName();
    item_0b->printName();
    item_0c->printName();
}

unique_ptr<item_TypeA> checkPointer_unique() {
    unique_ptr<item_TypeA> item_01(new item_TypeA());
    //unique_ptr<item_TypeA> item_01(new item_TypeA(" gold block "));
    
    item_01->printName();
    return item_01;
};

void checkPointer_share() {
    cout << "\n";
    // ----- assign one raw pointer to multiple owners
    shared_ptr<item_TypeA> share_0 = make_shared<item_TypeA>(" silver block ");
    //{ // A -- 
    shared_ptr<item_TypeA> share_1 = share_0;
    shared_ptr<item_TypeA> share_2 = share_0;
    // B -- 
    // shared_ptr<item_TypeA> sh_3 = sh_1; // <-- ok
    //} // sh_1 and sh_2 will be automaticaly destroyed after end of scope

    cout << " A---share_0 " << share_0.use_count() << endl;
    cout << " A---share_1 " << share_1.use_count() << endl;
    cout << " A---share_2 " << share_2.use_count() << endl;
    cout << "\n";
    
    share_0 = nullptr;
    cout << " B---share_0 " << share_0.use_count() << endl;
    cout << " B---share_1 " << share_1.use_count() << endl;
    cout << " B---share_2 " << share_2.use_count() << endl;
    cout << "\n";
    
    share_1 = nullptr;
    cout << " C---share_0 " << share_0.use_count() << endl;
    cout << " C---share_1 " << share_1.use_count() << endl;
    cout << " C---share_2 " << share_2.use_count() << endl;
};

void checkPointer_weak() {

    // provides access to an object that is owned by one or more shared_ptr instances, but does not 
    // participate in reference counting. 
    // B --    
    shared_ptr<item_TypeA> sh_0 = make_shared<item_TypeA>(" silver block ");
    //weak_ptr<item_TypeA> wk_0 = make_shared<item_TypeA>(" Gold block "); // <-- not working
    weak_ptr<item_TypeA> wk_0 = sh_0; // works fine
    // weak_ptr<item_TypeA> wk_2 = wk_0; // <-- ok 

    if (auto w = wk_0.lock()) { // use expired() or lock() to determine if weak_ptr is valid
        w->printName();
        cout << "   --- -------------  ";
    } else {
        cout << "   --- weak_ptr not defined.";
    }

    cout << "\n A---sh_0 " << sh_0.use_count() << endl;
    sh_0 = nullptr;
    cout << "\n B---sh_0 " << sh_0.use_count() << endl;

};



int main() {

    // review default pointer
    // variables save data , pointers save address // <-- only rule
    // variables save data , pointers save address as an iteger //
    
    int value = 54; // save 54 integer number in "value" 
    cout << "  Value        : " << value <<endl;
    cout << "  Value address: " << &value <<endl;

    int* PT = &value; // save address of "value" in PT integer pointer
    cout << "  PT           : " << PT << endl;
    cout << "  PT points to : " << *PT << endl; 
    cout << " \n";

    *PT = 74; // <-- change the value at that address
    cout << "       PT           : " << PT << endl;
    cout << "       PT points to : " << *PT << endl; // de-reference pointer
    // magic is here !
    cout << "       Value        : " << value << endl;

    
    // ---- Allows exactly "one" owner of the underlying pointer.     
    // ----- A 
    //unique_ptr<item_TypeA> u_01(new item_TypeA());
    ////unique_ptr<item_TypeA> u_01= make_unique<item_TypeA>(); // <-- better approache
    //u_01->printName();
    ////unique_ptr<item_TypeA> u_02 = u_01; // <-- not possible
    //unique_ptr<item_TypeA> u_02 = move(u_01); // <-- "Move" address to u_02
    //// u_01->printName(); // crash --> u_01 is nullptr now
    //u_02->printName(); // ok 
    
    //unique_ptr<string> stA = make_unique<string>("Ace");  
    //cout << " >>>  " << *stA << endl;  

    // ----- B 
    //checkPointer_00();

    // ----- C
    //unique_ptr<item_TypeA> ui = checkPointer_unique();
    //cout << "-- check moved pointer ->> ";  ui->printName();

    // ----- D
    //checkPointer_share();

    // ----- E
    //checkPointer_weak();

    cout << " -- end of code -- " << endl;
}

// https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
// https://aticleworld.com/shared-pointer-in-cpp/  // <-- shared pointer
// https://iamsorush.com/posts/weak-pointer-cpp/
// https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-in-cpp/

// https://www.youtube.com/watch?v=UOB7-B2MfwA&t=559s
// https://www.youtube.com/watch?v=e2LMAgoqY_k 

