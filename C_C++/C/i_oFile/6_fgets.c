#include <stdio.h>
#include <conio.h>
#include <string.h>
//fgets(variable_to_store, length, file_pointer)
//fgets: đọc một dòng (hoặc chuỗi ký tự) từ một tệp tin hoặc từ bàn phím
//       đọc một dòng đầy đủ kể cả ký tự xuống dòng ('\n') 
int main() {
    FILE *pf;
    char data[15];

    pf = fopen(".//txt//fgets.txt", "r");

    if(pf == NULL) {
        printf("Unable to open the file\n");
    }
    else {
        while(!feof(pf)) {
            fgets(data, 15, pf);
            printf("The characters readed were: %s", data);
        }
        fclose(pf);
    }

    getch();
    return 0;
}