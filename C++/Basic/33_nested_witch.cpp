#include <iostream>
using namespace std;

int main() {
    int outerChoice, innerChoice;

    cout << "Select an option for the outer switch (1 or 2): ";
    cin >> outerChoice;

    switch (outerChoice) {
        case 1:
            cout << "You selected option 1. Now select an option for the inner switch (1 or 2): ";
            cin >> innerChoice;

            switch (innerChoice) {
                case 1:
                    cout << "You selected inner option 1.\n";
                    break;
                case 2:
                    cout << "You selected inner option 2.\n";
                    break;
                default:
                    cout << "Invalid inner choice.\n";
            }
            break;

        case 2:
            cout << "You selected option 2.\n";
            break;

        default:
            cout << "Invalid outer choice.\n";
    }

    return 0;
}
