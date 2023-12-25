//viết code một lần và sử dụng cho nhiều kiểu dữ liệu hoặc giá trị khác nhau mà không cần phải viết lại code
#include <iostream>
#include <string>
using namespace std;

    // template<typename T> // 1 template func với tham số T nhận vào mọi data type
    // void Print(T value) { //đây k phải là 1 func, nhận vào 1 giá trị kiểu T
    //     cout << value << endl;
    // }
    // // void Print(float value) {
    // //     cout << value << endl;
    // // }
    // // void Print(string value) {
    // //     cout << value << endl;
    // // }

    // int main() {
    //     Print(5);  
    //     // Print("Hello");
    //     // Print(5.5f);

    //     // Print<int>(5); // ko cần 

    //     return 0;
    // }


    // template<int N>
    // class Array {
    // private:
    //     int m_Array[N];
    // public:
    //     int GetSize() //trả về kích thước của mảng
    //     const { //method GetSize() không thay đổi dữ liệu của object array và chỉ được phép đọc dữ liệu.
    //         return N; //đảm bảo rằng giá trị của mảng không thể thay đổi sau khi được khởi tạo.
    //     }
    // };

    // int main() {
    //     Array<5> array; //object array với N = 5
    //     cout << array.GetSize() << endl;
    // }
/*
Đây là cách bạn có thể tạo các đối tượng Array với kích thước khác nhau tại thời điểm biên 
dịch thông qua sử dụng template, giúp tái sử dụng mã và tạo ra mã linh hoạt có thể thích ứng với nhiều tình huống khác nhau.
*/


template<typename T, int N>
class Array {
private:
    T m_Array[N];
public:
    int GetSize() //trả về kích thước của mảng
    const { //method GetSize() không thay đổi dữ liệu của object array và chỉ được phép đọc dữ liệu.
        return N; //đảm bảo rằng giá trị của mảng không thể thay đổi sau khi được khởi tạo.
    }
};

int main() {
    Array<string, 50> array; //object array với N = 5
    cout << array.GetSize() << endl;
}