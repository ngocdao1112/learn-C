#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

/*
File I/O trong C/C++ (Input/Output) là quá trình đọc và ghi dữ liệu từ và vào các tệp tin (file)

1. Lưu trữ và khôi phục dữ liệu:
    - Cho phép lưu trữ dữ liệu của chương trình để sử dụng ở các lần chạy sau.
    - Cho phép khôi phục dữ liệu từ các phiên làm việc trước.
2. Tương tác với tệp tin hệ thống:
    - Cho phép chương trình đọc và ghi dữ liệu từ và vào các tệp tin hệ thống.
3. Truyền dữ liệu giữa các chương trình:
    - Các chương trình có thể sử dụng file I/O để truyền dữ liệu giữa chúng.
*/
/* create of a new file, opening, reading, writing data in a file, closing a file.
 steps for processing a file
 1. Declare a file pointer variable
 2. open a file using fopen() 
 3. process the file using the suitable function 
 4. close the file using fclose() function 

 1. fopen, fclose
 2. getc: đọc 1 ký tự từ 1 tệp, đọc các ký tự từ 1 tệp
 3. putc: ghi 1 ký tự vào 1 tệp
 4. getw: đọc 1 số nguyên từ 1 tệp, lấy 1 số nguyên từ 1 tệp
 5. putw: ghi 1 số nguyên vào 1 tệp
 6. fprintf, fscanf
 7. fgets: nhận 1 chuỗi ký tự đã đọc từ 1 tệp
 8. fputs: viết chuỗi ký tự vào 1 tệp
 9. feof: phát hiện và đánh dấu trong 1 tệp duy nhất
*/
// C:
/*
1. "r" (read):
    Mở tệp tin để đọc.
    Tệp tin phải tồn tại, nếu không hàm mở sẽ thất bại.

2. "w" (write):
    Mở tệp tin để ghi.
    Nếu tệp tin tồn tại, nó sẽ bị xóa và tạo lại. Nếu không tồn tại, tạo một tệp tin mới.

3. "a" (append):
    Mở tệp tin để thêm vào cuối.
    Nếu tệp tin tồn tại, con trỏ ghi được đặt ở cuối tệp tin. Nếu không tồn tại, tạo một tệp tin mới.

4. "r+" (read and write):
    Mở tệp tin để đọc và ghi.
    Tệp tin phải tồn tại, nếu không hàm mở sẽ thất bại.

5. "w+" (read and write):
    Mở tệp tin để đọc và ghi.
    Nếu tệp tin tồn tại, nó sẽ bị xóa và tạo lại. Nếu không tồn tại, tạo một tệp tin mới.

6. "a+" (read and append):
    Mở tệp tin để đọc và thêm vào cuối.
    Nếu tệp tin tồn tại, con trỏ đọc và ghi được đặt ở cuối tệp tin. Nếu không tồn tại, tạo một tệp tin mới.
*/
//File handling in C:
    int main() {
        FILE *Fpointer;
        Fpointer = fopen(".//txt//File_handling.txt", "w"); //Unable to create the file
        // Fpointer = fopen(".//txt//LearnC.txt", "w"); //File opened successfully
        // Fpointer = fopen(".//txt//LearnC.txt", "a"); //File opened successfully
        if(Fpointer == NULL) {
            printf("Unable to create the file");
        }
        else {
            printf("File opened successfully");
        }

        fclose(Fpointer);
        
        getch();
        return 0;
    }

// C++:
    // int main() {
    //     // Mở tệp tin để đọc
    //     ifstream inFile("example.txt", ios::in);
    //     // Mở tệp tin để ghi
    //     ofstream outFile("example.txt", ios::out);
    //     // Mở tệp tin để thêm vào cuối
    //     fstream appendFile("example.txt", ios::app);

    //     // Các thao tác đọc và ghi có thể được thực hiện trên các đối tượng inFile, outFile, và appendFile.

    //     inFile.close();
    //     outFile.close();
    //     appendFile.close();

    //     return 0;
    // }
