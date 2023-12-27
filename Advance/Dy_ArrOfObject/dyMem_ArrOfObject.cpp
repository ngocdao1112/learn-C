#include <iostream>
using namespace std;
/*
Dynamic memory and Arrays of objects:

    - difference between static and dynamic arrays
    - how to allocate memory for dynamic arrays
    - how to deallocate memory for dynamic arrays
    - a real-world example of how to work with dynamic arrays of objects
    - what are the benefits of using dynamic arrays
    - most common errors
    - task for you at the end
//changing the size of the dynamic array at runtime
    1. allocate newStudents array
    2. copy elements from students array into newStudents array
    3. delete [] students
    4. students should point to the same address as newStudents (students == newStudents) 
*/

class Student {
public:
    string Name;
    int Age;
    char Gender;
    float ProgrammingGrade;
};
//passing dynamic array into a function
void printStudents(Student* students, int size) {
    for(int i=0; i<size; i++) {
        cout << "=======================" << '\n';
        cout << "STUDENT " << i+1 << '\t';
        cout << students[i].Name << '\t';
        cout << students[i].Age << '\t';
        cout << students[i].Gender << '\t';
        cout << students[i].ProgrammingGrade << '\n';

    }
}

int main() {
    //create dynamic array of objects
    int size;
    cout <<"Number of student: ";
    cin >> size;
    Student* students = new Student[size];

    for(int i=0; i<size; i++) {
        cout << "STUDENT " << i+1 << endl;

        Student s;
        cout << "Name: "; cin >> s.Name;
        cout << "Age: "; cin >> s.Age;
        cout << "Gender: "; cin >> s.Gender;
        cout << "Programming grade: "; cin >> s.ProgrammingGrade;

        students[i] = s;
    }

    char choice;
    cout << "Do you want a bigger array?";
    cin >> choice;
    if(choice == 'n' || choice == 'N') {
        delete[]students;
        return 0;
    }
    //changing the size of the dynamic array at runtime
    int newSize;
    cout << "Enter new size: ";
    cin >> newSize;
    //1. allocate newStudents array
    Student* newStudents = new Student[newSize];
    // memcpy(newStudents, students, sizeof(Student)*size);     => shallow copy 
    //2. copy elements from students array into newStudents array => deep copy
    for(int i=0; i<size; i++) {
        newStudents[i] = students[i]; 
    }
    //3. delete [] students
    delete[]students;
    //4. students should point to the same address as newStudents (students == newStudents) 
    students = newStudents;

    for(int i=size; i<newSize; i++) {
        cout << "STUDENT " << i+1 << endl;

        Student s;
        cout << "Name: "; cin >> s.Name;
        cout << "Age: "; cin >> s.Age;
        cout << "Gender: "; cin >> s.Gender;
        cout << "Programming grade: "; cin >> s.ProgrammingGrade;

        students[i] = s;
    }

    // printStudents(students, size);
    printStudents(students, newSize);

    delete [] students;
    cin.get();
}