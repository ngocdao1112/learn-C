/*
TOPIC: Use of join(), detach() and joinable() In Thread In C++ (C++11)
JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object. 
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining, (using joinable() function)
DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread. 
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detach() will result into program termination. 
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.
NOTES:
// Either join() or detach() should be called on thread object, otherwise during thread object's destructor it will 
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.

*/
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object. 
    // void run(int count) {
    //     while(count-- > 0)
    //         cout << "CppNuts" << endl;
    //     this_thread::sleep_for(chrono::seconds(3)); //mất 3's để in "main() after"
        
    // }
    // int main() {
    //     thread t1(run, 10);
    //     cout << "main()" << endl;
    //     t1.join();
    //     cout << "main() after" << endl;

    //     return 0;
    // }

// 1. Double join will result into program termination.
    // void run(int count) {
    //     while(count-- > 0)
    //         cout << "CppNuts" << endl;
    //     this_thread::sleep_for(chrono::seconds(3)); 
        
    // }
    // int main() {
    //     thread t1(run, 10);
    //     cout << "main()" << endl;
    //     t1.join();
    //     // t1.join(); //không thể join một thread đã kết thúc.
    //     cout << "main() after" << endl;

    //     return 0;
    // }
// 2. If needed we should check thread is joinable before joining, (using joinable() function)
    // void run(int count) {
    //     while(count-- > 0)
    //         cout << "CppNuts" << endl;
    //     this_thread::sleep_for(chrono::seconds(3)); 
        
    // }
    // int main() {
    //     thread t1(run, 10);
    //     cout << "main()" << endl;
    //     t1.join();

    //     if(t1.joinable())
    //         t1.join();
    //     cout << "main() after" << endl;

    //     return 0;
    // }
//0. This is used to detach newly created thread from the parent thread. 
    // void run(int count) {
    //     while(count-- > 0)
    //         cout << count << " CppNuts" << endl;
    //     // std::this_thread::sleep_for(chrono::seconds(5));
    //     cout << "thread finished" << endl; 
        
    // }
    // int main() {
    //     std::thread t1(run, 10);
    //     cout << "main()" << endl;
    //     t1.detach(); //độc lập với tiến trình chính
    //                 // in ra "main() after" mà không đợi thread t1 kết thúc

    //     cout << "main() after" << endl;
    //     std::this_thread::sleep_for(chrono::seconds(5));

    //     return 0;
    // }
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detach() will result into program termination. 
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.
    void run(int count) {
    while(count-- > 0)
        cout << count << " CppNuts" << endl;
    // std::this_thread::sleep_for(chrono::seconds(5));
    cout << "thread finished" << endl; 
        
    }
    int main() {
        /*The moment you create a thread that thread is marked as joinable and then later once either you apply join() or detach() 
        on that thread then it automatically becomes non-joinable.*/
        std::thread t1(run, 10);
        cout << "main()" << endl;

        t1.detach();
        // t1.detach(); error, the same join()
        if(t1.joinable())
            t1.detach();

        cout << "main() after" << endl;
        // std::this_thread::sleep_for(chrono::seconds(5));

        return 0;
    }