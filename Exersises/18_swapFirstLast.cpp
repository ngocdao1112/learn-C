#include <iostream>
#include <math.h>
using namespace std;
//swap first and last digit of a number 

int main() {
    int num, last, first, temp, swap, count = 0;
    cout << "Enter any number: ";
    cin >> num;

    temp = num;
    last = temp % 10;

    // Đếm số lượng chữ số
    while (temp > 0) {
        temp /= 10;
        count++;
    }

    temp = num;
    first = temp / pow(10, count - 1);

    // Đảo chữ số đầu và chữ số cuối
    swap = last * pow(10, count - 1) + num % (int)pow(10, count - 1) - last + first;
    
    cout << "Last digit: " << last << '\n';
    cout << "First digit: " << first << '\n';
    cout << num << " is swapped to " << swap;

    return 0;
}
