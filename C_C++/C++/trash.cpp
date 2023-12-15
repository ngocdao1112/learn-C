#include <iostream>
#include <random>
using namespace std;


//VD1
    // int add(int a, int b) { //0fxx
    //     return a+b;
    // }
    // int main() {
    //     int result;
    //     int (*ptr)(int, int) = &add;
    //     result = (*ptr)(10, 20);
        
    //     printf("%d", result);
    // }
//VD2
    float sum(float a, float b) {return a+b;}
    float sub(float a, float b) {return a-b;}
    float mult(float a, float b) {return a*b;}
    float divi(float a, float b) {return a/b;}
    // //traditional
    // int main() {
    //     int choice;
    //     float a, b, result;
    //     printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
    //     scanf("%d", &choice);
    //     printf("Enter two numbers:\n");
    //     scanf("%f %f", &a, &b);
    //     switch(choice) {
    //         case 0: 
    //             result = sum(a, b); break;
    //         case 1: 
    //             result = sub(a, b); break;
    //         case 2: 
    //             result = mult(a, b); break;
    //         case 3: 
    //             result = divi(a, b); break;
    //     }
    //     printf("%f", result);
    //     result 0;
    // }
//new program
#define ops 4
int main() { //*p[4](float, float)
    float (*ptr2func[ops])(float, float) = {sum, sub, mult, divi}; //mảng chứa con trỏ hàm
    int choice;
    float a, b;
    printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
    scanf("%d", &choice);
    printf("Enter two numbers:\n");
    scanf("%f %f", &a, &b);
    printf("%f", ptr2func[choice](a, b));
    
    return 0;
}
