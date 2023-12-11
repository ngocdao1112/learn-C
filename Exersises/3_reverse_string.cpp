//reverse a string enter by user
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_SIZE 100 //maximum size of the string

int main() {
    int i, j, length;
    char string[MAX_SIZE];
    char reverse[MAX_SIZE];

    cout << "Enter a string: ";
    // cin >> string; //chỉ nhận một phần của chuỗi đến khi gặp dấu cách hoặc ký tự xuống dòng
    cin.getline(string, MAX_SIZE);

    length = strlen(string);
    j=0;

    for(i=length-1; i>=0; i--) {
        reverse[j] = string[i];
        j++;
    }

    reverse[j] = '\0'; //Đảm bảo kết thúc chuỗi đảo ngược
    cout << "Reversed string: " << reverse;

    return 0;
}
/*
length = strlen(ngoc) = 4;

j=0; i=4-1=3; => reverse[0] = string[3] = c
j=1; i=3-1=2; => reverse[1] = string[2] = o
...

*/