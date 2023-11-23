#include <iostream>
using namespace std; 
int main() 
{ 
 //1. ép kiểu rộng 
    int a = 10; 
    //kiểm tra kiểu dữ liệu của a
    cout << "kieu du lieu cua a: "<< typeid(a).name()<<endl; 
    //xuất giá trị a 
    cout << "a= " << a << endl;
    //khai báo biến b, ép kiểu a sang int 
    float b = (float)a; // ép tường minh
    //float b = a; // C++ cho phép ép tắt
    
    //kiểm tra kiểu dữ liệu của b
    cout << "kieu du lieu cua b: " << typeid(b).name()<<endl;
    //xuất giá trị b
    cout << "b= " << b << endl;

 //2. ép kiểu hẹp
    float soA = 1.25;
    int soB = 1.25;
    cout << "SoA= " << soA << endl;
    cout << "SoB= " << soB << endl;
} 