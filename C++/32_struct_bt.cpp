#include <iostream>
#include <math.h>
using namespace std;

/*
    Viết ctrinh cấu trúc
    struct DiaChi {
        tenDuong
        Quan
        tinhThanh
    }
    struct NhanVien {
        Ma (int)
        ten [char()]
        tuoi (int)
        DiaChi CoQuan
        DiaChi NhaRieng
    }
    1. Tạo 2 đối tượng nv1, nv2 có đầy đủ toàn bộ infor trên, và xuất 2 màn hình
    2. khai báo bằng con trỏ
*/

/* struct DiaChi
{
    char tenDuong[300];
    char quan[300];
    char tinhThanh[300];
};
struct NhanVien {
    int ma;
    char ten[300];
    int tuoi;
    DiaChi CoQuan;
    DiaChi NhaRieng;
};

int main() {
    NhanVien pnv1;
    pnv1 = { 111, "Dao Tien Ngoc", 24, 
        {"Cong vien PMQT", "Quan 12", "Ho Chi Minh"}, 
        {"Le Thi Hoa", "Thu Duc", "Ho Chi Minh"} };

    cout << "Ma nv1: " << pnv1.ma << endl;
    cout << "Ten nv1: " << pnv1.ten << endl;
    cout << "Tuoi nv1: " << pnv1.tuoi << endl;
    cout << "CQ, Ten duong nv1: " << pnv1.CoQuan.tenDuong << endl;
    cout << "CQ, Quan nv1: " << pnv1.CoQuan.quan << endl;
    cout << "CQ, Tinh thanh nv1: " << pnv1.CoQuan.tinhThanh << endl;
    cout << "NR, Ten duong nv1: " << pnv1.NhaRieng.tenDuong << endl;
    cout << "NR, Quan nv1: " << pnv1.NhaRieng.quan << endl;
    cout << "NR, Tinh thanh nv1: " << pnv1.NhaRieng.tinhThanh << endl;

    NhanVien *pnv2 = new NhanVien;
    *pnv2 = { 222, "Ho Xuan Trieu", 23, 
            {"Cong vien PMQT", "Quan 12", "Ho Chi Minh"}, 
            {"Duong Phu Yen", "Khanh Hoa", "Phu Yen"} };

    cout << endl;
    cout << "Ma nv2: " << pnv2->ma << endl;
    cout << "Ten nv2: " << pnv2->ten << endl;
    cout << "Tuoi nv2: " << pnv2->tuoi << endl;
    cout << "CQ, Ten duong nv2: " << pnv2->CoQuan.tenDuong << endl;
    cout << "CQ, Quan nv2: " << pnv2->CoQuan.quan << endl;
    cout << "CQ, Tinh thanh nv2: " << pnv2->CoQuan.tinhThanh << endl;
    cout << "NR, Ten duong nv2: " << pnv2->NhaRieng.tenDuong << endl;
    cout << "NR, Quan nv2: " << pnv2->NhaRieng.quan << endl;
    cout << "NR, Tinh thanh nv2: " << pnv2->NhaRieng.tinhThanh << endl;

} */

    /*
        BT: Sử dụng struct, có 2 biến thành viên là: tọa độ x, y
        Viết hàm:
            1. tính khoảng cách giữa 2 điểm
                z = sqrt((xB-xA)^2 + (yB-yA)^2)
            2. Nhập vào 1 mảng các điểm, tính tổng độ dài các điểm đó
    */
