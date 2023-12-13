#include <iostream>
#include <random>
using namespace std;

int main() {
    // int a[] = {34, 56, 54, 32, 67, 89, 90, 32, 21};
    // //Original order
    // for (int i=0; i<9; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // //reverse order
    // for (int i=8; i>=0; i--) {
    //     printf("%d ", a[i]);
    // }
    // return 0;

    int ptr[] = {1,2,3,4,5};
    for(int i=0; i<=5; i++) {
        cout << ptr[i] << '\t';
    }
    cout << endl;
    for(int i=5; i>=0; i--) {
        cout << ptr[i] << '\t';
    }
}
