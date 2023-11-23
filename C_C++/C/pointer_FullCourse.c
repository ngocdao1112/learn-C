// #include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//change value #1
    // int main() {
    //     int a = 10;
    //     int* p = &a;
    //     printf("a= %d\n", a); //a=10
    //     *p=12;
    //     printf("a= %d\n", a); //a=12
    // }
//change value #2
    // int main() {
    //     int a=10; int *p;
    //     p= &a;
    //     printf("Address of P is %d\n", p); //123123
    //     printf("Value at p is %d\n", *p); //10
    //     int b= 20;
    //     *p = b; //assign value of b for vùng nhớ pointer p đang trỏ đến
    //     printf("Adress of P is %d\n", p); //123123
    //     printf("Value at p is %d\n", *p); //12
    // }
//Pointer arithemetic
    // int main() {
    //     int a=10;
    //     int* p = &a;
    //     printf("Adress of p is %d\n", p); //p is 2002
    //     printf("Value at address p is %d\n", *p); //10
    //     printf("size of integer is %d bytes\n", sizeof(int)); //4 bytes
    //     printf("Adress p+1 is %d\n", p+1); //p+1 is 2006
    //     printf("Value at address p+1 is %d\n", *(p+1)); //123123
    // }
// int pointer -> Chỉ có thể trỏ đến kiểu dữ liệu là int.
    // int main() {
    //     int a = 1025;
    //     int *p = &a;
    //     printf("size of integer is %d bytes\n", sizeof(int)); //4 bytes
    //     printf("Address = %d, value = %d\n", p, *p); //add is 11112222, value is 1025
    //     printf("Address = %d, value = %d\n", p+1, *(p+1)); //add is 11112226, value is 123123
    //     char *p0;
    //     p0 = (char*)p; //typecasting
    //     printf("size of integer is %d bytes\n", sizeof(char)); //1 bytes
    //     printf("Address = %d, value = %d\n", p0, *p0); //add is 11112222, value is 1
    //     //1025 = 0000.0000 0000.0000 0000.0100 0000.0001
    //     //..0100 0000.0001 = 1*2^0 + 0.2^1 + 0*2^2 + ...+ 1*2^10 = 1025 (from binary to decimal)
    //     printf("Address = %d, value = %d\n", p0+1, *(p0+1)); //add is 11112223, value is 4
    //     //0000.0001 = p0+0; 0000.0100 = p0+1 = 0*2^0 + 0*2^1 + 1*2^2... = 4
    // }
//void pointer -> Có thể trỏ đến bất kỳ kiểu dữ liệu nào.
    // int main() {
    //     int a = 1025;
    //     int *p = &a;
    //     printf("size of integer is %d bytes\n", sizeof(int));
    //     printf("Address = %d, value = %d\n", p, *p); //Address = 402652188, value = 1025
    //     void *p0;
    //     p0 = p;
    //     // printf("Address = %d, value = %d\n", p0, *p0);
    //     printf("Address = %d", p0); //Address = 402652188
    // }
//pointer to pointer
    // int main() {
    //     int x = 5;
    //     int* p= &x;
    //     *p = 6;
    //     int** q = &p;
    //     int*** r = &q; 
    //     printf("%d\n", *p); //6
    //     printf("%d\n", *q); //address p
    //     printf("%d\n", *(*q)); //6
    //     printf("%d\n", *(*r)); //address q
    //     printf("%d\n", *(*(*r))); //6
    //     ***r = 10;
    //     printf("x= %d\n", x); //x=10
    //     **q = *p + 2;
    //     printf("x= %d", x); //x=12
    // }
//pointer to function arguments - call by reference
    // void Increment(int a) { //a is local variable
    //     a = a + 1;
    //     printf("Address if variable a in increment = %d\n", &a); //1111
    // }
    // int main() {
    //     int a; //local variable
    //     a = 10;
    //     Increment(a); //instead of a = a + 1
    //     printf("Address if variable a in increment = %d\n", &a); //2222
    //     // printf("a= %d", a); //why = 10?
    // }

    // void Increment(int x) { //a is local variable
    //     x = x + 1;
    //     printf("Address if variable a in increment = %d\n", &x); //1111
    // }
    // int main() {
    //     int a; //local variable
    //     a = 10;
    //     Increment(a); //instead of a = a + 1
    //     printf("Address if variable a in increment = %d\n", &a); //2222
    //     printf("a= %d", a); //why = 10?
    // }
