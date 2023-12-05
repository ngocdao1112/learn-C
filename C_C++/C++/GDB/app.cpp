// Question: what is gdb and how to use to debug your C&C++ code?
// Answer: I will explain few commands: next, step, continue, breakpoints, backtrace, frame, info...
//g++ -g app.cpp //-g là debuging
/*
D:\VSCode\C++_v2> cd D:\VSCode\C++_v2\C_C++\C++\GDB
D:\VSCode\C++_v2\C_C++\C++\GDB> g++ -g app.cpp -o myprogram
D:\VSCode\C++_v2\C_C++\C++\GDB> gdb myprogram.exe
- (gdb) 'b main'        // breakpoint
- (gdb) 'run'       
- (gdb) 'f'             //check xem dang dong nao
#0  main () at app.cpp:35
35          int mainVariable = 10;
- (gdb) 'next'          // xem dong tiep theo
36          cout << mainVariable << endl;
- (gdb) 'print mainVariable' or 'p mainVariable'
$1 = 10
- (gdb) n 
10
37          fun1();
- (gdb) s                //access vao fun1()
fun1 () at app.cpp:46
46          int fun3Variable = 15;
- (gdb) q
A debugging session is active.

        Inferior 1 [process 25640] will be killed.

- Quit anyway? (y or n) y
PS D:\VSCode\C++_v2\C_C++\C++\GDB>

Để thoát khỏi gdb và quay về thư mục D:\VSCode\C++_v2\C_C++\C++\GDB> "quit or q"
*/

#include <iostream>
using namespace std;

void fun3() {
    int fun3Variable = 25;
    cout << fun3Variable << endl;
}

void fun2() {
    int fun2Variable = 20;
    cout << fun2Variable << endl;
    fun3();
}

void fun1() {
    int fun1Variable = 15;
    cout << fun1Variable << endl;
    fun2();
}

int main() {
    int mainVariable = 10;
    cout << mainVariable << endl;
    fun1();

    cin.get();
    return 0;
}

/*
- (gdb) backtrace
#0  fun2 () at app.cpp:40
#1  0x00007ff634041507 in fun1 () at app.cpp:48
#2  0x00007ff63404154d in main () at app.cpp:54

- (gdb) r
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: D:\VSCode\C++_v2\C_C++\C++\GDB\myprogram.exe 
[New Thread 14496.0x25ac]
[New Thread 14496.0x24d0]
[New Thread 14496.0x42c0]

Thread 1 hit Breakpoint 1, main () at app.cpp:52
52          int mainVariable = 10;

- (gdb) infor b
Undefined command: "infor".  Try "help".

- (gdb) info b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x00007ff63404151b in main() at app.cpp:52
        breakpoint already hit 1 time
- (gdb) delete 1
- (gdb) info b
No breakpoints or watchpoints.
- (gdb) b fun3
Breakpoint 3 at 0x7ff634041458: file app.cpp, line 35.
- (gdb) f
#0  main () at app.cpp:52
52          int mainVariable = 10;
- (gdb) continue
Continuing.
10
15
20

Thread 1 hit Breakpoint 3, fun3 () at app.cpp:35
35          int fun3Variable = 25;
- (gdb) n
36          cout << fun3Variable << endl;
- (gdb) n
25
37      }
- (gdb) info breakpoint
Num     Type           Disp Enb Address            What
2       breakpoint     keep y   0x00007ff63404151b in main() at app.cpp:52
        breakpoint already hit 1 time
3       breakpoint     keep y   0x00007ff634041458 in fun3() at app.cpp:35
        breakpoint already hit 1 time
- (gdb) bt        // 1 func đc gọi 1 stack sẽ đc tạo
#0  fun3 () at app.cpp:37
#1  0x00007ff6340414c6 in fun2 () at app.cpp:42
#2  0x00007ff634041507 in fun1 () at app.cpp:48
#3  0x00007ff63404154d in main () at app.cpp:54
*/

/*
Đang ở fun1() nên k thể print fun2Variable:
- (gdb) n
56          cout << mainVariable << endl;
- (gdb) n
10
57          fun1();
- (gdb) s
fun1 () at app.cpp:49
49          int fun1Variable = 15;
- (gdb) n
50          cout << fun1Variable << endl;
- (gdb) p fun2Variable
No symbol "fun2Variable" in current context.
- (gdb) p fun1Variable
$6 = 15
*/


