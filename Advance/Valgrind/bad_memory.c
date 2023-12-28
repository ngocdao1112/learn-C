/*
- Gỡ lỗi lỗi bộ nhớ
- Kiểm tra hiệu suất: mã chậm
- Phân tích lỗi logic: sử dụng giá trị không khởi tạo

#include <iostream>

void memoryLeak() {
    int* dynamicArray = new int[5];
    // Forgot to delete dynamicArray, causing a memory leak
    // delete[] dynamicArray; // Uncomment this line to fix the memory leak
}

void useAfterFree() {
    int* dynamicNumber = new int;
    *dynamicNumber = 42;
    delete dynamicNumber;
    // Accessing dynamicNumber after it has been deleted
    std::cout << "Value: " << *dynamicNumber << std::endl; // Causes use-after-free error
}

int main() {
    memoryLeak();
    useAfterFree();

    return 0;
}

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Example of what not to do with dynamic memory!
// https://www.youtube.com/watch?v=bb1bTJtgXrI&list=PLGvfHSgImk4ZZq5KWX0mGT0kgwy9-I-Qe
void test1() {
    const int NUM_HEIGHTS = 3;
    // int *heights = malloc(NUM_HEIGHTS);
    // int *heights = malloc(NUM_HEIGHTS*sizeof(int));
    int *heights = malloc(NUM_HEIGHTS * sizeof(*heights));
    for(int i=0; i < NUM_HEIGHTS; i++) {
        heights[i] = i*i;
        printf("%d: %d\n", i, heights[i]);
        // free(heights);
    }
    free(heights);
}

void test2() {
    const int NUM_WEIGHTS = 5;
    long long *weights = malloc(NUM_WEIGHTS * sizeof(weights));
    for(int i=0; i < NUM_WEIGHTS; i++) {
        weights[i] = 100+i;
        printf("%d: %lld\n", i, weights[i]);
    }
    free(weights);
    weights[0] = 0;
}

//algrind --leak-check=full ./bad_memory
void test3() {
    const int NUM_HEIGHTS = 10;
    long long *heights = malloc(NUM_HEIGHTS * sizeof(heights));
    for(int i=0; i < NUM_HEIGHTS; i++) {
        // if((heights = NULL)) {
        // if(heights = NULL) { error
        if(heights == NULL) {
            heights = malloc(NUM_HEIGHTS * sizeof(*heights));
        }
    }
    free(heights);
}

char *getString() {
    char message[100] = "Hello world!";
    char *ret = message;
    return ret;
}

void test4() {
    printf("String: %s\n", getString());
}

int main(int argc, char *args[]) {
    // test1();
    // test2();
    // test3();
    test4();

    // system("pause > 0");
    return 0;


}
