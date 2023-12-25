#include <stdio.h>
#include <conio.h>
#include <string.h>
//fputs(input, pf); //ghi chuỗi từ input vào tệp tin đã mở
int main() {
        FILE *pf;
        char input[50];

        pf = fopen(".//txt//fputs.txt", "w");

        if(pf == NULL) {
            printf("Unable to create the file\n");
        }
        else {
            printf("Enter a string to write to the file\n");
            // gets(input); -> đã bị loại bỏ 
            fgets(input, sizeof(input), stdin); // fgets: được sử dụng để đọc chuỗi từ bàn phím 'stdin' và lưu vào mảng 'input'
                                                // sizeof(input): giúp tránh tràn bộ đệm.
            fputs(input, pf); //ghi chuỗi từ input vào tệp tin đã mở
            printf("Data has writte successfully\n");
            fclose(pf);
        }
        
        getch();
        return 0;
    }