/*
• An exception is an unexpected problem that arises during the execution of a program.
• Exception handling mechanism provide a way to transfer control from one part of a program to another. This makes it easy to separate the error handling code from the code written to handle the actual functionality of the program.
• C++ exception handling is built upon three keywords: try, catch, & throw.

- try: A block of code which may cause an exception is typically placed inside the try block. It's followed by one or more catch blocks. If an exception occurs, it is thrown from the try block.
- catch: this block catches the exception thrown from the try block. Code to handle the exception is written inside this catch block.
- throw: A program throws an exception when a problem shows up. This is done using a throw keyword.
- Every try catch should have a corresponding catch block. A single try block can have multiple catch blocks.
*/

#include <iostream>
using namespace std;

    // int main() {
    //     int numberator, denominator;
    //     cout << "Enter numberator and denominator: " << endl;
    //     cin >> numberator >> denominator;

    //     int result = numberator/denominator;
    //     cout << "Division is: " << result;

    //     //nếu 5/0 sẽ bị lỗi => exception

    //     return 0;
    // }

    int main() {
    int numberator, denominator, result;
    cout << "Enter numberator and denominator: " << endl;
    cin >> numberator >> denominator;
    try {
        if(denominator == 0) {
            throw denominator;
        }
        int result = numberator/denominator; //devision happens here
    }
    catch(int ex) {
        cout << "Exception: Divide by zero not allowed - " << ex << '\n';
    }
    cout << "Division is: " << result;

    //nếu 5/0 sẽ bị lỗi => exception

    return 0;
    }