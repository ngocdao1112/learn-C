#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int>unPtr1 = make_unique<int>(25);
    unique_ptr<int>unPtr2 = move(unPtr1);
    // cout << *unPtr2 << endl;
    // cout << *unPtr1 << endl; //null pointer vì đã move to ptr2
    //check xem unPtr1 có trống không
    if(unPtr1.get() == nullptr) {
        cout << "unPtr1 is null" << endl;
    }
    else {
        cout << *unPtr1 << endl;
    }
    if(unPtr2.get() != nullptr)
        cout << *unPtr2 << endl;
    
    return 0;
    cin.get();
}