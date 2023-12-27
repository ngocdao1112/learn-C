#include <iostream>
#include <algorithm>
#include <random>
using namespace std;


int main() {
    /*
        Viet ctrinh tạo 1 mảng 1 chiều gồm các ptu là số nguyên có 4 ptu, các ptu do người dùng nhập từ bàn phím
    */
/*   
    int Arr1[4];
    for(int i = 0; i < size(Arr1); i++) {
        cout << "Arr1[" << i << "]= " << endl;
        cin >> Arr1[i];

    }
    cout << "Mang vua nhap la: ";
    for (int i=0; i < size(Arr1); i++) {
        cout << Arr1[i] << " ";
    }
*/
    //1. sắp xếp mảng
    int Arr2[5] = {14, 5, 7, 8, 4};
    sort(Arr2, Arr2 + size(Arr2)); //Arr2 trỏ đến phần tử đầu tiên của mảng
    // Arr2 + size(Arr2) là con trỏ trỏ đến vị trí ngay sau phần tử cuối cùng của mảng, đánh dấu phạm vi cần được sắp xếp
    cout << "Arr2 sau sắp xếp tăng dần là: ";
    for (int i = 0; i < size(Arr2); i++) {
        cout << Arr2[i] << " ";
    }
    cout << endl;
    //2. đảo ngược mảng
    reverse(Arr2, Arr2 + size(Arr2));
    cout << "Arr2 sau khi đổi ngược là: ";
    for (int i = 0; i < size(Arr2); i++) {
        cout << Arr2[i] << " ";
    }
    cout << endl;
    //3. tạo ra mảng có các ptu ngẫu nhiên
/*    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99); //set khoảng ngẫu nhiên

    int Arr3[10];
    for (int i = 0; i < size(Arr3); i++) {
        Arr3[i] = dis(gen);
    }
    cout << "Mảng ngẫu nhiên vừa tạo ra là: ";
    //xuất mảng
    for (int pt : Arr3) {
        cout << pt << " ";
    }
    cout << endl;
    cout << endl; 
*/
/*  BT:
    1. Viết ctrinh tạo 1 mảng 1 chiều gồm các ptu là số nguyên, có 7 ptu ngẫu nhiên
    2. Xuất các gtri trong mang
    3. Đảo ngược mảng, và xuất mảng sau khi đảo ngược
    4. Sắp xếp mảng tăng dần
    5. Tính tổng các ptu trong mảng
    6. Cho user nhập 1 số bất kỳ, check xem số đó có tồn tại trong mảng hay không, nếu có thì bao nhiêu số ??
*/
    //1. Tạo mảng có 7 ptu ngẫu nhiên
    random_device rd1;
    mt19937 gen1(rd1());
    uniform_int_distribution<> dis(0, 10);

    int Arr4[7];
    for (int i = 0; i < size(Arr4); i++) {
        Arr4[i] = dis(gen1);
    }
    cout << "Mang ngau nhien sau khi tao la: ";
    //2. Xuất các gtri trong mang
    for(int pt : Arr4) {
        cout << pt << " ";
    }
    cout << endl;
    //3. Đảo ngược mảng, và xuất mảng sau khi đảo ngược
    reverse(Arr4, Arr4 + size(Arr4));
    cout << "Mang sau khi doi nguoc la: ";
    for (int i = 0; i < size(Arr4); i++) {
        cout << Arr4[i] << " ";
    }
    cout << endl;
    //4. Sắp xếp mảng tăng dần
    sort(Arr4, Arr4 + size(Arr4));
    cout << "Mang sau khi sap xep tang dan la: ";
    for (int i=0; i < size(Arr4); i++) {
        cout << Arr4[i] << " ";
    }
    cout << endl;
    //5. Tính tổng các ptu trong mảng
    int sum = 0;
    for (int i = 0; i < size(Arr4); i++) {
        sum += Arr4[i]; // sum = sum + Arr4[i]
    }
    cout << "Tong cac ptu trong mang la: " << sum << endl;

    //6. Cho user nhập 1 số bất kỳ, check xem số đó có tồn tại trong mảng hay không, nếu có thì bao nhiêu số ??
    int nhapSo;
    cout << "Nhap 1 so bat ky: ";
    cin >> nhapSo;

    int dem = 0;
    for (int i = 0; i < size(Arr4); i++) {
        if(Arr4[i] == nhapSo) {
            dem++;
        }
    }
    /*  1   3   5   1   6
        nhapSo: 1
        dem = 0; i = 0; 
        Arr4[0] == 1 => 1 == 1 ; dem++ = 1
        dem = 1; i = 1;
        Arr4[1] == 1 => 3 == 1 => false
        dem = 1; i = 2;
        Arr4[2] == 1 => 5 == 1 => false
        dem = 1; i = 3; 
        Arr4[3] == 1 => 1 == 1 ; dem++ = 2
        dem = 2; i = 4;
        Arr4[2] == 1 => 6 == 1 => false
        ====> dem = 2
    */
    if(dem > 0) {
        cout << "So " << nhapSo << " ton tai trong mang va xuat hien " << dem << " lan." << endl;
    }
    else
        cout << "So " << nhapSo << " khong ton tai trong mang." << endl; 
}