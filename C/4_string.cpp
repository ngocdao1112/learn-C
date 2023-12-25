#include <iostream>
//note1:
/* char *ptr = "Hello"

"Hello"[1] = pointer to 'H'[1]

H       e       l       l       o       \0
1000    1001    1002    1003    1004    1005

pointer to 'H'[1] = *(pointer to 'H' + 1)
pointer to 'H'[1] = *(1000+1) = *(1001) = 'e'
*/
//note2:
// char *ptr = "Hello";
// *ptr = 'M'; //-> not allowed, because read only memory

//Declaring and Initializing String Variables
//note3: 
/*
char s[6] = "Hello";
char s[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
recall: 
we cannot modify a string litreal
char *ptr = "Hello";
*ptr = 'M'; => error
But we can modify a char array
char s[6] = "Hello";
s[0] = 'M';
*/
//note 4:
/*
int main() {
    char s[5] = "Hello"; // false
    char t[5];
    char s[6] = "Hello"; // true
    char t[6];
    for (int i=0; s[i] != '\0'; i++) {
        t[i] = s[i];
    }
    t[5] = '\0';
    printf("%s", t);

    return 0;
}
*/
/*
//Writing Strings using printf and puts Functions
//note1:
char *ptr = "Hello World";
printf("%s", ptr); // ouput: Hello World
//note2:
char *ptr = "Hello World";
printf("%.5s, ptr"); //%.ns
// ouput: Hello
//note3:
char *ptr = "Hello World";
printf("%.5s, ptr"); 
printf("%6.5s, ptr"); //%m.ns
// ouput: Hello
//      :  Hello (tính từ trái qua)
//note4:
char *s = "Hello";
puts(s);
puts(s);
// ouput:
//  Hello
//  Hello
*/
//Reading Strings using scanf and gets Functions
//note1: scanf đọc từng ký tự và lưu dưới dạng mảng và không lưu khoảng trắng
    // char a[10];
    // printf("Enter string: \n");
    // scanf("%s", a); // no need to put &, scanf không đọc space
    // printf("%s", a);
/*
    input: You are most welcome
    ouput: You
*/
//note2: gets() is still unsafe
//fail
    // char a[10];
    // printf("Enter string:\n");
    // gets(a);
    // printf("%s", a);
/*
    input: you are most welcome
    your program may cash
*/
//pass
    // char a[10];
    // printf("Enter string:\n");
    // scanf("%9s", a);
    // printf("%s", a);
/* 
    input: youaremostwelcome
    output: youaremos
*/
    // #include <iostream>
    // #include <stdio.h>
    // //Designing The Input Function using getchar()
    // int input(char str[], int n) {
    //     int ch, i=0;
    //     while((ch=getchar()) != '\n') //ch = 72 != 10
    //         if(i<n)
    //             str[i++] = ch; //str[0] = 72
    //     str[i] = '\0'; // str[5] = '\0';
    //     return i; // return 5;
    // }
    // int main() {
    //     char str[100];
    //     int n = input(str, 5);
    //     printf("%d %s", n, str); // ouput: 5 Hello

    //     return 0;
    // }
/* str  72      101     108     108     111     0
        1000    1001    1002    1003    1004    1005
    Input: Hello, How are you?
        i       ch      n
lần 1:  0       72      5
        2000    3000    4000
lần 2:  1       101     5
lần 3:  2       108     5
lần 4:  3       108     5
lần 5:  4       111     5
*/

//putchar() Function in C
    // int main() {
    //     int ch;
    //     for(ch = 'A'; ch <= 'Z'; ch++) 
    //         putchar(ch);
    //     return 0; // ouput: ABCD....Z
    // }

//String Copy Function - strcpy()
// char * strcpy(char* destination, const char* source)
    // #include <string.h>
    // int main() {
    //     char str1[10] = "Hello";
    //     char str2[10];
    //     char str3[10];

    //     strcpy(str3, strcpy(str2, str1));
    //     printf("%s %s", strcpy(str2, str3));
    //     // printf("%s\n", strcpy(str2, str1));
    //     // printf("%s", str2);
    //     return 0;
    // }
    // //strncpy(destination, source, sizeof(destination));
    // #include <string.h>
    // int main() {
    //     char str1[6] = "Hello";
    //     char str2[4];
    //     strncpy(str2, str1, sizeof(str2));
    //     printf("%s", str2);

    //     return 0; // ouput: Hell
    // }
    // //vd khác
    // #include <string.h>
    // int main() {
    //     char str1[6] = "Hello";
    //     char str2[6];
    //     strncpy(str2, str1, sizeof(str2));
    //     str2[sizeof(str2) - 1] = '\0';
    //     printf("%s", str2);

    //     return 0; // Hello
    // }

//String Length Function - strlen()
//size_t strlen(const char* str);
    // note: size_t la 1 unsigned int
    //       not count NULL character
    // int main() {
    //     char *str = "Hello World"; // ouput: 11
    //     //or
    //     char str[100] = "Hello World"; 
    //     printf("%d", strlen(str));

    //     return 0;
    // }

//String Concatenate Functions - strcat() & strncat()
// char* strcat(char* str1, const char* str2);
    // int main() {
    //     char st1[100], str2[100]; // true
    //     //char st1[15], str2[100]; // false
    //     strcpy(str1, "Welcome to ");
    //     strcpy(str2, "our Academy");
    //     strcat(str1, str2);
    //     printf("%s", str1);

    //     return 0;
    // }
    // //strncat(): tự động nối NULL character vào cuối
    // int main() {
    //     char str1[5], str2[100];
    //     strcpy(str1, "He");
    //     strcpy(str2, "llo!");
    //     strncat(str1, str2, sizeof(str1) - strlen(str1) - 1); //str1, str2, 2
    //     /*
    //     sizeof(str1): size of array - 5
    //     strlen(str1): size of string - 2
    //     1 creating room for NULL character - 1
    //     */
    //     printf("%s", str1);

    //     return 0; // output: Hell
    // }

//String Comparison Function - strcmp()
/*
    int strcmp(const char* s1, const char* s2);
    < 0, if s1<s2
    > 0, if s1>s2
    = 0, if s1 == s2
*/
    // int main() {
    //     char *s1 = "abcd";
    //     char *s2 = "abce"; // output: s1 is less than s2
    //     char *s2 = "abcd"; // output: s1 is greater than or equal to s2
    //     if(strcmp(s1, s2) < 0)
    //         printf("s1 is less than s2");
    //     else
    //         printf("s1 is greater than or equal to s2");

    //     return 0; 
    // }
//Strings (Solved Problem 2)
    // char p[20];
    // char *s = "string";
    // int length = strlen(s);
    // for(int i=0; i<length; i++)
    //     p[i] = s[length-i];
    // printf("%s", p);
//Strings (Solved Problem 3)
    // char c[] = "GATE2011";
    // char *p = c;
    // printf("%s", p + p[3] - p[1]);
/*          
    G       A       T       E       2       0       1       1       \0
    1000    1001    1002    1003    1004    1005    1006    1007    1008
    1000 + E - A
    1000 + 69-65
    1000 + 4 = 1004 = 2011
*/

//Strings (Solved Problem 4)
    // void foo(char *a) {
    //     if (*a && *a != ' ') {
    //         foo(a+1);
    //         putchar(*a);
    //     }
    // }
/*  input:   ABCD EFGH
    output:  ABCD
*/

