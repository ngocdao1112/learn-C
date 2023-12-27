#include <iostream>
using namespace std;
//print all natural numbers in reverse order

int main() {
    int num=0, i;
    cout << "Enter any number: ";
    cin >> num;

    for(int i=num; i >= 1; i--) {
        cout << i << ' ';
    }

    return 0;
}