/*
struct point
{
    double x;
    double y;
};
// tính khoảng cách giữa 2 điểm
double distance(point a, point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

//hàm nhập tọa độ các điểm
void nhapDiem(point array[], int soDiem) {
    for(int i = 0; i < soDiem; i++) {
        cout << "Enter point thứ: " << i + 1 << endl;
        cout << "Enter tọa độ x: ";
        cin >> array[i].x;
        cin.ignore(); //xóa bộ nhớ đệm

        cout << "Enter tọa độ y: ";
        cin >> array[i].y;
        cin.ignore(); //xóa bộ nhớ đệm
    }
}

//hàm xuất tọa độ các điểm đã nhập
void XuatDiem(point array[], int soDiem) {
    for (int i = 0; i < soDiem; i++) {
        cout << array[i].x << " - " << array[i].y << endl;
    }
}

//hàm tính distance các điểm (A, B, C AB + BC)
double lengthPoints(point array[], int soDiem) {
    double totalDistance;
    for (int i = 0; i < soDiem - 1; i++) {
        double kc = distance(array[i], array[i+1]);
        totalDistance += kc; //totalDistance = totalDistance + kc;
        cout << "KC thứ " << i << " = " << kc << endl;
    }
    return totalDistance;
}
int main() {
    //1. tính khoảng cách giữa 2 điểm
    //khai báo 2 đối tượng a, b là 2 điểm
    point a;
    point b;
    //gán giá trị cho 2 điểm a, b
    a = { 1, 1 };
    b = { 3, 3 };
    //gọi hàm khoảng cách
    double kq = distance(a ,b);
    cout << "Distance 2 point a, b: " << kq << endl;

    //2. Nhập vào 1 mảng các điểm, tính tổng độ dài các điểm đó
    const int soDiem = 3;
    //khởi tạo mảng
    point array[soDiem]; //point array[3]
    nhapDiem(array, soDiem);
    cout << "Lists tọa độ vừa nhập: " << endl;
    XuatDiem(array, soDiem);
    cout << endl;
    cout << "Total point lengths: " << lengthPoints(array, soDiem);

}
*/

/*
    BT: Cho phân số có cấu trúc: tử, mẫu
    Viết hàm cộng, trừ, nhân, chia tối giản phân số (4/8) 1/2
*/
struct PhanSo
{
    int tu, mau;
};
//tìm hàm ước chung lớn nhất
int UCLN (int a, int b) {
    a = abs(a);
    b = abs(b);
    if(b == 0)
        return a;
    return UCLN(b, a % b);
}

//hàm tối giản phân số
void ToiGianPhanSo (PhanSo& ps) {
    int ucln = UCLN(ps.tu, ps.mau);
    ps.tu /= ucln; //ps.tu = ps.tu / ucln
    ps.mau /= ucln; //ps.mau = ps.mau / ucln
}

//hàm cộng phân số (1/2 + 3/4)
PhanSo CongPhanSo (PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = (ps1.tu * ps2.mau) + (ps1.mau * ps2.tu);
    kq.mau = ps1.mau * ps2.mau;
    ToiGianPhanSo(kq);
    return kq;
}

//hàm trừ phân số (1/2 - 3/4)
PhanSo TruPhanSo (PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = (ps1.tu * ps2.mau) - (ps1.mau * ps2.tu);
    kq.mau = ps1.mau * ps2.mau;
    ToiGianPhanSo(kq);
    return kq;
}

//hàm nhân phân số (1/2 * 3/4)
PhanSo NhanPhanSo (PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    ToiGianPhanSo(kq);
    return kq;
}

//hàm chia phân số (a/b / c/d = a/b * d/c)
PhanSo ChiaPhanSo (PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    ToiGianPhanSo(kq);
    return kq;
}

int main () {
    PhanSo ps1, ps2, kq;
    cout << "Mời nhập vào phân số thứ nhất: \n";
    cin >> ps1.tu >> ps1.mau;
    cin.ignore();

    cout << "Mời nhập vào phân số thứ hai: \n";
    cin >> ps2.tu >> ps2.mau;
    cin.ignore();

    //Cộng phân số
    kq = CongPhanSo(ps1, ps2);
    cout << "Tong hai phan so + : " << kq.tu << "/" << kq.mau << endl;

    //Trừ phân số
    kq = TruPhanSo(ps1, ps2);
    cout << "Tong hai phan so - : " << kq.tu << "/" << kq.mau << endl;

    //Nhân phân số
    kq = NhanPhanSo(ps1, ps2);
    cout << "Tong hai phan so * : " << kq.tu << "/" << kq.mau << endl;

    //Chia phân số
    kq = ChiaPhanSo(ps1, ps2);
    cout << "Tong hai phan so / : " << kq.tu << "/" << kq.mau << endl;

}