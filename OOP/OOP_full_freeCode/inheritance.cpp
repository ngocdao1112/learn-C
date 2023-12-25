#include <iostream>
using namespace std;

class AbstracEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee: AbstracEmployee {
private:
    // string Name;
    string Company;
    int Age;
protected:
    string Name;
public:
    // string Name;
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
};
// class Developer: Employee {
class Developer: public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee{name, company, age} {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        // cout<< getName() << " fixed bug using " << FavProgrammingLanguage << endl;
        cout<< Name << " fixed bug using " << FavProgrammingLanguage << endl; //vì attributes 'Name' nằm trong protected vì subClass kế thừa từ superClass
    }

};

// class Teacher: public Employee { // nếu trong main gọi AskFor.. or get, set thì sẽ error như giải thích ở dưới
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
};

int main()
{
    Developer d = Developer("Ngoc", "TMA", 24, "C++");
    d.FixBug();
    d.AskForPromotion(); // error : do phương thức AskForPromotion trong AbstracEmployee được khai báo là private 
                        //mặc định khi bạn không chỉ định mức độ truy cập nào cả
    Teacher t = Teacher("Bao", "VinSchool", 35, "History");
    t.PrepareLesson();
    t.AskForPromotion();
}