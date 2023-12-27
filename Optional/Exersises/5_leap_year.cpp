//check leap year using conditional Operator
//chia hết cho 4 và không chia hết cho 100
//a%b == 0 or a%b != 0
#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter any year: ";
    cin >> year;

    (year % 4 == 0 && year % 100 != 0) ? cout << year << " is leep year" :
        (year % 400 == 0) ? cout << year << " is LEEP YEAR" : cout << year << " is not leep year";
    // 1600 chia hết cho 4 nhưng ko chia hết cho 100
    // xét tiếp thì 1600 chia hết cho 400 vậy
    // 1600 is LEEP YEAR
    return 0;
}