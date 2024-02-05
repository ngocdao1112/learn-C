#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//https://www.youtube.com/watch?v=aP1ijjeZc24
//truyền tham số từ dòng lệnh khi bạn chạy một chương trình trong môi trường cmd
// int main(int argc, char* argv[]) {
//     for(int i=0; i<argc; i++) {
//         printf("argv[%d]: %s\n", i, argv[i]);
//     }

//     int result = 1;
//     for(int i=1; i<argc; i++) {
//         int x = strtol(argv[i], NULL, 10); //chuyển đổi chuỗi số ở argv[i] thành số nguyên và gán vào biến x.
//         result = result * x;
//     }
//     printf("Multiplication result is %d\n", result);

//     return 0;
// }

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    // In ra tên chương trình (đối số đầu tiên)
    std::cout << "Program name: " << argv[0] << std::endl;

    // In ra các đối số cụ thể (nếu có)
    if (argc > 1) {
        std::cout << "Other arguments: " << std::endl;
        for (int i = 1; i < argc; ++i) {
            std::cout << "  Argument " << i << ": " << argv[i] << std::endl;
        }
    } 
    else {
        std::cout << "No additional arguments." << std::endl;
    }

    cin.get();

    return 0;
}
