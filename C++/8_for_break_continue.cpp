#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    //continue: tính tổng từ 1 đến 5, bỏ qua 3
/*    int tong = 0;
    for (int i=1; i<=5; i++)
    {
        if (i==3) {
            continue;
        }
        else {
            cout << "i= " << i << endl;
            tong +=i;
        }
    }
    cout << "tong = " << tong << endl; */

    //break
/*    int n=0;
    while (n < 100) {
        n++;
        cout << "n trong vòng lặp = " << n << endl;
        if (n == 4)
            break;
    }
    cout << "giá trị n cuối cùng = " << n << endl; */

/*
    Viết ctrinh nhập số nguyên n, in ra kq n!
    - dùng for
    - dùng while
*/    
    // int n, gt = 1;
    // cout << "n = ";
    // cin >> n;

    //case 1: dùng for
/*    for (int i=0; i <= n; i++) {
        cout << i << endl;
        gt *= i; //gt = gt*i
    }
    cout << n << "! = " << gt << endl; */

    //case 2: while
/*    int i = 1;
    while (i <= n) {
        gt *= i;
        i++;
    }
    cout << n << "! = " << gt << endl; */

/*
    Viết ctrinh nhập a,
    - Nếu a chẵn thì tính tổng các số chẵn từ 0 đến a
    - Nếu a lẻ thì in ra dòng chữ "tôi không tính tổng số lẻ, bye bye" và thoát chương trình
*/  
/*    int a;
    cout << "Nhap a: ";
    cin >> a;
    if(a % 2 == 0) {
        int s = 0;
        for(int i = 0; i <= a; i += 2) {
            cout << "i = " << i << endl;
            s += i;
        }
        cout << "s = " << s << endl;
    }
    else
        cout << "tôi không tính tổng số lẻ, bye bye" << endl; */
/*
    Viết ctrinh tính tổng các số lẻ từ 1 đến n, n tự nhập
    vd n = 7, bỏ qua 3 => in ra kq
    Thử break khi vòng lặp chạy đến gtri n=3
*/

/*    int n , s = 0;
    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i+=2) {
        if (n%2 != 0) {
                if (i == 3) {
                break;
            }
            cout << "i = " << i << endl;
            s += i;
        }
    }
    cout << "s = " << s << endl;

    return 0; */

/*
    Viết ctrinh: tìm những số chia hết cho 3 từ 10 đến 50
*/
/*    int n;
    cout << "Nhap n: ";
    cin >> n;

    for (int i = 10; i <= n; i++) {
        if (i %3 == 0) {
            cout << "So chia het cho 3 la: " << i << endl;
        }
    }*/

/*
    S = 1! + 2! + 3! + ... + 10!
*/
/*    int gt = 1;
    int s = 0;
    int n;
    cout << "Nhap n: ";
    cin >> n;

    for (int i=1; i <= n ; i++) {
        gt = gt * i;
        // cout << gt << endl;
        s = s + gt;
    }
    cout << "Tong can tinh la: " << s << endl;  */

/*
    Tìm tất cả những số hoàn hảo trong phạm vi từ 1-1000
*/
/*    int n = 6;
    int sum = 0;
    //check các ước thực n
    for (int i=1; i < n; i++) {
        // cout << i<< endl;
        if (n%i == 0)
            sum = sum + i;
    }
    if (sum == n) 
        cout << n << " la so hoan hao" << endl;
    else
        cout << n << " khong phai la so hoan hao" << endl;

    cout << "Các số hoàn hảo trong phạm vi từ 1 - 1000 là: " << endl;
    for (int n = 1; n <= 1000; n++) {
        int tong = 0;
        for (int i= 1; i < n; i++) {
        // cout << i<< endl;
        if (n%i == 0)
            tong = tong + i;
    }
    if (tong == n) 
        cout << n << "\t";
        // else
        //     cout << n << " khong phai la so hoan hao" << endl;
        
    }*/

/*
    Viet ctrinh nhập a > 0, cho biết đó có phải là số nguyên tố
    (số ngto là số > 1, và chỉ chia hết cho 1 và chính nó)
    kết thúc ctrinh hỏi user:
    Do you want to continue using the software?
    If you select 0, exit the program 
*/
/*    while (true)
    {
        int a;
        cout << "Nhap a, a > 0: ";
        cin >> a;
        if(a <= 0) {
            cout << "Enter again! a>0.";
            continue;
        }
        //check so ngto
        bool isPrime = true;
        for (int i=2; i < a; i++) {
            if(a%i == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            cout << a << " là so ngto \n";
        else
            cout << a << " ko phai là so ngto";
        string traloi;
        cout << "Do you want to continue? \n";
        cout << "If select n|N, exit the program \n";
        cin >> traloi;
        if (traloi == "n" || traloi == "N")
            break;
        cout << "Thanks for you using your the software!";
    }*/
}