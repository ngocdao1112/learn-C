/*
- There are 5 different types we can create threads in C++11 using callable objects.
// NOTE:
- If we create multiple threads at the same time it doesn't guarantee which one will start first.

*/
#include <iostream>
#include <thread>
using namespace std;
//1. Function Pointer
// This is the very basic form of thread creation.
    // void fun(int x) {
    //     while(x-- > 0) {
    //         cout << x << endl;
    //     }
    // }
    // int main() {
    //     thread t1(fun, 11);
    //     t1.join();
    //     return 0;
    // }
//2. Lambda Function
    // int main() {
    //     //we can directly inject lambda at thread creation time
    //     // auto fun = [](int x) {
    //     thread t([](int x) {
    //         while(x-- > 0) {
    //             cout << x << endl;
    //         }
    //     }, 10);

    //     // thread t(fun, 10);
    //     t.join();
    //     return 0;
    // }
//3. Functor(Funtionc-Object), Sử dụng class và toán tử () (toán tử hàm):
    class Base {
    public:
        void operator ()(int x) {
            while (x-- > 0) {
                cout << x << endl;
            }
        }
    };
    int main() {
        thread t((Base()), 10);
        t.join();

        return 0;
    }
//4. Non-static member function
    // class Base {
    // public:
    //     void run(int x) {
    //         while (x-- > 0) {
    //             cout << x << endl;
    //         }
    //     }
    // };
    // int main() {
    //     Base b;
    //     thread t(&Base::run, &b, 10);
    //     t.join();

    //     return 0;
    // }
//5. static member function
    // class Base {
    // public:
    //     static void run(int x) {
    //         while (x-- > 0) {
    //             cout << x << endl;
    //         }
    //     }
    // };
    // int main() {
    //     thread t(&Base::run, 10);
    //     t.join();

    //     return 0;
    // }