//VD1:
/* 
#define N 10
int arr[10];

int main() {
    int a[N], i;
    for (int i=0; i<N ; i++) {
        printf("Enter input for index %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("\nArray elements are as follows:\n");
    for(int i=0; i<N; i++) {
        printf("%d", a[i]);
    }
    
    return 0;
}
*/

//Nếu số ptử < hơn độ dài của mảng thì các vị trí còn lại sẽ = 0
//Để khởi tạo 1 mảng với tất cả các số:
        //int arr[10] = {0}; -> true
        //int arr[5] = {}; -> false
        //int arr[5] = {1, 2, 3, 4, 5, 6}; -> false
//VD2:
/*int arr[10] = {1, 0, 0, 0, 0, 2, 3, 0, 0, 0};
we want:
    - 1 in position 0 
    - 1 in position 5 
    - 1 in position 6
int arr[10] = {[0] = 1, [5] = 2, [6] = 3};
*/
//VD3:
/*
int a[] = {1, 7, 5, [5] = 90, 6, [8] = 4};
=
int a[] = {1, 7, 5, 0 , 0, 90, 6, 0, 4};

//VD4: reverse
int main() {
    int a[] = {34, 56, 54, 32, 67, 89, 90, 32, 21};
    //Original order
    for (int i=0; i<9; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    //reverse order
    for (int i=8; i>=0; i--) {
        printf("%d ", a[i]);
    }
    return 0;
}

//VD5:
int main() {
    int seen[10] = {0};
    int N;
    printf("Enter number: ");
    scanf("%d", &N);
    
    int rem;
    while (N>0) {
        rem = N%10;
        if(seen[rem] == 1)
            break;
        seen[rem] = 1;
        N = N/10;
    }
    if(N>10)
        printf("Yes");
    else
        printf("No");
    return 0;
}
*/
//1. Count Array Elements using sizeof() Operator
/*int main() {
    int a[] = {1,2,3,21,4,3,12,65,3,32,21,654,423,121,65,
            434,23,21,24,35,65,76,8,9,54,54,43,54,65,76,54,
            54,4,32,32,32,54,6,6,773,652,2,32,3};
            
    printf("%d", sizeof(a)/sizeof(a[0]));
}
*/
/*
//2. Multidimensional Arrays
size of a[10][20] = 10*20 = 200
                  = 200*4 = 800 bytes
//(we can store upto 200 elements in this array)
size of a[4][10][20] = 4*10*20 = 800
                     = 800*4 = 3200 bytes
//(we can store upto 800 elements in this array)

//3. Three-Dimensional (3D) Arrays
int a[2][2][3] = {
    {{1, 2, 3}, {4, 5, 6}},
    {{7, 8, 9}, {10, 11, 12}}
};
/*
    1 2 3       7  8  9
    4 5 6       10 11 12
        //2x3           //2x3
*/
/*
//VD1:
int main() {
    int a[5][5] = {
        {8, 3, 9, 0, 10},
        {3, 5, 17, 1, 1},
        {2, 8, 6, 23, 1},
        {15, 7, 3, 2, 9},
        {6, 14, 2, 6, 0},
    }
}
int sum = 0;
//row
printf("Row total: ");
for(int i=0; i<5; i++) {
    for(int j=0;j<5;j++) {
        sum += a[i][j];
    }
    printf(" %d", sum);
    sum=0;
}
//column
printf("\nColumn total: ");
for(int j=0; j<5; j++) {
    for(int i=0;i<5; i++) {
        sum += a[i][j];
    }
    printf(" %d", sum);
    sum=0;
}

//VD2:
#define MAX 50
int main() {
    int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX];
    int arows, acolumns, brows, bcolumns;
    int sum = 0;
    //part 1
    printf("Enter rows & columns of the matrix a: ");
    scanf("%d %d", &arows, &acolumns);
    
    printf("Enter elements of matrix a: \n");
    for(int i=0; i<arows; i++) {
        for(int j=0; j<acolumns; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter rows & columns of the matrix b: ");
    scanf("%d %d", &brows, &bcolumns);
    
    if(brows != acolumns) {
        printf("Sorry! we cannot multiply the matrices a & b");
    }
    else {
        printf("Enter elements of matrix b: \n");
        for(int i=0; i<brows; i++) {
            for(int j=0; j<bcolumns; j++) {
                scanf("%d", &b[i][j]);
            }
        }
    }
    
    printf("\n");
    
    for(int i=0; i<arows; i++) {
        for(int j=0; j<bcolumns; j++) {
            for(int k=0; k<brows; k++) {
                sum += a[i][j] * b[i][j];
            }
            product[i][j] = sum;
            sum=0;
        }
    }
    //printing the array elements
    printf("Resutant matrix\n");
    for(int i=0; i<arows; i++) {
        for(int j=0; j<bcolumns; j++) {
            printf("%d", product[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

//VD3: Variable Length Arrays in C
int main() {
    int n;
    printf("Enter number of elements you want to reverse: \n");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter all the %d elements: \n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Elements in reverse order are: \n");
    for(int i=n-1; i>=0; i--) {
        printf("%d ", a[i]);
    }
    
    return 0;
}

//pointer
int x=5;
int *ptr;
ptr = &x;
==> int x=5, *ptr = &x;
*/
/*
//pointer
int x = 5;
int *ptr;
ptr = &x;
=
int x = 5;
*ptr = &x;

//change value
int x = 10;
int *ptr = &x;
*ptr = 4;
printf("%d", *ptr); //output: 4

//Pointer Assignment
int i = 10;
int p, q;
p = &i;
q = p;

printf("%d %d", p, q); // output: 10 10
//note: q = p is not same as q = p;
int i = 10;
int p, q;
p = &i;
q = p;
==========
int i = 10, j = 20;
int p, q;
p = &i;
q = &j;
//homework:
int i = 1;
int *p = &i;
q = p;
*q = 5;
printf("%d", *p);

//Finding the Largest & Smallest Elements in an Array
void minMax(int arr[], int len, int min, int max) {
    min = max = arr[0];
    for(int i=0; i<len; i++) {
        if(arr[i] > *max)
            *max = arr[i];
        if(arr[i] < *min)
            *min = arr[i];
    }
}
int main() {
    int a[] = {23, 4, 21, 98, 987, 45, 32, 10, 123, 986, 50, 3, 4, 5};
    int min, max;
    int len = sizeof(a) / sizeof(a[0]);
    minMax(a, len, &min, &max);
    printf("Minimum value int the array is: %d and Maximum value is: %d ", min, max);
    
    return 0;
}

//c_passing_pointers_to_functions
//c_return_pointer_from_functions
    int *findMid(int a[], int n);
    int main() {
        int a[] = {1, 2, 3, 4, 5};
        int n = sizeof(a)/sizeof(a[0]);
        int *mid = findMid(a, n);
        printf("%d", *mid);
        
        return 0; // output: 3
    }
    int *findMid(int a[], int n) {
        return &a[n/2];
    }
//automatic variable
    int *fun() {
        int i = 10;
        return &i;
    }
    int main() {
        int *p = fun();
        printf("%d", *p); // warning: function returns address of local variable
    }

//VD1: 
    int *p = &i;
    p = &i;
//VD3: how to print the address of a variable?
    int main() {
        int i = 10;
        int *p = &i;
        printf("Addess of variable i is %p", p);
        //variable i is 0x6fff....
        return 0;
    }
//VD4: if i is a variable and p points to i, aliases of i?
Ex:
    int i = 10; // giá trị i = 10; address i = 1000; 
    int *p = &i; // address p = 2000; ô chứa 1000 vì trỏ đến i 
    a) p = (1000) = 10 -> true
    b) &p = (&p) = *(2000) = 1000
    c) &p = 2000
    d) i = (10) doesn't make sense
    e) &i = (&i) = *(1000) = 10 -> true
//Pointer Arithmetic (Increment & Decrement)
int main() {
    int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
    int *p = &a[0]; // 1000
    printf("%d ", *(p++)); // 1000
    printf("%d ", *p);
    return 0; // output: 5 16
}
int main() {
    int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
    int *p = &a[0]; // p = 1000
    printf("%d ", *(++p)); // 1004
    return 0; // output: 16
}

//Pointer Arithmetic (Comparing the Pointers)
int main() {
    int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
    int p = &a[1], q = &a[5];
    
    printf("%d ", *(p+3));
    printf("%d ", *(p-3));
    printf("%d ", q - p);
    printf("%d ", q < p); // memory addresses
    printf("%d ", q > p); // values pointed
    //output: 45 7 4 1 1
}

//Sum of Array Elements using Pointers
//old program
int main() {
    int a[] = {11, 12, 36, 5, 2};
    int sum = 0, *p;
    
    for(p = &a[0]; p <= &a[4]; p++) {
        sum += *p;
    }
    printf("Sum is %d", sum); //76
}
//Using Array Name as a Pointer
//new program; *(a+i) = a[i]
int main() {
    int a[] = {11, 12, 36, 5, 2};
    int sum = 0, *p;
    
    for(p = a; p <= a + 4; p++) {
        sum += *p;
    }
    printf("Sum is %d", sum); //76
}
//other VD
int main() {
    int a[] = {11, 22, 36, 5, 2};
    int *p = a;
    printf("%d", *(++p));
    
    return 0; // output: 22
}

//Reverse a Series of Numbers using Pointers
#define N 5
int main() {
    int a[N], *p;
    printf("Enter 5 elements in array: ", N);
    for(p=a; p <= a+N-1; p++) { //p=1000; p <= 1000+(5-1)x4 = 1016
        scanf("%d", p);
    }
    printf("elements in Reverse order:\n");
    for(p = a+N+1; p >= a; p--) { // p = 1016; p>=1000
        printf("%d ", *p);
    }
    
    return 0;
}

//Passing Array as an Argument to a Function
    int add(int b[], int len) {
        int sum = 0, i;
        for(i=0; i<len; i++) {
            sum += b[i];
        }
        return sum;
    }

    int main() {
        int a[] = {1, 2, 3, 4};
        int len = sizeof(a)/sizeof(a[0]);
        printf("%d", add(a, len));
        
        return 0;
    }


//Pointers (Program 5):
//What is the output of the follow C:
void f(int *p, int *q){ //*p=&i=1000 ; *q=&j=2000
    p = q; //p=q=2000=1
    *p = 2; //*p=2=*(1000)=2000=2
    //=> q=2; p=0
}

int i=0, j=1;
int main() {
    f(&i, &j); 
    printf("%d %d\n", i, j); // output: 0 2

    return 0;
}


//Pointers (Program 6)
int f(int *a, int n) {
    if(n<=0)
        return 0;
    else if (*a % 2 == 0){
        return *a + f(a+1, n-1);
    }
    else
        return *a - f(a+1, n-1);
}

int main() {
    int a[] = {12, 7, 13, 4, 11, 6};
    printf("%d", f(a, 6));
    getchar();

    return 0;
}
// f(&a[0], 6) -> 12 + f(&a[1], 5) -> 7 - f(&a[2], 4) -> 13 - f(&a[3], 3) -> 4 + f(&a[4], 2) -> 11 - f(&a[5], 1) -> 6 - f(&a[6], 0)
// 6 + 0 -> 11 - 6 = 5


//Function Pointers in C
int main() {
    int *ptr[10]; // -> wrong
    int *ptr[10]; // -> true
    return 0;
    // [] before *
}
//VD1
int add(int a, int b) { //0fxx
    return a+b;
}
int main() {
    int result;
    int (*ptr)(int, int) = &add;
    result = *ptr(10, 20);
    
    printf("%d", result);
}
//VD2
float sum(float a, float b) {return a+b;}
float sub(float a, float b) {return a-b;}
float mult(float a, float b) {return a*b;}
float divi(float a, float b) {return a/b;}
//traditional
int main() {
    int choice;
    float a, b, result;
    printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
    scanf("%d", &choice);
    printf("Enter two numbers:\n");
    scanf("%f %f", &a, &b);
    switch(choice) {
        case 0: 
            result = sum(a, b); break;
        case 1: 
            result = sub(a, b); break;
        case 2: 
            result = mult(a, b); break;
        case 3: 
            result = divi(a, b); break;
    }
    printf("%f", result);
    result 0;
}
//new program
#define ops 4
int main() { //*p[4](float, float)
    float (*ptr2func[ops])(float, float) = {sum, sub, mult, divi};
    int choice;
    float a, b;
    printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
    scanf("%d", &choice);
    printf("Enter two numbers:\n");
    scanf("%f %f", &a, &b);
    printf("%f", ptr2func[choice](a, b));
    
    return 0;
}
*/