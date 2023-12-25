#include <iostream>
using namespace std;

// Các attributes của class default là private
class Employee {
public:
    string Name;
    string Company;
    int Age;
    // Methods là hành vi của Object (nhưng nếu quá nhiều method thì phải create 1 METHOD để đại diện cho 1 hành vi)
    void IntroducYourself()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
};

int main()
{
    Employee employee1; // create 1 Object của Class
    // Access modifiers (private, public & protected)
    employee1.Name = "Ngoc";
    employee1.Company = "TMA";
    employee1.Age = 24;
    employee1.IntroducYourself();

    Employee employee2;
    employee2.Name = "Trieu";
    employee2.Company = "TMA";
    employee2.Age = 23;
    employee2.IntroducYourself();
    
    //vậy nếu có 100 employee thì làm thế nào ????
    //có 1 cách là dùng constructor nhưng nếu 1 class sẽ có 1 constructor default nếu k được khởi tạo
        //constructor k có kiểu trả về
        //constructor có cùng tên với class mà nó thuộc về
        //constructor phải ở public mode
}