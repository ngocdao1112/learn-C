#include <iostream>
using namespace std;
/*
int a = 5; // 101
2 bytes = 16 bits
101 -> 3 bits
-> 13 bits wasted
=> to avoid this > BIT-fields
Condition:
    - structure / union member
    - Unsigned interger
*/
    // void main() {
    //     struct time {
    //         unsigned int hours: 5; // int = 4 byte = 32 bit = 2^32 = ...number
    //                                 // 2^(5bit) = 32 numbers
    //         unsigned int minutes: 5;
    //         unsigned int seconds: 5;
    //     };

    //     struct time t = {10, 20, 45};
    //     printf("displays time as");
    //     printf("%d : %d : %d", t.hours, t.minutes, t.seconds);
        
    // }

//Bit fields được sử dụng để giảm sie of class/struct nếu chúng ta có thể
    // struct Date {
    //     unsigned int d : 5;
    //     unsigned int m : 4;
    //     unsigned int y;
    // };
    // int main() {
    //     Date d;
    //     d.d = 8; d.m = 8; d.y = 1989;
    //     cout << d.d << "/" << d.m << "/" << d.y << endl;
    //     cout << sizeof(Date) << endl;

    //     return 0;
    // }