#include <iostream>
#include <math.h>
using namespace std;

int main()
{
/*    int tong, hieu, x, y;

    cout << "nhap vao tong 2 so: ";
    cin >> tong;
    cout << "nhap vao hieu 2 so: ";
    cin >> hieu;
    // x + y = tong;
    // x - y = hieu;
    // 2x = tong + hieu
    x = (tong + hieu)/2;

    cout << "x = " << x << endl;
    y = tong - x;
    cout << "y = " << y << endl; */

    //Viet ctrinh nhập vào 1 năm dương lịch, kiểm tra năm đó có phải năm nhuận hay k?
    /*Note: năm nhuận là năm
    (chia hết cho 4, và k chia hết cho 100) or (chia hết cho 400)
    =>((nam % 4 == 0) && (nam % 100 != 0)) || (nam % 400 == 0) */

/*    int nam;
    cout << "nhap nam: ";
    cin >> nam;

    if ((nam % 4 == 0) && (nam % 100 != 0)) {
        cout << "la nam nhuan" << endl;
    }
    else {
        cout << "nam khong nhuan" << endl;
    } */

    //viet ctrinh nhâp 1 tháng bấy kỳ từ 1 - 12 => tháng đó có bao nhiu ngày?
/*    int year, months;
    cout << "nhap months: ";
    cin >> months;

    if (months == 2) {
        cout << "nhap year: ";
        cin >> year;
        //check năm nhuận ?
        if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)){
            cout << months << " / " << year << " co 29 days";
        }
        else
            cout << months << " / " << year << " co 28 days";
    }
    else if (months == 4 || months == 6 || months == 9 || months == 11) {
        cout << "Thang " <<  months << " Co 30 days";
    }
    else if (months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12) {
        cout << "Thang " <<  months << " Co 31 days";
    }
    else
        cout << "Không phải tháng"; */

//BT: giải pt bậc 2
/*
    ax^2 + bx + c = 0
    1. case1: a=1; b=2; c=-3
        PT co 2 ng: x1 = 1; x2 = -3

    2. case2: a=1; b=2; c=-1
        PT co ng kep x1= x2 = -1

    3. case3: a=1; b=1; c=1
        PT vo nghiem
*/

    double a , b, c, delta, x1, x2;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    delta = pow(b,2) - 4*a*c;

    if ( delta > 0 ) {
        x1 = (-b + sqrt(delta)) /2*a;
        x2 = (-b - sqrt(delta)) /2*a;

        cout << "PT co 2 nghiem x1 = " << x1 <<" & x2 = " << x2 << endl;
    }

    else if ( delta == 0) {
        x1= -b/(2*a); 
        cout << "PT co nghiem kep x1=x2 = " << x1 << endl;
    }

    else
        cout << "PT VO NGHIEM" << endl;



}