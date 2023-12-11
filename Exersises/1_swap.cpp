#include <iostream>
using namespace std;

int main() {
    int a=5, b=10, temp;
    cout << "Before swap: " << endl;
    cout << "a = " << a << "; b = " << b << endl;

    temp = a; //temp = 5
    a = b; // a = 10
    b = temp; // b = 5

    cout << "After swap: " << endl;
    cout << "a = " << a << "; b = " << b << endl; 

}