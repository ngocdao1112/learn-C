#include <iostream>
using namespace std;

int tong(int x, int y=0) {
    return x + y;
}

int main() {
    //goi ham tinh tong
    int kq1 = tong(9);
    cout << "Kq1 = " << kq1 << endl;

    int kq2 = tong(9, 5);
    cout << "Kq2 = " << kq2 << endl;

}