// check whether a character is alphabet, digit or special character
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter any character: ";
    cin >> ch;

    //Alphabet checking condition
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        cout << ch << " = is an alphabet";
    }
    else if(ch > '0' && ch <= '9') {
        cout << ch << " = fis a digit";
    }
    else
        cout << ch << " is a special character";
    return 0;
}