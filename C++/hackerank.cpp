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

*/