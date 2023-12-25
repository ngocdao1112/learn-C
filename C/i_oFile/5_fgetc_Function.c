#include <stdio.h>
#include <conio.h>
#include <string.h>
//fgetc(): đọc từng ký tự từ tệp có sẵn content
int main() {
    FILE *pf;
    char ch;

    pf = fopen(".//txt//fgetc.txt", "r");
    if(pf == NULL) {
        printf("Unable to open the file\n");
    }
    else {
        while(!feof(pf)) {
            ch = fgetc(pf);
            printf("%c", ch);
        }
        fclose(pf);
    }

    getch();
    return 0;
}