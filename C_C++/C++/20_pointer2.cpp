#include <iostream>
using namespace std;

/*
    Mảng 2 chiều con trỏ: giống với mảng 2 chiều thông thường, ta có thể khai báo 1 ma trận, có n dòng và m cột
    (lưu ý các phần tử này toàn bộ là các con trỏ)
*/
int main() {
    const int row = 3;
    const int col = 4;
    //1 & 2. xuất địa chỉ 
    //1.
    int **capHai = new int *[row]; //3 dòng
    for (int i = 0; i < row; i++) {
        //di chuyển con trỏ bên trong để cấp phát bộ nhớ
        *(capHai + i) = new int[col]; //4 phần tử
    }

    // 2. xuất địa chỉ các ô nhớ của con trỏ cấp 2
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            //sử dụng dấu ngoặc vuông
            //sẽ truy xuất đến value ô nhớ tại vị trí i, j
            //vì thế cần sử dụng & để xuất ra địa chỉ ô nhớ tại i, j
            cout << &capHai[i][j] << " "; // capHai[i][j] -> false
        }
        cout << endl;
    }
    //3 & 4. xuất giá trị
    //3. gán giá trị cho các ptu của con trỏ mảng
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            capHai[i][j] = i + j;
        }
    }
    //4. duyệt mảng xuất các giá trị trên ma trận
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << capHai[i][j] << " ";
        }
        cout << endl;
    }

    //5. Hủy con trỏ, chỗ nào có cấp phát thì cần hủy, để k bị chiếm dụng bộ nhớ trên thanh RAM
    for (int i = 0; i < row; i++) {
        delete *(capHai + i);
    }
    delete capHai;

}