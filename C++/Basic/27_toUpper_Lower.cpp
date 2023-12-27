#include <iostream>
#include <cstring>
using namespace std;

int main() {
    //cách 1: toUpper(char)
    char x = 'k';
    char x_hoa = toupper(x);
    cout << "ky tu k viet hoa la: " << x_hoa << endl;
    char kytuHoa = toupper('k');
    cout << "ký tự k viết hoa là: " << kytuHoa << endl;

    //cách 2: toupper(int ASII) truyền mã ASII
    char xx = 65;
    cout << "ký tự trong biến xx mã ASII 65 là: " << xx << endl;
    cout << "ký tự trong biến xx viết hoa là: " << toupper(xx) << endl;

    //tolower
    char hoa = 'A';
    char thuong = tolower(hoa);
    cout << "ký tự sau khi viết thường là: " << thuong << endl;


    /*  
        Cho user nhập vào 1 mảng ký tự
        - Chuyển toàn bộ chuỗi sang in thường và xuất ra màn hình
        - Chuyển toàn bộ chuỗi sang in hoa và xuất ra màn hình
    */
    const int max = 500;
    char str[max]; //mảng max có 500 ký tự

    cout << "Nhap chuoi bt1: ";
    cin.getline(str, max);
    cout <<"Chuoi vua nhap la: " << str << endl;
    //Chuyển toàn bộ in hoa sang in thường
    for (int i = 0; i < strlen(str); i++) {
            str[i] = tolower(str[i]);

    }
    cout << "Chuỗi sau khi chuyển sang thường là: " << str << endl;

    //Chuyển toàn bộ chuỗi sang in hoa
    for (int i = 0; i < strlen(str); i++) {
            str[i] = toupper(str[i]);

    }
    cout << "Chuỗi sau khi chuyển sang hoa là: " << str << endl;

    /*  1.
        Viết ctrinh nhâp 1 chuỗi ký tự
        - xuất ra màn hình mã ASII của từng ký tự vừa nhập vào
        (mỗi ký tự viết trên 1 dòng)
    */
    const int max_len = 200;
    char str1[max_len];
    cout << "Nhập vào 1 chuỗi bt1: ";
    cin.getline(str1, max_len);

    //xuất ra mã ASII của từng ký tự //abc
    char c = 'a';
    int maASII = (int)c;
    cout << maASII << endl;

    cout << strlen(str1) << endl;

    //dùng for để duyệt mảng ký tự
    for (int i = 0; i < strlen(str1); i++) {
        cout << str1[i] << " ma ASII la: " << (int)(str1[i]) << endl;
    }

    /*  2. 
        Viết ctrinh nhập 1 chuỗi ký tự, xuất ra màn hình chuỗi đảo ngược của chuỗi đó
    */
    //cach 1:
    const int max_len1 = 200;
    char str2[max_len1];
    cout << "Nhap chuoi bt2: ";
    cin.getline(str2, max_len1);
    //check độ dài của chuỗi nhập vào
    int len = strlen(str2);
    cout << len << endl;

    cout << "chuỗi cách 1 đảo ngược là: ";
    for (int i =(len-1); i >=0; i--) {
        // cout << "str2[" << i << "] = " << str2[i] << "\t";
        cout << str2[i];
    }
    cout << endl;

    //cach 2:
    for (int i=0; i < len/2; i++) {
        char temp = str2[i];
        str2[i] = str2[len - i - 1];
        str2[len - i - 1] = temp;
    }
    //xuất chuỗi sau đảo ngược
    cout << "chuỗi cách 2 đảo ngược là: " << str2 << endl;




}