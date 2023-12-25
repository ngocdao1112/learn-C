#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
/*  int r;
    float PI = 3.14f;
    cout << "r = ";
    cin >> r;

    double chuVi = 2*PI*r;
    double dienTich = PI*pow(r,2);

    cout << "chu vi = " << chuVi << endl;
    cout << "dien tich = " << dienTich << endl; */

/*    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "s = a*b = " << a*b << endl;
    cout << "p = (a+b)*2 = " << (a+b)*2 << endl; */

    float toan, van, anh;
    cout << "toan = ";
    cin >> toan;
    cout << "van = ";
    cin >> van;
    cout << "anh = ";
    cin >> anh;

    double dtb = (toan + van + anh) / 3;

    cout << "DTB: " << dtb << endl;
    cout << "Ket qua lam tron: " << setprecision(3) << dtb << endl;


}