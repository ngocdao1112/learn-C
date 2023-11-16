#include <iostream>
#include <cstring>
using namespace std;

int main() {
    /*
        1. tìm ký tự trong mảng
        strchr(<mang char>, 'ký tự cần tìm')
        - Trả về con trỏ trỏ đến vị trí ký tự đầu tiên mà nó tìm thấy
        - Nếu không tìm thấy trả về NULL
    */

   char *thuTu, kyTuX;
   char str1[100] = "tuhoc.cc";
   kyTuX = 'c';
   //tìm kyTuX trong chuỗi str7
   //Trả về con trỏ trỏ đến vị trí ký tự đầu tiên mà nó tìm thấy
   //nếu không có ký tự trong mảng sẽ trả về null
    thuTu = strchr(str1, kyTuX); //tim kyTuX trong str1
    if (thuTu == NULL)
        cout << "Khong tim thay";
    else
        cout << "Tim thay tai vi tri index: " << (thuTu - str1) << "\n";

    /* 
        2. tìm chuỗi trong mảng
        strstr(<chuỗi gốc>, <chuỗi cần tìm>)
        - Trả về con trỏ trỏ đến vị trí chuỗi đầu tiên mà nó tìm thấy
        - Nếu không tìm thấy trả về NULL
    */

    char *thuTu2;
    char str2[100] = "Toi tuhoc tại tuhoc.cc";

    thuTu2 = strstr(str2, "tuhoc"); // tìm tuhoc trong str8

    if(thuTu2 == NULL) 
        cout << "Khong tim thay";
    else
        cout << "Tim thay tai vi tri index: " << (thuTu2 - str2);

}
