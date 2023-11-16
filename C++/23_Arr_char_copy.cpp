#include <iostream>
#include <cstring>
using namespace std;

int main() {
    //sao chép mảng ký tự
    char chuoi1[] = "Dao Tien Ngoc";
    char chuoi2[20];
    strcpy_s(chuoi2, sizeof(chuoi2), chuoi1);
    cout << "chuoi 1 : " << chuoi1 << endl;
    cout << "chuoi 2 : " << chuoi2 << endl; 

    //sao chép n ký tự
    char chuoi3[] = "123456";
    char chuoi4[20];
    strncpy_s(chuoi4, sizeof(chuoi4), chuoi3, 4);
    cout << "chuoi 3 : " << chuoi3 << endl;
    cout << "chuoi 4 : " << chuoi4 << endl;


}
