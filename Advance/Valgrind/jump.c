// #include <iostream>
#include <stdio.h>

int main() {
    int x;
    int y = 2;

    if (y > 5) {
        x = 5;
    }

    // std::cout << x << std::endl;
    printf("%d ", x);
    return 0;
}
//Nếu điều kiện y > 5 không được đáp ứng, giá trị của x không được 
//gán và sẽ chứa giá trị ngẫu nhiên từ bộ nhớ.