//pointer to arrays
    //element at index i:
        //address - &A[i] or (A+i)
        //value - A[i] or *(A+i)
    // int main() {
    //     int A[] = {2, 4, 5, 8, 1};
    //     int *p = A;
    //     //A++; //Invalid -> Lỗi: Mảng là một biến cố định, không thể thay đổi địa chỉ của mảng trực tiếp
    //     p++; // Valid -> Hợp lệ: Con trỏ p có thể thay đổi để trỏ đến phần tử khác trong mảng
    //     for (int i=0; i<5; i++) {
    //         printf("Address = %d\n", &A[i]);
    //         printf("Address = %d\n", A+i);
    //         printf("Value = %d\n", A[i]);
    //         printf("Value = %d\n", *(A+i));
    //         // printf("Address = %d\n", *(p+i));
    //     }
    // }
//Arrays as function arguments
    //TRUE
    // int sumOfElements(int A[], int size) {
    //     int sum = 0;
    //     for (int i=0; i<size; i++) {
    //         sum += A[i];
    //     }
    //     return sum;
    // }
    // int main() {
    //     int A[] = {1, 2, 3, 4, 5};
    //     int size = sizeof(A)/sizeof(A[0]);
    //     int total = sumOfElements(A, size);
    //     printf("Sum of elements = %d\n", total); // = 15
    // }
    //FALSE
    // int sumOfElements(int A[]) {
    //     int sum = 0;
    //     int size = sizeof(A)/sizeof(A[0]);
    //     printf("SOE - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0])); // A= 4 bytes, A[0]= 4 bytes
    //     for (int i=0; i<size; i++) {
    //         sum += A[i];
    //     }
    //     return sum;
    // }
    // int main() {
    //     int A[] = {1, 2, 3, 4, 5};
    //     // int size = sizeof(A)/sizeof(A[0]);
    //     int total = sumOfElements(A);
    //     printf("Sum of elements = %d\n", total); // = 1
    //     printf("Main - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0])); // A= 20 bytes, A[0]= 4 bytes
    // }
    //FALSE -> TRUE
    // int sumOfElements(int* A, int size) { //"int *A" or "int A[]" ..it's the same.
    //     int sum = 0;
    //     printf("SOE - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0])); // A= 4 bytes for PC has 32 bits, A= 8 bytes for PC has 64 bits
    //                                                                                     // A[0]= 4 bytes
    //     for (int i=0; i<size; i++) {
    //         sum += A[i]; //A[i] is *(A+i)
    //     }
    //     return sum;
    // }
    // int main() {
    //     int A[] = {1, 2, 3, 4, 5};
    //     int size = sizeof(A)/sizeof(A[0]);
    //     int total = sumOfElements(A, size); // A can be used for &A[0]
    //     printf("Sum of elements = %d\n", total); // = 15
    //     printf("Main - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0])); // A= 20 bytes, A[0]= 4 bytes
    // }
    //ANOTHER (void)
    // void Double(int* A, int size) { //"int *A" or "int A[]" ..it's the same.
    //     for (int i=0; i<size; i++) {
    //         A[i] = 2*A[i];
    //     }
    // }
    // int main() {
    //     int A[] = {1, 2, 3, 4, 5};
    //     int size = sizeof(A)/sizeof(A[0]);
    //     Double(A, size);
    //     for (int i=0; i<size; i++) {
    //         printf("%d ", A[i]);
    //     }
    // }
