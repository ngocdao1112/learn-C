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
    Student() {}
};

int main() {
    // int luckyNumbers[5] = { 1,3,5,13,21 }; //primitive data types

    // Student s1;

    //khởi tạo các attributes
        // s1.Name = "Ngoc";
        // s1.Age = 28;
        // s1.Gender = 'm';
        // s1.ProgrammingGrade = 9;

    //nếu tạo thêm 1 s2 thì sẽ phải copy nguyên thủy như cách s1 ở trên vậy dùng constructor để làm gọn hơn
    //cách 1
        Student students[3] = { 
            {"Ngoc", 24, 'm', 9.5},
            {"An", 24, 'm', 9},
            {"Trinh", 23, 'f', 9.5}
        };
    //cách 2:
        // Student students[3];
        // for(int i=0; i<3; i++) {
        //     cout << "STUDENT " << i << endl;

        //     Student s;
        //     cout << "Name: "; cin >> s.Name;
        //     cout << "Age: "; cin >> s.Age;
        //     cout << "Gender: "; cin >> s.Gender;
        //     cout << "ProgrammingGrade: "; cin >> s.ProgrammingGrade;
        //     cout << "==========================" << endl;

        //     students[i] = s;
        // }
    //access individual objects in the arr
        // cout << "Programming grade of first student is " 
        //     << students[0].ProgrammingGrade << endl;
    //access and modify object properties in arr
        // students[1].Name = "Ngoc"; 
        
    //loops to perform operations on arr of object
    float sumOfObject = 0;
    for(int i=0; i<3; i++) {
        sumOfObject += students[i].ProgrammingGrade;
    }
    cout << "Average grade is " << sumOfObject / 3;

    //most common errors that can happen
        // for(int i=0; i<=3; i++) //access to ptu ko tồn tại trong arr và sẽ lấy giá trị trong bộ nhớ có sẵn

    cin.get();
    return 0;
}