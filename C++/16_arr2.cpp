#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main() {
/*
    Mảng 2 chiều (matrix) là tập hợp của nhiều mảng 1 chiều có cùng kích thước
    Khởi tạo: data_type <tên mảng> [rows][columns];
*/
    //1. khởi tạo mảng 2 chiều
    int mang1[3][4];
    string mang2[3][3];
    double mang3[5][4];

    //2. khởi tạo và gán giá trị
    const int row = 3;
    const int col = 4;
    int mang4[row][col] = {
        {1, 5, 4, 7}, // [0][0], [0][1], [0][2], [0][3]
        {4, 7, 9, 8}, // [1][0], [1][1], [1][2], [1][3]
        {5, 8, 4, 7}  // [2][0], [2][1], [2][2], [2][3]
        };

    //3. xuất mảng
    for (int i= 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mang4[i][j] << " ";
        }
        cout << endl;
    }
    // cout << mang4[2][1] << endl;
    //4. gán giá trị trực tiếp
    mang4[2][1] = 10;
    mang4[1][3] = 10;
    cout << "Mảng sau khi gán là: " << endl;
    for (int i= 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mang4[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //5. Tạo mảng 2 chiều ngẫu nhiên
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);

    //tạo mảng có row dòng và col cột
    int mang5[row][col];
    for (int i= 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            mang5[i][j] = dis(gen);
        }
        // cout << endl;
    }
    //xuất mảng
    for (int i= 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mang5[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    //6. Tạo mảng với các phần tử được nhập từ user
    int Mang6[row][col];
    //duyệt từng ptu của mảng và cho phép nhập từ bàn phím
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Mang6[" << i << "][" << j << "]= ";
            cin >> Mang6[i][j];
        }
        cout << endl;
    }
    //xuất mảng sau khi nhập
    cout << "\nMang ban vua nhap la:  " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << Mang6[i][j] << "\t";
        }
        cout << endl;
    }
    //xuất dòng muốn xem
    int dong;
    cout << "Nhap row muon xem: ";
    cin >> dong;
    for (int j = 0; j < col; j++) {
        cout << Mang6[dong][j] << " ";
    }
    cout << endl;
    //xuất cột muốn xem
    int cot;
    cout << "\nNhap col muon xem: ";
    cin >> cot;
    for (int i = 0; i < row; i++) {
        cout << Mang6[i][cot] << endl;
    }

}