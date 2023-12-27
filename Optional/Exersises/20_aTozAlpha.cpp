#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int character = 0;
    char ch = 'A';

    do {
        character = int(ch);
        cout << ch << " ";

        ch = char(character);
    }
    while (ch <= 'Z');
    
    return 0;
}