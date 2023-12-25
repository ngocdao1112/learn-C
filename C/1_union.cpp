#include <iostream>
using namespace std;

/* VD1
union abc {
    int a;
    char b;
}var;

int main () {
    var.a = 65;
    printf("a = %d\n", var.a);
    printf("b = %c", var.b);
    //ouput: a= 65
            //b = A
}
*/

/* VD2
union abc {
    int a; // 4 bytes
    char b; // 1 bytes
    double c; // 8 bytes
    float d; // 4 bytes
};

int main () {
    printf("%ld", sizeof(union abc));
    return 0;
    //output : 8
}
*/

/* VD3
union abc {
    int a;
    char b;
};
int main() {
    union abc var;
    var.a = 90;
    union abc *p = &var;
    printf("%d %c", p->a, p->b);

    return 0;
    //output: 90 Z
}
*/
/*
//VD4
struct store {
    double price; // 8b
    char *title; // 8b
    char *author; // 8b
    int num_pages; // 4b
    int color //wastage - 4b
    int size; //wastage - 4b
    char *design; //wastage - 8b
}

int main()
{
    struct store book;
    book.title = "The Alchemist";
    book.author = "Paulo Coelho";
    book.num_pages = 197;
    book.price = 23;
    
    struc store book;
    printf("%ld bytes", sizeof(book));
    //ouput: 44 bytes

    return 0;
}
*/

struct store {
    double price; // 8b
    union {
        struct {
            char *title; // 8b
            char *author; // 8b
            int num_pages; // 4b
        } book;
        struct {
            int color; // 4b
            int size; // 4b
            char *design; // 8b
        } shirt;
    } item;
};

int main()
{
    struct store s;
    s.item.book.title = "The Alchemist";
    s.item.book.author = "Paulo Coelho";
    s.item.book.num_pages = 197;
    printf("%s\n", s.item.book.title);
    printf("%ld", sizeof(s));
    //ouput : 28
    return 0;
}


/* VD5
// best choice
typedef union { // 8 bytes
    int a; 
    char b;
    double c;
} data;

int main() { // size = 80 bytes
    data arr[10];
    arr[0].a = 10;
    arr[1].b = 'a';
    arr[2].c = 10.178;
    
    return 0;
}

typedef struct { // 13 bytes
    int a; 
    char b;
    double c;
} data;

int main() { // size = 130 bytes
    data arr[10];
    arr[0].a = 10;
    arr[1].b = 'a';
    arr[2].c = 10.178;
    
    return 0;
}
*/