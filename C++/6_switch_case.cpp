#include <iostream>
using namespace std;

int main()
{   //check chan le
/*    int n;
    cout << "Nhap n: ";
    cin >> n;
    int div = n%2;
    switch (div)
    {
        case 0:
            cout << n << "n la so chan";
            break;
        default:
            cout << n << "n la so le";
            break;
    } */

/*
Viet ctrinh khung tim kiem: cho user nhập vào lựa chọn
    1. tìm theo tên
    2. tìm theo tác giả
    3. tìm theo nhà xuất bản
    4. tìm theo tiêu đề
    Thoát nếu bấm phím invalid
    */
    int choice;
    cout << "Moi bam so de chon: " << endl;

    cout << "1. Tìm theo tên" << endl;
    cout << "2. Tìm theo tác giả" << endl;
    cout << "3. Tìm theo nhà xuất bản" << endl;
    cout << "4. Tìm theo tiêu đề" << endl;
    cin >> choice;

   switch (choice) 
   {
    case 1:
        cout << "Tìm theo tên" << endl;
        break;
    case 2:
        cout << "Tìm theo tác giả" << endl;
        break;
    case 3:
        cout << "Tìm theo nhà xuất bản" << endl;
        break;
    case 4:
        cout << "Tìm theo tiêu đề" << endl;
        break;
    default:
        cout << "bấm phím invalid!";
        break;
   }

}