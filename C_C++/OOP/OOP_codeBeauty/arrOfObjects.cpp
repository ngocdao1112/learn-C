#include <iostream>
using namespace std;

/*
- what are arr of objects
- how are they different from arr of primitive data types
- why and when should you use arr of objects
- how do you access individual objects in the arr
- how do you access and modify object properties in arr
- how do you loops to perform operations on arr of object
- most common errors that can happen 
- task for you at the end
*/
class Student {
public:
    string Name;
    int Age;
    char Gender;
    float ProgrammingGrade;

    Student (string _name, int _age, char _gender, float _programmingGrade) { //nhận 4 giá trị ở dưới truyền lên
        Name = _name;
        Age = _age;
        Gender = _gender;
        ProgrammingGrade = _programmingGrade;
    }
};

int main() {
    // int luckyNumbers[5] = { 1,3,5,13,21 }; //primitive data types

    Student s1;

    //khởi tạo các attributes
    s1.Name = "Ngoc";
    s1.Age = 28;
    s1.Gender = 'm';
    s1.ProgrammingGrade = 9;

    Student students[3];
    students[0] = s1;
    //nếu tạo thêm 1 s2 thì sẽ phải copy nguyên thủy như cách s1 ở trên vậy dùng constructor để làm gọn hơn


    // cin.get();
    return 0;
}