//character arrays and pointers - PART I
    //1. how to store strings, size of array >= char in string + 1
    //rule: '\0' is null in string, "John" : size >= 5 
        // int main() {
        //     char C[20];
        //     C[0] = 'J';
        //     C[1] = 'O';
        //     C[2] = 'H';
        //     C[3] = 'N';
        //     C[4] = '\0';
        //     printf("%s\n", C);
        //     int len = strlen(C);
        //     printf("Length = %d\n", len);
        // }

        // int main() {
        //     //char C[4] = "JOHN"; //error
        //     char C[] = "JOHN";
        //     char C[] = {'J', 'O', 'H', 'N', '\0'};
        //     printf("Size in bytes = %d\n", sizeof(C)); //5
        //     int len = strlen(C);
        //     printf("Length = %d\n", len); //4, because size null ko được tính vào độ dài
        // }
    //2. arrays & pointer are different types that are used in similar manner
        // int main() {
        //     char C1[6] = "Hello"; //khi viết string thì ngầm định có null
        //     char* C2;
        //     C2 = C1;
        //     printf("%c\n", C2[1]); //e
        //     C2[0] = 'A';
        //     printf("%s\n", C1); //Aello
        //     C2++;
        //         // C2[i] is *(C2+i);
        //         // C1[i] or *(C1+i);
        // }
    //3. Arrays are always passed to function by reference
    //array làm đối số của function
        // void print(char* C) {
        //     // int i = 0;
        //     // while (C[i] != '\0') { //C[i] = *(C+i)
        //     while (*C != '\0') {
        //         //printf char at address pointer C
        //         printf("%d", *C);
        //         // i++;
        //         C++;
        //     }
        //     printf("\n");
        // }
        // int main() {
        //     char C[20] = "Hello";
        //     printf(C);
        // }
//character arrays and pointers - PART II
    //  void print(const char *C) {
    // void print(char *C) {
    //     while (*C != '\0') {
    //         printf("%c", *C);
    //         C++;
    //     }
    //     printf("\n");
    // }
    // int main() {
    //     char C[20] = "Hello"; // string gets stored in the space for array
    //     // char *C = "Hello"; // string gets stored as compile time constant
    //     print(C);
    // }

    // void print(char *C) {
    //     C[0] = 'A';
    //     while (*C != '\0') {
    //         printf("%c", *C);
    //         C++;
    //     }
    //     printf("\n");
    // }
    // int main() {
    //     char C[20] = "Hello";
    //     print(C); // Aello
    // }
//Pointers and multi-dimensinal arrays
    // void Func(int *A) { //argument: 1D array of integers
    // }
    // int main() {
    //     int C[3][2][2] = {{{2,5}, {7,9}},
    //                     {{3,4}, {6,1}},
    //                     {{0,8},{11,13}}};
    //     int A[2] = {1,2};
    //     int B[2][3] = {{2,4,6}, {5,7,8}}; //B returns int (*)[3]
    //     Func(A); // A return int*
    // }

    // void Func(int (*A)[3]) { //argument: 2D array of integers
    // }
    // int main() {
    //     int C[3][2][2] = {{{2,5}, {7,9}},
    //                     {{3,4}, {6,1}},
    //                     {{0,8},{11,13}}};
    //     int A[2] = {1,2};
    //     int B[2][3] = {{2,4,6}, {5,7,8}}; //B returns int (*)[3]
    //     Func(A); // A return int*
    // }
//POINTER & DYNAMIC MEMORY - STACK & HEAP: 
/*Kiến trúc đc chia thành 4 phân đoạn:
    1. Heap
    2. Stack -> function calls local variable
    3. Static/Global -> lưu trữ all các biến static or biến global
                        các biến k đc khai báo bên trong hàm -> để có thể access anywhere
    4. Code(text) -> lưu trữ lệnh cần thực thi
*/
//2. Stack -> function calls local variable
    // int total; //-> global variable
    // int Square(int x) {
    //     return X*X;
    // }
    // int SquareOfSum(int x, int y) {
    //     int z = Square(x+y); //2 đối số x, y
    //     return z; //(x+y)^2
    // }
    // int main() {
    //     int a = 4, b =8;
    //     total = SquareOfSum(a, b);
    //     printf("ouput = %d", total);
    // }
