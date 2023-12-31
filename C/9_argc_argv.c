#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//https://www.youtube.com/watch?v=aP1ijjeZc24
//truyền tham số từ dòng lệnh khi bạn chạy một chương trình trong môi trường cmd
int main(int argc, char* argv[]) {
    for(int i=0; i<argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    int result = 1;
    for(int i=1; i<argc; i++) {
        int x = strtol(argv[i], NULL, 10); //chuyển đổi chuỗi số ở argv[i] thành số nguyên và gán vào biến x.
        result = result * x;
    }
    printf("Multiplication result is %d\n", result);

    return 0;
}