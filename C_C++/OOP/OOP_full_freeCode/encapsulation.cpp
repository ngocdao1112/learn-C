#include <iostream>
using namespace std;

class Employee
{
private: //encapsulation để bảo mật data và change data
    string Name;
    string Company;
    int Age;
public:
    void setName(string name) { //setter
        Name = name;
    }
    string getName() { //gettter
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    void setAge(int age) {
        if(age >= 18) //muốn tăng sự bảo mật lên nên dùng if-else
        Age = age;
    }
    int getAge() {
        return Age;
    }

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
    Employee employee1 = Employee("Ngoc", "TMA", 24);
    employee1.IntroducYourself();
    Employee employee2 = Employee("Trieu", "TMA", 23);
    employee2.IntroducYourself();

    //encapsulation
    employee1.setAge(15); //15 < 18 nên kết quả vẫn là 24
    cout << employee1.getName() << " is " << employee1.getAge() << " years old" << endl;
}