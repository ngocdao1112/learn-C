#include <iostream>
using namespace std;
class AbstracEmployee {
    virtual void AskForPromotion() = 0;
// public: 
//     virtual void AskForPromotion() {
//             cout << " got ngoccccc!" << endl;
//     }
};
class Employee: public AbstracEmployee {
private: //encapsulation để bảo mật data
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
        if(age >= 18)
        Age = age;
    }
    int getAge() {
        return Age;
    }

    void IntroducYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion() {
        if(Age > 30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << ", sorry NO promotion for you!" << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Ngoc", "TMA", 24);
    Employee employee2 = Employee("Trieu", "TMA", 35);
    employee1.AskForPromotion();
    employee2.AskForPromotion();

    return 0;
}