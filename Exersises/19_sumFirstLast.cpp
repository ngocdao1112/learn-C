#include <iostream>
#include <math.h>
using namespace std;
//sum of the first and last digits of any number
int main() {
    int lastDigit, firstDigit, num, sum=0;
    cout << "Enter any number: "; cin >> num;

    lastDigit = num%10;
    firstDigit = num;

    while (num >= 10)
    {
        num = num/10;
    }
    
    firstDigit = num;
    sum = firstDigit + lastDigit;
    cout << "Sum: " << sum;
    
    return 0;
}