//https://www.youtube.com/watch?v=oUJbuFMyBDk&pp=ygURSVBDIG1lc3NhZ2UgcXVldWU%3D

#include <iostream>
#include <memory>
using namespace std;

class SharedData {
public:
    SharedData(int value) : data(value) {}

    void printData() {
        cout << "Shared Data: " << data << endl;
    }

private:
    int data;
};

int main() {
    // Tạo một smart pointer shared_ptr đến đối tượng SharedData
    shared_ptr<SharedData> sharedObj = make_shared<SharedData>(42);

    // Tạo thêm một smart pointer khác trỏ đến cùng một đối tượng
    shared_ptr<SharedData> anotherSharedObj = sharedObj;

    // Sử dụng smart pointer để truy cập và sửa đổi dữ liệu
    sharedObj->printData();
    anotherSharedObj->printData();

    // Khi smart pointer cuối cùng trỏ đến đối tượng bị hủy, bộ nhớ được giải phóng tự động
    return 0;
}
