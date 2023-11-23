#include <iostream>
#include <cstring>
using namespace std;

int main() {
    /*
        strcmp(<str1>, <str2>) - so sánh theo bảng mã ASII, có phân biệt hoa thường
        - Trả về 0 nếu str1 = str2
        - Trả về 1 nếu str1 > str2
        - Trả về -1 nếu str1 < str2

        strncmp(<str1>, <str2>, n) - so sánh n ký tự
    */

    char str1[] = "Hello";
    char str2[] = "Hello";
    //hàm so sánh string compare
    int kq = strcmp(str1, str2);
    cout << "kq = " << kq << endl;

    char str3[] = "Hello";
    char str4[] = "Hexxxo";
    //hàm so sánh n ký tự string compare
    int kq2 = strncmp(str3, str4, 2); // chỉ compare 2 ký tự
    cout << "kq2 = "<< kq2 << endl;

}