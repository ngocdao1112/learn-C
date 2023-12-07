#include <iostream>
using namespace std;

class Employee {
private:
    string Name;
    string Company;
    int Age;
public:
    void IntroducYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    //Constructors có tham số
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employee1 = Employee("Ngoc", "TMA", 24); //gọi constructor và truyền vào 3 đối số
    // Employee employee1; // create 1 Object của Class
    //truyền 3 thuộc tính Name, Company & Age cho Constructors
    /* employee1.Name = "Ngoc";
    employee1.Company = "TMA";
    employee1.Age = 24; */
    employee1.IntroducYourself();
    // employee1.Name(); // vì chưa có getter & setter nên sẽ cần encapsulation

    Employee employee2 = Employee("Trieu", "TMA", 23);
    employee2.IntroducYourself();
}