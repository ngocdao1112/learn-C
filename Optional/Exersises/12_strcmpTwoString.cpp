#include <iostream>
#include <string.h>
using namespace std;
//compare two strings using strcmp

int main() {
    char string1[100], string2[100];
    cout << "Enter 1st string: ";
    cin >> string1;
    cout << "Enter 2nd string: ";
    cin >> string2;

    if(strcmp(string1, string2) == 0) {
        cout << "Entered string are equal" << '\n';
    }
    else
        cout << "Entered string are not equal" << '\n';

    return 0;
}