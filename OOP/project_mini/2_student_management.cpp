#include <vector>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Student {
    private:
        int rollno, age;
        string name;
    public:
        Student(int stdRollno, string stdName, int stdAge) {
            rollno = stdRollno;
            name = stdName;
            age = stdAge;
        }
        void setRollno(int stdRollno) {
            rollno = stdRollno;
        }
        int getRollno() {
            return rollno;
        }
        void setName(int stdAge) {
            age = stdAge;
        }
        int getAge() {
            return age;
        }
};
//Create function to add new student
void addNewStudent(vector<Student> &student) {
    int rollno, age;
    string name;
    cout << "Enter Rollno: ";
    cin >> rollno;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;

    Student.newStudent(rollno, name, age);
    students.push_pack(newStudent);

}



int main() {
    vector<Student> students;
    students.push_back(Student(1, "Ali", 20));

    int op;
    cout << "\t\t1. Add new Student: " << endl;
    cout << "\t\t2. Display all Student: " << endl;
    cout << "\t\t3. Search Student: " << endl;
    cout << "\t\t4. Update Student: " << endl;
    cout << "\t\t5. Delete Student:  " << endl;
    cout << "\t\t6. Exit: " << endl;
    cout << "\t\tEnter your choice: ";
    cin >> op;

}