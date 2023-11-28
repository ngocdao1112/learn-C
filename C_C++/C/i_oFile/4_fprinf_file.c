#include <stdio.h>
#include <conio.h>
#include <string.h>
//fprintf: Ghi thông tin với định dạng vào tệp tin
//fprintf(file_pointer, "format specifier", list of variables);
int main() {
    FILE *pf;
    char name[50];
    int age;
    printf("Enter your name and age\n");
    scanf("%s%d", name, &age);

    pf = fopen(".//txt//fprint.txt", "a");

    if(pf == NULL) {
        printf("Unable to open the file\n");
    }
    else {
        fprintf(pf, "%s\t%d\n", name, age);
        printf("data written successfully\n");
        fclose(pf);
    }

    getch();
    return 0;
}