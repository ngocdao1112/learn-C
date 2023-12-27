/*
- QUESTIONS
1. What do you understand by thread and give one example in C++?
- ANSWER
1. In evey application there is a default thread which is main(), in side this we create other threads.
 - A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
For example:
(a) The browser has multiple tabs that can be different threads.
(b ) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
(c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

- WAYS TO CREATE THREADS IN C++11:
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member functions
- REQUIREMENT
Find the addition of all odd number from 1 to 1900000008 and all even number from 1 to 1900000000
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;
ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if((i & 1) == 1) {
            OddSum += i;
        }
    }
}

void findOdd(ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if((i & 1 ) == 0) {
            EvenSum += i;
        }
    }
}
int main() {
    ull start = 0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    //in lần 1 cho này: 7's , lẽ ra là < 5's như ở dưới nhưng phụ thuộc vào nhiều yếu tố
    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);
    t1.join(); //đã làm 1 video khác cho chỗ này
    t2.join();

    //in lần 1 cho này: 5's
    // findOdd(start, end);
    // findEven(start, end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum: " << OddSum << endl;
    cout << "EvenSum: " << EvenSum << endl;

    cout << "Sec: " << duration.count()/1000000 << endl;

    return 0;
}