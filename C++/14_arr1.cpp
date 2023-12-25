#include <iostream>
using namespace std;

/*
    Array là tập hợp các biến có cùng data type
    - biến trong mảng được sử dụng để chỉ định 1 phần tử trong mảng
    - Array có size cố định không thể change
    - Array có index bắt đầu từ 0
*/
/*
    Khai báo: data_type <arr name> [];
    Khởi tạo: data_type <arr name> [] = {gt1, gt2, gt3,...}
*/
int main() {
    //1. Khai báo Array
    int Arr[5];
    string Arr1[7];
    //2. Khởi tại Array
    int Arr2[] = {1, 2, 3, 4, 5, 6,7};
    string Arr3[] = {"ngoc", "an", "huong", "huy"};

    //3.Truy xuất các ptu của Array
    cout << Arr2[2] << endl;
    cout << Arr3[3] << endl;
    //4. Check chiều dài Array
    // int Arr4[5] = {1, 3, 5, 6, 8, 9}; // số 5 là chỉ số index của phần tử trong mảng [NOTE]
    int Arr4[] = {1, 3, 5, 6, 8, 9};
    int chieuDai = size(Arr4);
    cout << "Length của Arr4 là: " << chieuDai << endl;

    //5. duyệt Array, để xem
    cout << "Mang Arr5 = ";
    int Arr5[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int pt: Arr5) {
        cout  << pt << " ";
    }
    cout << endl;
    //6. duyệt Array theo vị trí index
    for (int i=0; i < size(Arr5); i++) {
        //in ra vị trí index thứ i
        // cout << "i = " << i << ",\t";
        cout << Arr5[i] << " ";
    }
    cout << endl;
    //7. Thay đổi giá trị cho Array
    //cách 1
    int Arr6[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << "Value Array Arr6 tại vị trí index 0 trước khi đổi: " << Arr6[0] << endl;
    Arr6[0] = 999;
    cout << "Value Array Arr6 tại vị trí index 0 sau khi đổi: " << Arr6[0] << endl;
    //cách 2
    int Arr7[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < size(Arr7); i++) {
        if (i == 7) {
            Arr7[i] += 2; // Arr7[i] = Arr7[i] + 2;
        }
    }
    //Xuất mảng để xem
    cout << "Arr7 sau đổi là: ";
    for (int pt : Arr7) {
        cout << pt << " ";
    }

}