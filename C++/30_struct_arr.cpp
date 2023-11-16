#include <iostream>
using namespace std;

/*
    - Coi cấu trúc như 1 kiểu dữ liệu do ta tạo ra
    - Khai báo như khai báo mảng thông thường
    - Các phần tử cũng có thể dùng toán tử .Dot để truy cập các thuộc tính (các biến thành viên)
*/

struct SinhVien
{
    int ma;
    char ten[255];
};

//hàm nhập mảng
void NhapMang(SinhVien ds[], int total) {
    for (int i =0; i < total; i++) {
        cout << "Nhập infor sv thứ " << i + 1 << endl;
        cout << "Nhập mã: ";
        cin >> ds[i].ma;
        //xóa bộ nhớ đệm
        cin.ignore();
        cout << "Nhập tên: ";
        // get_s(ds[i], sizeof(ds[i].ten));
        cin.getline(ds[i].ten, sizeof(ds[i].ten));
        cin.ignore();

    }
}
//hàm xuất mảng
void XuatMang(SinhVien ds[], int total) {
    for (int i = 0; i < total; i++) {
        cout << ds[i].ma << "\t" << ds[i].ten << endl;
    }
}

int main() {
    //khai báo mảng với kiểu dữ liệu cơ bản
    int mang1[15];
    //khai báo mảng với cấu trúc
    const int total = 4;
    SinhVien ds[total];

    NhapMang(ds, total);
    XuatMang(ds, total);


}