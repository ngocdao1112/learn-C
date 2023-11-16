#include <iostream>
using namespace std;

/*  1. Recursuve
    - Đệ quy là cách dùng hàm để gọi lại chính nó
    - Để giải đệ quy cần:
        + Điểm dừng của bài toán
        + Quy luật của bài toán
*/
/*  2. Fibonaci
    - Dãy fibonaci: F1=1; F2=1; Fn=F(n-1) + F(n-2)
        + Quy luật: Fn = F(n-1) + F(n-2)
        + Điểm dừng: n <= 2 thì Fn(n) = 1
*/
int giaiThua(int n);
int fibobaci(int n);

int main() {
    //goi ham tinh giai thua
    int kq = giaiThua(4);
    cout << "kq= " << kq << endl;

    int kq2 = fibobaci(14);
    cout << "kq2= " << kq2 << endl;

}

int giaiThua(int n) {
    if (n <= 1)
        return 1;
    return n*giaiThua(n-1);
}
/*  n = 4
    n*giaiThua(n-1) = 4*giaiThua(4-1) = 4*giaiThua(3)
    gán n = 3 tới giaiThua(int n) => giaiThua(int 3)

    n*giaiThua(n-1) = 3*giaiThua(3-1) = 4*giaiThua(2)
    gán n = 2 tới giaiThua(int n) => giaiThua(int 2)

    n*giaiThua(n-1) = 3*giaiThua(2-1) = 4*giaiThua(1)
    gán n = 1 tới giaiThua(int n) => giaiThua(int 1)

    n <= 1; 1 <= 1 => true and return 1;
*/

int fibobaci(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibobaci(n-1) + fibobaci(n-2);
}