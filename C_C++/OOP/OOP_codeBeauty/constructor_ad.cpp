#include <iostream>
#include <list>
using namespace std;

class User {
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;

    // default constructor, empty
    User() {
        FirstName = "nn";
        LastName = "nln";
        Age = 0;
        Email = "not set";
    }

    //parameter constructor
    User(string fName, string lName, int age) {
        FirstName = fName;
        LastName = lName;
        Age = age;
        Email = fName+"."+lName+"@gmail.com";
    }

};

void GetUserInfo(User u) {
    cout << "First Name: " << u.FirstName << endl;
    cout << "Last Name: " << u.LastName << endl;
    cout << "Age: " << u.Age << endl;
    cout << "Email: " << u.Email << endl;
}

int main() {
    User user1("Ngoc", "dao", 24);
    User user2("Trieu", "ho", 23);
    User user3;
    User user4;
    // cout << "First Name: " << user2.FirstName << endl;
    // cout << "Last Name: " << user2.LastName << endl;
    // cout << "Age: " << user2.Age << endl;
    // cout << "Email: " << user2.Email << endl;

    GetUserInfo(user1);
    GetUserInfo(user2);
    GetUserInfo(user3);
    GetUserInfo(user4);

    cin.get();
}

/*
1. cùng tên với class
2. kiểu void
3. được gọi khi object của 1 class được gọi
4. đc đặt ở phần public của class
5. có tham số
6. ko có tham số
7. nếu k tạo thì trong class tự có constructor default
*/