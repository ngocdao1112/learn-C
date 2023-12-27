// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/* KHÁC NHAU GIỮA VECTOR & ARRAY
- Vector: Tự quản lý bộ nhớ (giống dynamic array nhưng vector tự giải phóng memory còn array thì phải delete manual)
- Các ptu vector đc đặt trong contiguous(bộ nhớ liền kề) để chúng có thể đc access và duyệt qua bằng cách sd iterator
    #include <vector>

    int main() {
        // Khởi tạo vector và thêm phần tử
        std::vector<int> dynamicVector;
        dynamicVector.push_back(1);
        dynamicVector.push_back(2);
        dynamicVector.push_back(3);

        // Vector tự động quản lý bộ nhớ khi thêm phần tử mới
        // và tự giải phóng bộ nhớ khi vector bị hủy

        return 0;
    }

- Array: Bạn phải quản lý bộ nhớ thủ công
    int main() {
        // Khởi tạo mảng và cấp phát động bộ nhớ
        int* dynamicArray = new int[3];
        
        // Thêm phần tử vào mảng
        dynamicArray[0] = 1;
        dynamicArray[1] = 2;
        dynamicArray[2] = 3;

        // Bạn phải giải phóng bộ nhớ một cách thủ công khi không cần sử dụng nữa
        delete[] dynamicArray;

        return 0;
    }

*/

int main() {
    // vector<data type> name_vector;
    
    return 0;
}