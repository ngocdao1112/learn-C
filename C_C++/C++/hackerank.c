/*
1. "Hello World!" in C	
    // char s1[100], s2[100], s3[100], s4[100];
    // scanf("%s%s%s%s", s1, s2, s3, s4);
	char s[100];
    fgets(s, sizeof(s), stdin);
    
    printf("Hello, World!\n%s", s);
    // printf("%s %s %s %s", s1, s2, s3, s4);
    // printf("%s", s);
2. Playing With Characters
    // char ch;
    // char str[100];
    // char sen[100];
    char ch, str[MAX_LEN], sen[MAX_LEN];
    scanf("%c %s %[^\n]%*c", &ch, str, sen);
	//%c : space sau c là đọc 1 char từ bàn phím và bỏ qua các ký tự trắng
	//%[^\n]%*c đọc 1 văn bản và bỏ qua \n
    
    printf("%c\n%s\n%s", ch, str, sen);
    // printf("%c\n", ch);
    // printf("%s\n", str);
    // printf("%s", sen);
3. Sum and Difference of Two Numbers
    int a, b;
    float c, d;
    
	scanf("%d%d%f%f", &a, &b, &c, &d);
    
    int s1 = a + b;
    int s2 = a - b;
    float s3 = c + d;
    float s4 = c - d;
    
    printf("%d %d\n%.1f %.1f", s1, s2, s3, s4);
	
4. For Loop in C

    for (int i=a; i<=b; i++) {
        if(i<=9) {
            switch (i) {
            case 1:
                printf("one\n");
                break;
            case 2:
                printf("two\n");
                break;
            case 3:
                printf("three\n");
                break;
            case 4:
                printf("four\n");
                break;
            case 5:
                printf("five\n");
                break;
            case 6:
                printf("six\n");
                break;
            case 7:
                printf("seven\n");
                break;
            case 8:
                printf("eight\n");
                break;
            case 9:
                printf("nine\n");
                break;
            }
        }
        else if (i%2 != 0){
            printf("odd\n");
        }
        else
            printf("even\n");
    }
5. Sum of Digits of a Five Digit Number
    while (n != 0) {
        // sum = sum + (n%10);
        sum += n % 10; // Add the last digit
        n /= 10;       // Remove the last digit, n = n/10;
    }
    
    printf("%d\n", sum);
    return 0;
6. Bitwise Operators
//  1: 0000.0001
//  2: 0000.0010
//and: 0000.0000   1&2
//  3: 0000.0011  
//and: 0000.0001   1&3
//and: 0000.0010   2&3
/*n = 3;
k = 3;

1 -> 3: 1, 2, 3
    and or xor
1 2    0    3    3
1 3    1    3    2
2 3    2    3    1

2 lớn nhất -> lớn nhất nhỏ hơn k
0 nhỏ hơn k -> lớn nhất nhỏ hơn k
2 lớn nhất nhỏ hơn k
    int maxAND = 0; 
    int maxOR = 0; 
    int maxXOR = 0;
    for(int a = 1; a <= n; a++) {
        for (int b=a+1; b <= n; b++) {
            // printf("%d %d %d\n", a&b, a|b, a^b);
            if ((a&b) < k && (a&b) > maxAND) {
                maxAND = a&b;
            }
            if ((a|b) < k && (a|b) > maxOR) {
                maxOR = a|b;
            }
            if ((a^b) < k && (a^b) > maxXOR) {
                maxXOR = a^b;
            }
        }
    }
    // printf("%d %d %d\n", maxAND, maxOR, maxXOR);
    printf("%d\n%d\n%d", maxAND, maxOR, maxXOR);

7. Functions in C
int max_of_four(int a, int b, int c, int d) {
    // return max(max(a,b), max(c,d));
    int maxab = max(a,b);
    int maxcd = max(c,d);
    int maxabcd = max(maxab, maxcd);
    return maxabcd;
}

int max(int x, int y) {
    if (x >= y) {
        return x;
    }
    else {
        return y;
    }
}
=========================
8. 1D Arrays in C
    int n;
    scanf("%d", &n);
    int arr = (int*)malloc(n  sizeof(int));
    // printf("%d\n", n);
    
    int sum = 0;
    // int m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        // arr[i] = m;
        sum += arr[i];
    }
    printf("%d", sum);
    
    return 0;
9. Array Reversal
    int left = 0;
    int right = num-1;
    while (left <= right) {
        int temp = arr[left]; //temp = 16
        arr[left] = arr[right]; // arr[0] = arr[5] => arr[0] = 12
        arr[right] = temp; // arr[5] = temp => arr[5] = 16
        left++; 
        right--;
    }
====================

    char *s;
    s = malloc(1024 * sizeof(char)); 
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] == ' ') {
            printf("\n");
        }
        else {
            printf("%c", s[i]);
        }
    }
	
======================================
s[j] có kiểu char <-> (int i -> char ' ')
a11472o5t6 = 10 index
i = 48; dem = 0
j = 0; 
s[j] = s[0] = 'a' == char(48) => 'a' == '0' -> sai
j = 1; 
s[j] = s[1] = '1' == char(48) => '1' == '0' -> sai
j = 2; 
.....
.....
i = 49; dem = 0
j = 0; 
s[j] = s[0] = 'a' == char(49) => 'a' == '1' -> sai
j = 1;
s[j] = s[1] = '1' == char(49) => '1' == '1' -> dung
dem = 1;

    char *s;
    s = (char*)malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT

    for (int i = 48; i < 58; i++) { // 0 -> 9: 48 -> 57
        int dem = 0;
        for (int j = 0; j < strlen(s); j++) {
            if(s[j] == (char)i) {
                dem++;
            }
        }
        printf("%d ", dem);
    }
===============================================
Printing Pattern Using Loops:
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//cách 1:
int main() {
    int n;
    scanf("%d", &n);

    int length = 2*n - 1;
    int a[length][length];
    int temp = n;

    // Complete the code to print the pattern.
    while (temp) {
        for (int i = length; i >= (2*n-length); i--)
        {
            for (int j = length; j >= (2*n-length); j--)
            {
                a[i - 1][j - 1] = temp;
            }
        }
        temp--; //2
        length--; //4
    }

    for (int i = 0; i < (2*n-1); i++)
    {
        for (int j = 0; j < (2*n-1); j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
===============================================
int marks_summation(int* marks, int number_of_students, char gender) {
    //Write your code here.
    int SUM = 0;
    for(int i = (gender == 'b' ? 0 : 1); i < number_of_students; i += 2) {
        SUM += marks[i]; //sum += *(marks + i);
    }
    return SUM;
}
===============================================
Boxes through a Tunnel:
struct box
{// Define three fields of type int: length, width and height
	int length, width, height;
};
typedef struct box box;

int get_volume(box b) {
	//Return the volume of the box
    return b.width*b.height*b.length;

}

int is_lower_than_max_height(box b) {
	//Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
	return b.height < MAX_HEIGHT;
}
===============================================
Small Triangles, Large Triangles:
                    3
                    7 24 25
                    5 12 13
                    3 4 5

                    arr[n] = arr[3] ; 0  1  2
                    ======================
                    - for 1:
                        i=0; i<n = 0<3 		>> true
                            p=tr[0].a + tr[0].b + tr[0].c / 2 = 28
                        arr[0] = 84
                        
                    - for 2:
                        i=1; i<n = 1<3 		>> true
                            p=tr[1].a + tr[1].b + tr[1].c / 2 = 15
                        arr[1] = 30
                        
                    - for 3:
                        i=2; i<n = 2<3 		>> true
                            p=tr[2].a + tr[2].b + tr[2].c / 2 = 6
                        arr[2] = 6
                    =======================
                    - for 2:
                        i=0; i<n = 0<3 		>> true
                            j=1; j<n = 1<3 		>> true
                                - arr[i] > arr[j] = 84 > 30
                                temp = arr[j] = arr[1] = 30
                                arr[j]= arr[i] = arr[0] = 84 	=> arr[j] = 84
                                arr[i] = temp = 30 				=> arr[i] = 30
                                
                                temp1 = tr[j] = tr[1] = (5 12 13)
                                tr[j] = tr[i] = tr[0] = (7 24 25) 	=> tr[j] = (7 24 25)
                                tr[i] = temp1 = (5 12 13) 			=> tr[i] = (5 12 13)
                                
                    => 84 (7 24 25) tr[j]
                    30 (5 12 13) tr[i]
                    =======
                        i=1; i<n = 1<3 		>> true
                            j=2; j<n = 2<3 		>> true
                                - arr[i] > arr[j] =  arr[1] > arr[2] = 30 > 6
                                temp = arr[j] = arr[2] = 6 
                                arr[j]= arr[i] = arr[1] = 30 	=> arr[j]= 30
                                arr[i] = temp = 6 				=> arr[i] = 6
                                
                                temp1 = tr[j] = tr[2] = (3 4 5)
                                tr[j] = tr[i] = tr[1] = (5 12 13)	=> tr[j] = (5 12 13)
                                tr[i] = temp1 = (3 4 5)				=> tr[i] = (3 4 5)
                                
                    => 30 (5 12 13) tr[j]
                    6 (3 4 5) tr[i]
                    =======
                        i=2; i<n = 2<3 		>> false
                        
                    => 84 (7 24 25) tr[j]
                    30 (5 12 13) tr[i]
                    => 30 (5 12 13) tr[j]
                    6 (3 4 5) tr[i]

                        6 (3 4 5) tr[i]
                        30 (5 12 13) tr[j]
                        84 (7 24 25) tr[j]
    typedef struct triangle triangle;
    void sort_by_area(triangle* tr, int n) {
        //Sort an array a of the length n
        double arr[n], temp;
        double p;
        triangle temp1;

        for (int i=0; i<n; i++) {
            p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
            arr[i] = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p- tr[i].c));
        }

        for (int i =0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[j];
                    arr[j]= arr[i];
                    arr[i] = temp;
                    
                    temp1 = tr[j];
                    tr[j] = tr[i];
                    tr[i] = temp1;
                }
            }
        }
    }
===============================================

*/
