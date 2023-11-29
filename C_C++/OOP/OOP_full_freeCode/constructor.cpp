#include <iostream>
using namespace std;

class Employee
{
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

    Employee employee2 = Employee("Trieu", "TMA", 23);
    employee2.IntroducYourself();
}