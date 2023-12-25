#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

int main() {
/*
    1. Viết ctrinh tạo 1 mảng 2 chiều có kích thước 4 dòng, 6 cột [4][6].
    Các ptu là số nguyên được tạo ra ngẫu nhiên
    2. Xuất các giá trị trong mảng
    3. Tìm số lớn nhất trong mảng. Xuất gtri số đó
    4. Tìm số nhỏ nhất trong mảng. Xuất gtri số đó
    5. Tính tổng các ptu trong mảng. Xuất ra kq
    6. Cho user nhập vào 1 số bất kỳ, check xem số đó có tồn tại trong mảng hay không,
    nếu có thì bao nhiêu số? 
*/
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0, 9);

    const int row = 4;
    const int col = 6;
//tao mang 2 chieu
    int Mang1[row][col];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            Mang1[i][j] = dis(gen);
        }
        // cout << Mang1[i][j] << endl;
    }
//2. xuat mang
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << Mang1[i][j] << " ";
        }
        cout << endl;
    }
//3. Tìm số lớn nhất trong mảng. Xuất gtri số đó
    int maxNumber= Mang1[0][0];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(Mang1[i][j] > maxNumber) {
                maxNumber = Mang1[i][j];
            }
        }
    }
    cout << "So lon nhat trong mang la: " << maxNumber;
    cout << endl;
//4. Tìm số nhỏ nhất trong mảng. Xuất gtri số đó
    int minNumber = Mang1[0][0];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(Mang1[i][j] < minNumber) {
                minNumber = Mang1[i][j];
            }
        }
    }
    cout << "So nho nhat trong mang la: " << minNumber;
    cout << endl;
//5. Tính tổng các ptu trong mảng. Xuất ra kq
    int sum = 0;
    for(int i = 0; i < row ; i++) {
        for(int j = 0; j < col; j++) {
            sum += Mang1[i][j];
        }
    }
    cout << "sum =  " << sum;
    cout << endl;
//6. Cho user nhập vào 1 số bất kỳ, check xem số đó có tồn tại trong mảng hay không,
//  nếu có thì bao nhiêu số?
    int nhapSo;
    cout << "Nhap so: ";
    cin >> nhapSo;
    int dem = 0;
    for(int i = 0; i < row ; i++) {
        for(int j = 0; j < col; j++) {
            if(Mang1[i][j] == nhapSo) {
                dem++;
            }
        }
    }
    if (dem > 0){
        cout << "So " << nhapSo << " ton tai trong mang va xuat hien " << dem << " lan";
    }
    else   
        cout << "So " << nhapSo << " khong ton tai trong mang";

}