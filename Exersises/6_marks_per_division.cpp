//calculate the total marks, percentage and division of student
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int rollNo, phy, che, it, total;
    float percentage;
    char name[30], div[10];

    cout << "Input the roll Number of the student: ";
    cin >> rollNo;

    cout << "Input the Name of the student: ";
    cin >> name;

    cout << "Input the marks of Physics, Chemistry and Information tech...: ";
    cin >> phy >> che >> it;

    total = phy + che + it;
    percentage = total / 3.0;

    if(percentage > 60) {
        strcpy(div, "First"); //copy "First" vào mảng ký tự div có 10 p.tu
    }
    else if (percentage <= 60 && percentage > 48) {
        strcpy(div, "Second");
    }
    else if (percentage <= 48 && percentage > 36) {
        strcpy(div, "Pass");
    }
    else
        strcpy(div, "Fail");

    cout << "Roll no: " << rollNo << '\n';
    cout << "Name of student's: " << name << '\n';
    cout << "Marks in Physics: " << phy << '\n';
    cout << "Marks in Chemistry: " << che << '\n';
    cout << "Marks in Information tech: " << it << '\n';
    cout << "==========================" << '\n';
    cout << "\tTotal marks = " << total << '\n';
    cout << "\tPercentage = " << percentage << '\n';
    cout << "\tDivision = " << div << '\n';

    return 0;
}