//1. Heap
    /*- Heap đc gọi là dynamic memory:
        + sử dụng heap gọi là cấp phát bộ nhớ động
        + heap cũng đc gọi là cấu trúc dữ liệu (học chỗ khác)
        + stack cũng dc gọi là cấu trúc dữ liệu, vì phân đoạn nên nó gọi là cấu trúc dữ liệu stack
        + C:
            - malloc, calloc, realloc, free >>>> functions
        + C++:
            - new, delete >>>>operators
        + Muốn lưu trữ 1 số nguyên trên heap,cần gọi hàm malloc, cho tôi 1 bộ nhớ 4 bytes, vậy 1 block 4 bytes sẽ đc dành riêng or phân bổ trên heap
        và malloc sẽ trả về 1 con trỏ đến địa chỉ bắt đầu của block này và malloc trả về pointer void
        + giả sử địa chỉ bắt đầu của khối 4 bytes này là 200 thì malloc sẽ trả về địa chỉ cho chúng ta là 200
        khai báo pointer p thì p sẽ nằm trên stack và lấy address là 200 ở block 4 bytes của heap
        + Trên thực tế, cách duy nhất để sd bộ nhớ trên heap là thông qua tham chiếu,
        hàm malloc tìm kím 1 space trống trong heap đặt chỗ cho bạn và trả lại con trỏ
        người lập trình cần xóa mọi thứ trên heap nếu ta đã phân bổ nó và k cần thêm nữa
        + Nếu malloc k tìm thấy bộ nhớ nào trên heap thì sẽ trả về null, vậy nên
            - in C: hãy viết malloc và free valid
            - in C++: dùng new & delete
    */
    //heap in C:
        // int main() {
        //     int a; //goes on stack
        //     int *p;
        //     p = (int*)malloc(sizeof(int));
        //     *p = 10;
        //     free(p);
        //     p = (int*)malloc(20*sizeof(int));
        //     // *p = 20;
        // }
    //heap in C++:
        // int main() {
        //     int a; //goes on stack
        //     int *p;
        //     p = new int;
        //     *p = 10;
        //     delete p;
        //     p = new int[20];
        //     delete[] p;
        // }

//Pointers as function returns
    // int Add(int a, int b) { //called function
    //     printf("Address of a in Add = %d\n", &a);
    //     int c = a+b;
    //     return c;
    // }
    // int main() { //calling function
    //     // int x = 2, y = 4;
    //     int a = 2, b = 4;
    //     printf("Address of a in Main = %d\n", &a);
    //     // int z = Add(x,y); // value in x of main is copied to a of Add
    //                         // value in y of main is copied to b of Add
           //call by value
    //     int z = Add(a,b);   
    //     printf("Sum = %d\n", z); // 6
    // }

    // int Add(int* a, int* b) { //called function
    //     // a and b pointer to integers local to Add
    //     printf("Address of a in Add = %d\n", &a);
    //     printf("Value in a of Add (address of a of main) = %d\n", a);
    //     printf("Value at address stored in a of Add = %d\n", *a);
    //     int c = (*a) + (*b);
    //     return c;
    // }
    // int main() { //calling function
    //     int a = 2, b = 4;
    //     printf("Address of a in Main = %d\n", &a);
            //call by reference
    //     int z = Add(&a, &b); // a and b are integers local to Main
    //     printf("Sum = %d\n", z); // 6
    // }
int* Add(int* a, int* b) { //called function - returns pointer to integer
    int* c = (int*)malloc(sizeof(int));
    *c = (*a + *b);
    return c;
}
int main() { //calling function
    int a = 2, b = 4;
    int* ptr = Add(&a, &b); // a and b are integers local to Main
    printf("Sum = %d\n", *ptr); 
}

int* Add(int* a, int* b) { //called function - returns pointer to integer
    int c = (*a) + (*b);
    return c;
}
int main() { //calling function
    int a = 2, b = 4;
    int* ptr = Add(&a, &b); // a and b are integers local to Main
    printf("Sum = %d\n", *ptr); 
}
// void PrintHelloWorld() {
//     printf("Hello World\n");
// }
// int* Add(int* a, int* b) { //called function - returns pointer to integer
//     int c = (*a) + (*b);
//     return &c;
// }
// int main() { //calling function
//     int a = 2, b = 4;
//     int* ptr = Add(&a, &b); // a and b are integers local to Main
//     PrintHelloWorld();
//     printf("Sum = %d\n", *ptr); 

// }