/*
- static bên ngoài 1 class or struct
    + 
- static bên trong 1 class or struct
*/

#include <iostream>

class MyClass {
public:
    static int myStaticVariable;
    int myRegularVariable;

    MyClass(int regularValue) : myRegularVariable(regularValue) {}
};

// Khởi tạo biến static
int MyClass::myStaticVariable = 0;

int main() {
    // Tạo hai đối tượng từ class
    MyClass obj1(10);
    MyClass obj2(20);

    // Mỗi đối tượng có một bản sao của biến regular
    std::cout << "Object 1 regular variable: " << obj1.myRegularVariable << std::endl;
    std::cout << "Object 2 regular variable: " << obj2.myRegularVariable << std::endl;

    // Biến static chia sẻ giữa tất cả các đối tượng của class
    MyClass::myStaticVariable = 5;

    std::cout << "Object 1 static variable: " << obj1.myStaticVariable << std::endl;
    std::cout << "Object 2 static variable: " << obj2.myStaticVariable << std::endl;

    return 0;
}
