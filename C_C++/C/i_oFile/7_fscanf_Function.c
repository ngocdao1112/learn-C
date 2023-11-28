#include <stdio.h>
#include <conio.h>
#include <string.h>
//fscanf(file_pointer, "format string", list of address of variables)
//Đọc thông tin với định dạng từ tệp tin
int main() {
    FILE *pf;
    // char data[10];
    int age;
    char name[10];

    //fscanf(file_pointer, "format string", list of address of variable)
    pf = fopen(".//txt//fscanf.txt", "r");

    if(pf == NULL) {
        printf("Unable to open the file\n");
    }
    else {
        // fscanf(pf, "%s %s", data, name);
        // printf("%s %s", data, name);
        fscanf(pf, "%s\t%d", name, &age);
        printf("%s\t%d", name, age);

        fclose(pf);
    }

    getch();
    return 0;
}