#include <iostream>
#include <cstring>
using namespace std;

int main() {
    //strcat_s tự động ngăn ngừa việc tràn bộ nhớ, nên kích cỡ mảng ko đủ để sao chép thì sẽ báo lỗi và không sao chép được!
    char str1[100] = "Hello "; //str1[10] -> false
    char str2[] = "World!";
    strcat_s(str1, str2); // copy str2 vào str1
    cout << "chuỗi sau nối là: \n";
    cout << str1 << endl;

    //copy toàn bộ
    //viết ctrinh nhâp str3, str4
    //thực hiện nối str4 vào str3 và xuất chuỗi sau khi nối ra màn hình
    char str3[100], str4[100];
    cout << "Nhap str3: ";
    cin.getline(str3, 100);

    cout << "Nhap str4: ";
    cin.getline(str4, 100);
    //nối str4 vào str3
    strcat_s(str3, str4); // nối str4 vào str3
    cout << "Chuỗi sau nối là: \n";
    cout << str3 << endl;

    //copy n ký tự vào chuỗi đích
    char str5[100] = "Hello, ";
    char str6[] = "World!";
    strncat_s(str5, sizeof(str5), str6, 3); // copy chuoi6 vao chuoi5 va lay 3 ky tu, 
                                            // check xem kich cỡ tối đa của chuoi5 có đủ lưu trữ sau copy không
    cout << str5 << endl;

}