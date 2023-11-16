/*
1. Preprocessors
2. Predefined Macros
3. Preprocessor Operators
    - Macro Continuation (\)
    - Token Pasting (##)
    - Parameterized Macros
*/

// Predefined Macros
#include <stdio.h>
int main() {
    printf("This is line number %d\n", __LINE__);
    printf("This file is %s\n", __FILE__);
    return 0;
}

// Macro Continuation (\) nối các dòng mã nguồn
#define MESSAGE "Hello, "\
                "World!"

// Token Pasting (##) nối hai token lại với nhau
#define CONCAT(a, b) a##b
int main() {
    int xy = CONCAT(10, 20); // sẽ trở thành int xy = 1020;
}

// Parameterized Macros
#define SQUARE(x) ((x) * (x))
int main() {
    int result = SQUARE(5); // sẽ trở thành int result = ((5) * (5));
}
