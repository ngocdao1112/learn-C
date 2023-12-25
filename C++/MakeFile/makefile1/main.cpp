#include <iostream>
using namespace std;

#include "functions.h"

int main(){
    print_hello();
    cout << endl;
    cout << "The factorial of 5 is " << factorial(5) << endl;

    cin.get();
    return 0;
}

// cd C_C++/C++/MakeFile/makefile1
// g++ -o myprogram factorial.cpp hello.cpp main.cpp