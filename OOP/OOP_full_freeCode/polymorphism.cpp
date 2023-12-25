#include <iostream>
using namespace std;

class AbstracEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee: public AbstracEmployee {
private:
    // string Name;
    string Company;
    int Age;
protected:
    string Name;
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

    void IntroducYourself()
    {
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
    virtual void Work() { //nếu có 'virtual' thì method Work() of subClass sẽ ghi đè lên superClass
        cout << Name << " is checking email, task, backlog, performing tasks..." << endl;
    }
};
class Developer: public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee{name, company, age}
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        cout<< Name << " fixed bug using " << FavProgrammingLanguage << endl;
    }
    void Work() {
        cout << Name << " is writing " << FavProgrammingLanguage << " code" << endl;
    }
};

class Teacher: public Employee {
public:
    string Subject;
    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work() {
        cout << Name << " is teaching " << Subject << " code" << endl;
    }

};

int main() //The most common use of polymorphism is when a
{          //parent class reference is used to refer to a child class object 
    Developer d = Developer("Ngoc", "TMA", 24, "C++");
    Teacher t = Teacher("Bao", "VinSchool", 35, "History");

    Employee* e1 = &d; //mặc dù e1 & e2 là pointer của class Employee
    Employee* e2 = &t;

    e1->Work(); // do method Work() đc định nghĩa là virtual 
    e2->Work(); //sử dụng tính đa hình để thực hiện method tương ứng của object real (Developer or Teacher).
}