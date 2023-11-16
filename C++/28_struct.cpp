#include <iostream>
#include <cstring>
using namespace std;
/*
    - Các kiểu dữ liệu cơ bản đã học: char, int, long, float, double...
    - Thực tế đôi khi cần sử dụng các kiểu dữ liệu phức tạp hơn -> using struct: là kiểu dữ liệu do ta tự định nghĩa
    - Struct: có thể hiểu đơn giản là 1 tập các biến được khai báo sau keyword struct

    Khai báo struct:
        struct tên_cấu_trúc {
            data_type tên_biến_thành_viên_1;
            data_type tên_biến_thành_viên_2;
            data_type tên_biến_thành_viên_3;
            ..........
        } varName1, varName2;
        //tên các biến cấu trúc - các đối tượng
    
    - Trong struct có thể khai báo nhiều biến thành viên
    - Trong struct có thể chứa các struct khác
*/

struct DiaChi
{
    //khai báo các biến thành viên - thuộc tính
    char SoNha[25];
    char TenDuong[250];
    char TinhThanh[25];
};
// struct SinhVien
struct SinhVien
{
    //biến thành viên, thuộc tính
    char MaSV[10];
    char TenSV[250];
    bool GioiTinh;
    DiaChi DiaChiNha;

};


//typedef struct SinhVien SV;

// sv1, sv2; // biến cấu trúc (đối tượng), đối tượng này chứa MaSV, TenSV, GioiTinh, ....

int main() {

    //tạo ra các đối tượng của cấu trúc SV
    SinhVien sv1, sv2; // Declare sv1 and sv2 inside the main function
    std::cout << "Hello";

    //để gán giá trị cho biến cấu trúc
    //cách 1:
    //{tên_biến_cấu_trúc} = { {giá_trị_1}, {giá_trị_2}, ..., {giá_trị_n} };
    sv1 = { {"02"}, {"Ngoc Dao"}, {true}, { {"84"}, {"Le Thi Hoa"}, {"Tp Thu Duc"} } };

    //cách 2:
    //có thể cần đối với 1 số trình biên dịch
    strcpy_s(sv2.MaSV, sizeof(sv2.MaSV), "01");
    strcpy_s(sv2.TenSV, sizeof(sv2.TenSV), "Dao Tien Ngoc");
    sv2.GioiTinh = false;

    /*
    Truy cập các biến thành viên (thuộc tính của cấu trúc):
    sử dụng tên_đối_tượng.biến_thành_viên
    */
   // Truy cập xuất thông tin sv1
    cout << "Thong tin sv1 la: " << endl;
    cout << "Ma SV: " << sv1.MaSV << endl;
    cout << "Ho va ten: " << sv1.TenSV << endl;
    cout << "Gioi tinh SV: " << (sv1.GioiTinh == true ? "Nam" : "Nu") << endl;
    cout << "So nha SV: " << sv1.DiaChiNha.SoNha << endl; // DiaChiNha là 1 cấu trúc, SoNha là biến thành viên đầu tiên của địa chỉ 100
    cout << "Ten duong SV: " << sv1.DiaChiNha.TenDuong << endl; 
    cout << "Tinh thanh SV: " << sv1.DiaChiNha.TinhThanh << endl;

   //xuất thông tin sv2
    cout << "Thong tin sv2 la: " << endl;
    cout << "Ma SV: " << sv2.MaSV << endl;
    cout << "Ho va ten: " << sv2.TenSV << endl;
    cout << "Gioi tinh SV: " << (sv2.GioiTinh == true ? "Nam" : "Nu") << endl;


    return 0;

}