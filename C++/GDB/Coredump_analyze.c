/*
- là quá trình phân tích và điều tra thông tin được lưu trữ trong core dump khi một chương 
trình thoát không mong muốn hoặc gặp lỗi. Core dump là một trạng thái tương tự như 
"bảng xanh" trên Windows, là một tệp chứa trạng thái của bộ nhớ và các biến khi một lỗi 
xảy ra trong chương trình.

- Core dump analysis giúp định rõ lý do khiến chương trình gặp sự cố, giúp lập trình 
viên hiểu và sửa lỗi một cách hiệu quả.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <unistd.h>
#include <time.h>

int main() {
    int rnum = 0;
    int *goodptr = malloc(sizeof(int));
    int *badptr = NULL;

    srand(time(NULL));
    while (true){
        rnum = rand() % 255;
        if (rnum == 13){
            *badptr = rnum;
        } 
        else {
            *goodptr = rnum;
        }
        printf("random: %d\n", rnum);
        usleep(1000);
    }
    
}

/*
- Segmentation faults in C or C++ is an error that occurs when a program attempts to access a memory 
location it does not have permission to access.

- The core dump refers to the recording of the state of the program, i.e. its resources in memory and processor.

- When a piece of code tries to do a read-and-write operation in a read-only location in memory or 
freed block of memory, it is known as a segmentation fault.

- It is an error indicating memory corruption.

Common Segmentation Fault Scenarios:
    - Modifying a string literal
    - Accessing an address that is freed
    - Accessing out-of-array index bounds
    - Improper use of scanf()
    - Stack Overflow 
    - Dereferencing uninitialized pointer 

*/

/*
// C program to demonstrate segmentation fault
// by modifying a string literal
#include <stdio.h>
 
int main()
{
    char* str;
 
    // Stored in read only part of data segment //
    str = "GfG";
 
    // Problem:  trying to modify read only memory //
    *(str + 1) = 'n';
    return 0;
}
*/

/*
// C program to illustrate the 
// segementation fault due to
// buffer overflow
#include <stdio.h>

int main()
{
	char ref[20] = "This is a long string";
	char buf[10];
	sscanf(ref, "%s", buf);
	return 0;
}
*/

