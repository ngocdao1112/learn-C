#include <iostream>
#include <random>
using namespace std;

/*  //1.
    1. Viết hàm (function) hoán vị 2 biến a, b là số thực bằng cách sử dụng con trỏ
    2. viết ctrinh nhập 2 số thực a, b. Sử dụng hàm trên để đổi chỗ a, b
*/

/*    //hàm hoán đổi 2 biến a, b nhưng sử dụng con trỏ
    void hoanDoi(double *a, double *b) {
        double temp = *a; //biến tạm = giá trị của a
        *a = *b; //gán giá trị a = giá trị nằm trên ô nhớ b
        *b = temp; // gán giá trị b = temp
    }

    int main() {
        double a, b;
        cout << "Nhap a: ";
        cin >> a;
        cout << "Nhap b: ";
        cin >> b;
        //goi hàm hoán đổi
        hoanDoi(&a, &b);
        cout << "Sau hoán đổi a= " << a << " và giá trị b= " << b << endl;

    } 
*/

/*
    //2.
    1. Viết ctrinh nhập vào mảng 1 chiều M, gồm n phần tử nguyên ngẫu nhiên [0, 100]
    2. Sắp xếp mảnh M theo chiều giảm dần.
    Note: Yêu cầu sử dụng tên mảng như con trỏ và sử dụng con trỏ
*/
    void Nhap(int *&M, int n);
    void Xuat(int *&M, int n);
    void hoanDoi(int *&M, int n);
    void sapXep(int *&M, int n);
    void hoanDoi_v1(int,int);
    void hoanDoi_v2(int*,int*);

    int main() {
        // //khai báo con trỏ
        int *M;
        int n = 10;
        // //gọi hàm nhập mảng
        Nhap(M, n);
        cout << "Mảng ngẫu nhiên vừa tạo ra là: \n";
        // Xuat(M, n);
        // cout << "" << endl;
        // sapXep(M ,n);

        // cout << "Mảng ngẫu nhiên vừa tạo ra là: \n";
        // Xuat(M, n);

        int a = 1;
        int b = 2;
        hoanDoi_v2(&a, &b);
        cout<<"a : "<<a;
        cout<<"b : "<<b;

    }

    //1. hàm nhập mảng
    //cần thêm dấu & vì có change giá trị của biến sau khi thoát hàm
    //xem lại bài 18, truyền tham biến và truyền tham trị
    void Nhap(int *&M, int n) {
        M = new int[n];
        //duyệt qua từng ptu của mảng
        //gán giá trị ngẫu nhiên
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 100);

        for (int i=0; i<n; i++) {
            //sử dụng M+i để di chuyển con trỏ
            *(M+i) = dis(gen); //gán giá trị cho vị trí con trỏ
        }
    }
    //2.
    void Xuat(int *&M, int n) {
        for (int i=0; i<n; i++) {
            cout << *(M+i) << " ";
        }
    }

    //3.
    //hàm hoán đổi 2 số nguyên
    void hoanDoi_v1(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void hoanDoi_v2(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    // void sapXep(int *&M, int n) {
    //     //run 2 vòng for để so sánh số trước và số sau
    //     //thuật toán sắp xếp nổi bọt (buble sort)
    //     for (int i=0; i<n; i++) {
    //         for (int j = i+1; j < n; j++) {
    //             // cout << i << "-" << j << "\t";
    //             //check xem số trước < số liền kề hay không hoán đổi
    //             if (*(M+i) < *(M+j)) {
    //                 hoanDoi (M+i, M+j);
    //             }
    //         }
    //         cout << endl;
    //     }
    // }
