#include <iostream>
#include <string.h>
using namespace std;
//count the number of alphabets, digits and special characters in string
#define MAX_SIZE 100
int main() {
    char string[MAX_SIZE];
    int alphabets, digits, specialchars, i;
    alphabets = digits = specialchars = i = 0;

    cout << "Enter a string: "; 
    cin.getline(string, MAX_SIZE);
    // '\0' đại diện cho char null, đánh dấu cuối của một chuỗi ký tự
    while (string[i] != '\0') {
        if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) 
        {
            alphabets++;
        }
        else if (string[i] >='0' && string[i] <= '9')
        {
            digits++;
        }
        else {
            specialchars++;
        }
        i++;
    }
    cout << "Total Alphabets: " << alphabets << endl;
    cout << "Total digits: " << digits << endl;
    cout << "Total specialchars: " << specialchars << endl;

    return 0;
}   