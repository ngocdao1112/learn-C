#include <iostream>
using namespace std;

int main()
{
/*
    1. while
    Viết ctrinh nhập n từ bàn phím
    n phải nằm trong khoảng từ 1 đến 99
    Nhập sai bắt nhập lại
*/
/*   int n;
   cout << "Enter n: ";
   cin >> n;

   while (n <1 || n > 99) {
    cout << "Từ 1 tới 99 thôi: " << endl;
    cin >> n;
   }
   cout << "n = " << n << endl; */

/*
    2. do while
    do 
    {
        <Khoi_lenh_lap_lai>
    }
    while (<dieu_kien_lap_lai>);
*/
    //tính tổng các số từ 1 tới 5
/*    int a;
    int tong = 0;
    do {
        tong += a;
        a++;
    }
    while (a <=5 );
    cout << "tong tu 1 toi 5 la: " << tong << endl; */

    //3. while (true)
    int n = 0;
    while (true)
    {
        cout << "n= " << n << endl;
        n++;
        if (n==10) {
            break;
        }
    }
    


}