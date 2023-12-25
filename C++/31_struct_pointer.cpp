#include <iostream>
using namespace std;

struct SinhVien
{
    int ma;
    char ten[300];
};
int main() {
    //khai báo con trỏ bth với kiểu dữ liệu cơ sở
    int *conTroNguyen = new int;
    //khởi tạo đối tượng thông thường của cấu trúc SinhVien
    SinhVien sv1;
    //gán giá trị cho sv1
    sv1 = { 1, "Dao Tien Ngoc"};
    //xuất infor .dot
    cout << "Ma sv1: " << sv1.ma << endl;
    cout << "Ten sv1: " << sv1.ten << endl;

    //khởi tạo đối tượng con trỏ cấu trúc
    SinhVien *psv2 = new SinhVien; //khai báo con trỏ
    //gán giá trị
    *psv2 = { 2, "Ho Xuan Trieu"};
    //gán giá trị cho psv2
    //truy cập vào các biến thành viên đôi với con trỏ thì dùng -> thay cho .dot
    cout << "Ma psv2: " << psv2->ma << endl;
    cout << "Ten psv2: " << psv2->ten << endl;

    SinhVien *psv3;
    psv3 = &sv1;
    //xuất infor
    cout << "Ma psv3: " << psv3->ma << endl;
    cout << "Ten psv3: " << psv3->ten << endl;

    //thử change infor trên con trỏ psv3
    cout << psv3->ma << "\t" << psv3 ->ten << endl;
    cout << sv1.ma << "\t" << sv1.ten << endl;

}
