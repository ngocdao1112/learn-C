#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class NCC {
    private:
        char maNCC[20];
        char tenNCC[30];
        char diaChi[30];
    public:
        void Nhap();
        void Xuat();
};
class hang {
    private:
        char tenHang[30];
        float donGia;
        float soLuong;
    public:
        void Nhap();
        void Xuat();
        float thanhTien() {
            return donGia*soLuong;
        }
};
class phieu {
    private:
        char maPhieu[20];
        char ngayLap[30];
        NCC x;
        hang *y;
        int n;
    public:
        void Nhap();
        void Xuat();
};
void NCC::Nhap() {
    cout << "\nNhap ma NCC: ";                  fflush(stdin);          fgets(maNCC, sizeof(maNCC), stdin);
    cout << "\nNhap ten NCC: ";                 fflush(stdin);          fgets(tenNCC, sizeof(tenNCC), stdin);
    cout << "\nNhap dia chi NCC: ";             fflush(stdin);          fgets(diaChi, sizeof(diaChi), stdin);
}
void NCC::Xuat() {
    cout << setw(10) << "Ma NCC: " << maNCC << setw(20) << "Ten NCC: " << tenNCC << endl;
    cout << setw(10) << "Dia chi NCC: " << diaChi << endl;
}
void hang::Nhap() {
    cout << "\nNhap ten hang: ";                fflush(stdin);          fgets(tenHang, sizeof(tenHang), stdin);
    cout << "\nNhap don gia: ";                 cin >> donGia;
    cout << "\nNhap so luong: ";                cin >> soLuong;
}
void hang::Xuat() {
    cout << tenHang << setw(15) << donGia << setw(15) << soLuong << setw(15) << thanhTien() << endl;
}
void phieu::Nhap() {
    cout << "\nNhap ma phieu: ";                fflush(stdin);          fgets(maPhieu, sizeof(maPhieu), stdin);
    cout << "\nNhap ngay lap: ";                fflush(stdin);          fgets(ngayLap, sizeof(ngayLap), stdin);         ngayLap[strcspn(ngayLap, "\n")] = '\0';
    x.Nhap();  
    cout << "\nNhap so luong hang: ";           cin >> n;
    y = new hang[n];
    for (int i=0; i<n; i++) {
        cout << "Hang thu " << i+1 << endl;
        y[i].Nhap();
    }
}
void phieu::Xuat() {
    cout << setw(30) << "========================PHIEU NHAP HANG========================" << endl;
    cout << setw(10) << "Ma Phieu: " << maPhieu << setw(20) << "Ngay lap: " << ngayLap << endl;
    x.Xuat();
    cout << setw(30) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(15) << "Thanh tien"<< endl;
    for (int i=0; i<n; i++) {
        y[i].Xuat();
    }
    float tong = 0;
    for (int i=0; i<n; i++) {
        tong = tong + y[i].thanhTien();
    }
    cout << setw(40) << "Cong thanh tien: " << tong << endl;

}

int main() {
    phieu a;
    a.Nhap();
    a.Xuat();

    return 0;
}