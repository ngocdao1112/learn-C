#include <iostream>
#include <string.h>
using namespace std;
//convert a string to a lower case
int main() {
    char string[10];
    cout << "Input a string: ";
    cin.getline(string, 10);
    
    cout << "Convert to lower case: " << strlwr(string);

    return 0;
}
