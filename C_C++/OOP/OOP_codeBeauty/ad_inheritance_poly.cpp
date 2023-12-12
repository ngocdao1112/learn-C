//xem arrOfObjects.cpp trước khi xem bài này
//example with Array of Objects
#include <iostream>
using namespace std;

/*
- Default là các phần tử cùng loại nằm trong cùng 1 mảng
- Nhưng lq tới OOP inheritance & polymorphism - array of object thì:
    + Lưu trữ các phần tử thuộc loại khác nhau trong cùng 1 mảng
*/
class Student {
public:
    string Name;
    int Age;
    char Gender;
    virtual void study() = 0;
};

class ProgrammingStudent : public Student {
public:
    void study() {
        cout << "Learning programming" << endl;
    }

};
class ArtsStudent : public Student {
public:
    void study() {
        cout << "Learning to paint" << endl;
    }
};
class MusicStudent : public Student {
public:
    void study() {
        cout << "Learning to play piano and to sing" << endl;
    }
};
int main() {
    Student* students[3]; //mảng con trỏ tới sinh viên
    students[0] = new ProgrammingStudent();
    students[1] = new ArtsStudent();
    students[2] = new MusicStudent();
    for(int i=0; i<3; i++) {
        students[i]->study();
    }
    for(int i=0; i<3; i++) {
        delete students[i];
    }

    // cin.get();
    return 0;
}