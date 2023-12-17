#include <iostream>
#include <memory>
using namespace std;
class MyClass {
public:
    MyClass() {
        cout << "Constructor invoked" << '\n';
    }
    ~MyClass() {
        cout << "Destructor invoked" << '\n';
    }
};
int main() {
    //1. HIỂN THỊ CẢ CONSTRUCTOR & DESTRUCTOR
        // {
        // unique_ptr<MyClass>unPtr1 = make_unique<MyClass>(); //Hàm make_unique sẽ cấp phát bộ nhớ động cho đối tượng và trả về một unique_ptr sở hữu đối tượng đó.
        // }//Ptr1 sẽ bị hủy sau khi ra khỏi scope này
    //2. SHARED POINTER
        // {
            // shared_ptr<MyClass>shPtr1 = make_shared<MyClass>();
            // cout << "Shared count: " << shPtr1.use_count() << '\n';
            // {
            //     shared_ptr<MyClass>shPtr2 = shPtr1;
            //     cout << "Shared count: " << shPtr1.use_count() << endl;
            // }
            // cout << "Shared count: " << shPtr1.use_count() << endl;
        // } // in thêm 'Destructor invoked'
    //3. WEAK POINTER
    weak_ptr<int> wePtr1;
    {
        shared_ptr<int>shPtr1 = make_shared<int>(25);
        wePtr1 = shPtr1;
    }
    
    system("pause > nul");
}