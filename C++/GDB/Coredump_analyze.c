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
#include <unistd.h>
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