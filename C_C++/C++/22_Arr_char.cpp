#include <iostream>
#include <limits>

using namespace std;

/*
    - Mảng ký tự là 1 mảng, mà các ptu là các ký tự đơn lẻ: a, b, c, 1, 2, $, #...
    - Chuỗi là 1 mảng ký tự được kết thúc bằng ký tự null('0')
    - Khai báo:
        + Dùng mảng 1 chiều
        + Mảng kyTu có khả năng lưu trữ tối đa 5 ptu
        + Luôn luôn chừa vị trí cuối cùng cho ký tự null\0 để mảng ký tự có thể hiển thị dưới dạng chuỗi
    - Khai báo hằng chuỗi
*/

int main() {
    //1.
    //khởi tạo mảng ký tự
    char kyTu[5] = { 'a', 'b', 'c', 'd' }; //chừa lại vị trí cuối cho ký tự null 0
    cout << kyTu << endl;
    //khai báo dùng con trỏ
    char *chuoi;
    //cấp phát bộ nhớ
    chuoi = new char[51];
    //gán phần tử theo vị trí index
    chuoi[0] = 'a';
    chuoi[1] = 'b';
    chuoi[2] = 'c';
    chuoi[3] = 'r';
    chuoi[4] = 't';
    chuoi[5] = '\0'; //nếu ko gán \0 sẽ false
    cout << "Mang ký tự khai báo dùng con trỏ: " << chuoi << endl;

    //khai báo hằng chuỗi
    char chuoi2[] = "Xin"; // có 3 ký tự nhưng thêm null\0 ở vị trí cuối cùng nên size của nó = 4
    cout << chuoi2 << endl;

    //check kích thước của mảng
    cout << size(chuoi2) << endl;

    //2. cin.getline(<ten_mang>, <so_ky_tu_toi_da_duoc_nhap>)
    //Đọc ký tự từ bàn phím, ký tự null sẽ tự động được thêm vào mảng
    //Để tránh tràn bộ nhớ, đối số thứ 2 của hàm getline sẽ quy định số ký tự tối đa được nhập vào mảng
    const int max = 4; //in ra 3 ký tự + 1 ký tự null
    char chuoi3[max]; //khai báo chuỗi chứa tối đa max = 4 ký tự
    cout << "Nhập chuỗi cách 1: ";
    cin.getline(chuoi3, max); //đối số max thứ 2 để tránh tràn bộ nhớ, vì max = 4 mà nhập 10 thì sẽ tràn
    cout << "Chuỗi vừa nhập là: ";
    cout << chuoi3 << endl;

    cin.clear(); //xóa trạng thái lỗi
    //xóa được tối đa bộ nhớ mà cin có thể lưu trữ được
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //dùng con trỏ
    char *chuoi4 = new char[max];
    cout << "Mời nhập chuỗi cách 2: ";
    cin.getline(chuoi4, max);
    cout << "Chuỗi vừa nhập là: " << chuoi4 << endl;

}
