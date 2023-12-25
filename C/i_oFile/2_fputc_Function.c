#include <stdio.h>
#include <conio.h>
#include <string.h>
// #include <iostream>
// #include <fstream>
// using namespace std;

////fputc: ghi một ký tự vào tệp tin
int main() {
    FILE *Fpointer;
    char data[50] = "Learning C with fput function";
    int length = strlen(data); //strlen: tính độ dài của chuỗi và lưu vào biến 'length'
    int counter;

    Fpointer = fopen(".//txt//fputc.txt", "w");

    if(Fpointer == NULL) {
        printf("Unable to create or open the file");
    }
    else {
        for(counter = 0; counter < length; counter++) {
            printf("Writing the character %c \n", data[counter]);
                fputc(data[counter], Fpointer); //fputc: ghi một ký tự vào tệp tin
        }
        printf("data written to the file successfully");
        fclose(Fpointer);
    }

    getch(); //dừng screen để xem notify
    return 0;
}