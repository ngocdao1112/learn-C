#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//HEAP & STACK, MEMORY LEAK
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

    //WHAT IS MEMORY LEAK
    /*
        - nói về tình huống xảy ra do việc sd bộ nhớ k đúng cách or bộ nhớ trên heap và tình huống này là rò rỉ bộ nhớ
        - simple betting game
        - "Jack, Queen, King" - computer shuffles these cards
        - if he wins, he takes 3*bet
        - if he looses. he tooks the bet amount
        - player has $100 initially
    */
    int cash = 100;
    void Play(int bet) {
        // char C[3] = {'J', 'Q', 'K'};
        char *C = (char*)malloc(3*sizeof(char)); // c++: char *C = new char[3];
        C[0] = 'J'; C[1] = 'Q'; C[2] = 'K';
        
        printf("Shuffling ...\n");
        srand(time(NULL)); //seeding random number generator
        for(int i=0; i<5; i++) {
            int x = rand() % 3;
            int y = rand() % 3;
            int temp = C[x];
            C[x] = C[y];
            C[y] = temp; // swaps characters at position x and y
        }
        int playersGuess;
        printf("What's the position of queen - 1, 2 or 3? ");
        scanf("%d", &playersGuess);
        if(C[playersGuess - 1] == 'Q') {
            cash += 3*bet;
            printf("You win! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
        } 
        else {
            cash -= bet;
            printf("You Loose! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
        }
    }
    int main() {
        int bet;
        while (cash > 0) {
            printf("What's your bet? $");
            scanf("%d", &bet);
            if(bet == 0 || bet > cash)
                break;
            Play(bet);
            printf("\n**********************************************\n");
        }
    }