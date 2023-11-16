#include <iostream>
using namespace std;


int main()
{
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            cout << i << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (j == 1 || i == j || j <= i) {
                cout << i << j << " ";
            }
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (j == 1 || j==7 || i==j) {
                cout << i << j << " ";
            }
            else
                cout << " " << " " << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (j == 1 || j == 7 || i==1 || i==7) {
                cout << i << j << " ";
            }
            else
                cout << "**" << "*";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (j == 1 || i == 7 || i == j) {
                cout << i << j << " ";
            }
            else
                cout << "  " << " ";
            }
        cout << endl;
        }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 7; j++) {
            if (i == 4) {
                cout << i << j << " ";
            }
            else if (j == 4-i+1 || j == 4+i-1) {
                cout << i << j << " ";
            }
            else
                cout << "  " << " ";
            }
        cout << endl;
        }
    
    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 7; j++) {
            if (i == 4) {
                cout << i << j << " ";
            }
            else if (j == 4-i+1 || j == 4+i-1) {
                cout << i << j << " ";
            }
            else
                cout << "  " << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (i == 4 || i == j) {
                cout << i << j << " ";
            }
            else if (i <= 4 && j == 1 || i >= 4 && j == 7) {
                cout << i << j << " ";
            } 
            else {
                cout << "  " << " ";
            }
        }
        cout << endl;
    }
}




