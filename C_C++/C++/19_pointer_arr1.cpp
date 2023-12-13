#include <iostream>
using namespace std;
/*
    - Con trỏ tương tác với mảng 1 chiều: con trỏ và mảng có mối quan hệ gần, mảng cũng quản lý theo địa chỉ ô nhớ
    - Có thể gán trực tiếp con trỏ vào mảng mà không cần dùng toán tử '&'
*/

int main() {
    //1.
    //khai bao mang
    int mang[] = { 1,2,3,4,5,1,4,8,4 };
    //khai bao con tro
    int *conTroM;
    //gán con trỏ vào mảng (không cần &)
    conTroM = mang; // &mang[0]
                    // &mang, đó sẽ là địa chỉ của toàn bộ mảng

    //duyệt mảng nhưng qua con trỏ
    cout << "Mảng trước khi đổi: ";
    for(int i=0; i < size(mang); i++) {
        //lấy giá trị nằm trên ô nhớ mà conTroM thứ i quản lý
        cout << *(conTroM + i) << " ";
        //lấy địa chỉ ô nhớ mà conTroM thứ i quản lý
        // cout << (conTroM + i) << " ";
    }

    //CON TRỎ TOÁN HỌC
    int mang[] = { 1,2,3,4,5,1,4,8,4 };
    int *conTroM;
    conTroM = mang;
    int *conTroArith;
    cout << "Mảng trước khi đổi: ";
    for(int i=0; i<size(mang); i++) {
        conTroArith = &conTroM[i];

        //lấy giá trị nằm trên ô nhớ mà conTroM thứ i quản lý
        cout << *(conTroM + i) << " ";
        //lấy địa chỉ ô nhớ mà conTroM thứ i quản lý
        // cout << (conTroM + i) << " ";
    }

    //2.thay đổi giá trị mảng dùng con trỏ
    *(conTroM + 2) = 99;
    cout << "\nMảng sau khi đổi : ";
    for (int i = 0; i < size(mang); i++) {
        cout << mang[i] << " ";
    }

    //3. khai báo mảng con trỏ
    int *mangConTro[4];
    //duyệt mảng để cấp phát bộ nhớ
    for (int i=0; i<size(mangConTro); i++) {
        mangConTro[i] = new int;
    }
    cout << endl;
    //xuất các giá trị của mảng (địa chỉ các ô nhớ)
    for (int i=0; i<size(mangConTro); i++) {
        cout << mangConTro[i] << endl;
    }


    

}