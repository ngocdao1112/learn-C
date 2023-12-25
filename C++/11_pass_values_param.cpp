#include <iostream>
using namespace std;

void thamTri(int a);
void thamChieu(int &a);

int main () {
    int a = 1;

    cout << "a co dia chi: " << &a << endl; // 0x5ffe9c
    cout <<"a truoc khi goi ham tham Tri: " << a << endl; // 1
    thamTri (a); // a ban goc
    cout <<"a sau khi goi ham tham Tri: " << a << endl; // 1

    cout << endl;
    cout << endl;

    cout << "a co dia chi: " << &a << endl; // 0x5ffe9c
    cout <<"a truoc khi goi ham tham Chieu: " << a << endl; // 1
    thamChieu (a); // a ban goc
    cout <<"a sau khi goi ham tham Chieu: " << a << endl; // 100

}
void thamTri(int a) {
    a = 100; // a ban sao
    cout << "a trong ham tham Tri la: " << a << endl; //100
    cout << "a co dia chi: " << &a << endl; // 0x5ffe70
}
void thamChieu(int &a) {
    a = 100; //a ban goc
    cout << "a trong ham tham Chieu la: " << a << endl; //100
    cout << "a co dia chi: " << &a << endl; // 0x5ffe9c

}

