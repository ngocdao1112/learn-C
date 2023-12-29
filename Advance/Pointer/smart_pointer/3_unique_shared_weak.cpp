//https://www.youtube.com/watch?v=UOB7-B2MfwA
/* 
1. Quản lý Đối tượng Động (Dynamic Objects):
    -  quản lý đối tượng được tạo động trên heap
    unique_ptr<int> uniquePtr = make_unique<int>(42);
    shared_ptr<int> sharedPtr = make_shared<int>(42);
2. Tránh Memory Leaks: 
    - Smart pointers tự động giải phóng bộ nhớ khi chúng ra khỏi phạm vi (scope)
3. Tránh Dangling Pointers:
    - Smart pointers giúp tránh việc sử dụng dangling pointers (con trỏ trỏ tới vùng nhớ không còn hợp lệ) 
    bằng cách tự động đặt giá trị nullptr cho con trỏ khi đối tượng được giải phóng.
4. Quản lý Resource:
    - std::unique_ptr<FILE, decltype(&fclose)> file(fopen("example.txt", "r"), &fclose);

*/
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Created Entity!" << endl;
    }
    ~Entity() {
        cout << "Destroyed Entity!" << endl;
    }

    void Print() {}
};

// int main() {
//     {
//         // unique_ptr<Entity> entity = make_unique<Entity>();
//         // unique_ptr<Entity> en = entity; // error, vì k cho copy
//         // entity->Print();
        
//     }
//     cin.get();
// }

// int main() {
//     {
//         shared_ptr<Entity> e0;
//         {
//             shared_ptr<Entity> sharedEntity = make_shared<Entity>();
//             e0 = sharedEntity;
//         }
//     }
//     cin.get();
// }

// int main() {
//     shared_ptr<Entity> sharedPtr = make_shared<Entity>();
//     weak_ptr<Entity> weakPtr = sharedPtr;

//     if (!weakPtr.expired()) { // tra xem weak_ptr có tham chiếu đến một đối tượng còn tồn tại trên heap hay không.
//         shared_ptr<Entity> sharedPtr2 = weakPtr.lock(); // Chuyển đổi thành shared_ptr
//         // Sử dụng sharedPtr2 như là một shared_ptr hợp lệ
//     }

//     // Khi weakPtr ra khỏi phạm vi, MyClass không bị giải phóng vì sharedPtr vẫn giữ sở hữu
//     return 0;
// }

int main() {
    shared_ptr<int> sharedPtr = make_shared<int>(42);
    weak_ptr<int> weakPtr = sharedPtr;

    if (!weakPtr.expired()) {
        // weakPtr tham chiếu đến một đối tượng trên heap
        cout << "The weak pointer is still valid." << endl;
    } else {
        // weakPtr không tham chiếu đến bất kỳ đối tượng nào (đã giải phóng hoặc chưa được thiết lập)
        cout << "The weak pointer is expired." << endl;
    }

    // Giải phóng sharedPtr
    sharedPtr.reset();

    if (!weakPtr.expired()) {
        // weakPtr tham chiếu đến một đối tượng trên heap (vẫn còn tồn tại)
        cout << "The weak pointer is still valid." << endl;
    } else {
        // weakPtr không tham chiếu đến bất kỳ đối tượng nào (đã giải phóng)
        cout << "The weak pointer is expired." << endl;
    }

    return 0;
}
