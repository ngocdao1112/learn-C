#include <iostream>
#include <cmath>
using namespace std;

/*int Cong(int x, int y); //khai báo
int Hieu(int x, int y);
void XinChao(string gioiTinh);

int main()
{
    int kq = Cong(7, 5);
    int kq2 = Hieu(12, 9);
    
    cout << "kq = " << kq << endl;
    cout << "kq2 = " << kq2 << endl;

    XinChao("nu");
    XinChao("nam");
}
//định nghĩa
int Cong(int x, int y) {
    return x + y;
}
int Hieu(int x, int y) {
    return x - y;
}

void XinChao(string gioiTinh) {
    if (gioiTinh == "nu")
        cout << "Xin chao, toi la nhan vien nu! \n";
    else if (gioiTinh == "nam")
        cout << "Xin chao, toi la nhan vien nam!"; 
} */

/*void GiaiPTB2(double a, double b, double c);

int main() {
    GiaiPTB2(1, 2, 3);
    GiaiPTB2(1, 2, 1);
    GiaiPTB2(1, 2, -3);
    //nhap a, b, c
    double x, y, z;
    cout << "Nhap x: " << endl;
    cin >> x;
    cout << "Nhap y: " << endl;
    cin >> y;
    cout << "Nhap z: " << endl;
    cin >> z;
    GiaiPTB2 (x, y ,z);

}
void GiaiPTB2(double a, double b, double c)
{
    int x1, x2;
    double delta = (b*b) - (4*a*c); 

    if(delta > 0) {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        cout << "PT co 2 nghiem: " << endl;
        cout << "\t x1 = " << x1 << endl;
        cout << "\t x2 = " << x2 << endl;

    }
    else if (delta == 0) {
        x1 = -b/(2*a);
        cout << "PT co nghiem kep x1 = x2 = " << x1 << endl;
    }
    else
        cout << "PT vo nghiem" << endl;
} */

/*
    Viet ctrinh nhap a, b.
    Dung Function:
    1. Neu nhap +, tinh a + b va in ra kq
    2. Neu nhap -, tinh a - b va in ra kq
    3. Neu nhap *, tinh a * b va in ra kq
    4. Neu nhap /, tinh a / b va in ra kq
*/

int Cong(int a, int b);
int Tru(int a, int b);
double Nhan(int a, int b);
double Chia(int a, int b);

int main() {
    // int a, b; 

    // int kq1 = Cong(a, b); // int kq1 = 2
    // cout << "a + b = " << kq1 << endl;

    // int kq2 = Tru(a, b);
    // cout << "a - b = " << kq2 << endl;

    // double kq3 = Nhan(a, b);
    // cout << "a * b = " << kq3 << endl;

    // double kq4 = Chia(a, b);
    // cout << "a / b = " << kq4 << endl;

    int option;
    do
    {
        int a, b;
        cout << "Nhap a: " << endl;
        cin >> a;
        cout << "Nhap b: " << endl;
        cin >> b;
        cout << "0. Thoat \n";
        cout << "1. Thuc hien phep + \n";
        cout << "2. Thuc hien phep - \n";
        cout << "3. Thuc hien phep * \n";
        cout << "4. Thuc hien phep / \n";
        cout << "Nhap vao lua chon: ";
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "a + b = " << Cong(a, b) << endl;
            break;
        case 2:
            cout << "a - b = " << Tru(a, b) << endl;
            break;
        case 3:
            cout << "a * b = " << Nhan(a, b) << endl;
            break;
        case 4:
            if (b == 0) {
                cout << "0 khong chia duoc!" << endl;
                continue;
            }
            else
                cout << "a / b = " << Chia(a, b) << endl;
            break;
        default:
            cout << "Nhap sai!" << endl;
            break;
        }

    } 
    while (option != 0);

}
int Cong(int a, int b) {
    return a + b; //return 2
}
int Tru(int a, int b) {
    return a - b;
}
double Nhan(int a, int b) {
    return a * b;
}
double Chia(int a, int b) {
    return a / b;
}

