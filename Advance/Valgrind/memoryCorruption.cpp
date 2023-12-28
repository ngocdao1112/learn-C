/*
- lỗi xảy ra khi dữ liệu trong bộ nhớ bị thay đổi một cách không đúng đắn.
    +  truy cập vào một phần của bộ nhớ không được cấp phát
    + sử dụng con trỏ đã bị giải phóng
    + ghi quá giới hạn của mảng
1. Buffer Overflow: 
    - Khi bạn ghi quá giới hạn của mảng hoặc bộ đệm, dữ liệu có thể lan sang các vùng bộ 
    nhớ khác, gây memory corruption
2. Accessing Freed Memory: 
    - Truy cập vào bộ nhớ đã được giải phóng có thể dẫn đến memory corruption, 
    vì dữ liệu trong đó có thể đã bị thay đổi hoặc bị ghi đè.
3. Race Conditions: 
    - Trong môi trường đa luồng, nếu hai luồng cùng truy cập và sửa đổi dữ liệu mà không 
    có bảo vệ, có thể xảy ra memory corruption.
4. Pointer Arithmetics Errors: 
    - Sử dụng sai cú pháp con trỏ, chẳng hạn như việc nhảy quá hoặc giảm giá trị con trỏ 
    một cách không đúng, có thể dẫn đến memory corruption.

*/
// 1. Buffer Overflow: 
#include <iostream>
#include <cstring>

void bufferOverflow(char* buffer) {
    // Ghi quá giới hạn của buffer
    strcpy(buffer, "Buffer Overflow Example");
}

int main() {
    // Khởi tạo một buffer có kích thước 10
    char myBuffer[10];

    // Gọi hàm bufferOverflow với buffer quá nhỏ
    bufferOverflow(myBuffer);

    // In nội dung của buffer
    std::cout << myBuffer << std::endl;

    return 0;
}

/*
==1234== Invalid write of size 23
==1234==    at 0x400689: bufferOverflow(char*) (my_program.cpp:6)
==1234==    by 0x4006A9: main (my_program.cpp:14)
==1234==  Address 0x5204060 is 0 bytes after a block of size 10 alloc'd
===> bạn có thể thấy rằng dữ liệu đã được ghi vào vùng nhớ sau buffer (Address 0x5204060 is 0 bytes after a block of size 10).

==1234==    at 0x4C2D7E3: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==1234==    by 0x400695: main (my_program.cpp:12)
==1234== 
Buffer Overflow Example
*/


// 3. Race Conditions: 
#include <iostream>
#include <thread>
#include <vector>

// Biến toàn cục sẽ được sử dụng bởi nhiều luồng mà không có sự đồng bộ
int counter = 0;

// Hàm thực hiện tăng giá trị của biến toàn cục
void incrementCounter() {
    for (int i = 0; i < 1000000; ++i) {
        counter++;
    }
}

int main() {
    const int numThreads = 5;
    std::vector<std::thread> threads;

    // Tạo và thêm các luồng vào vector
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementCounter);
    }

    // Đợi tất cả các luồng hoàn thành công việc của mình
    for (auto& thread : threads) {
        thread.join();
    }

    // In giá trị cuối cùng của counter
    std::cout << "Final Counter Value: " << counter << std::endl;

    return 0;
}

/*
==1234== Helgrind, a thread error detector
==1234== Copyright (C) 2007-2019, and GNU GPL'd, by OpenWorks LLP
==1234== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1234== Command: ./my_program
==1234== 
--1234-- WARNING: Serious error in the application.
--1234-- VGHelgrind has found a race in the program.
--1234--    Add "--history-level=full" to the helgrind command line
==> sử dụng --history-level=full để xem thông tin chi tiết về nơi race condition đã xảy ra.

--1234--    to see details about where the race was detected.
--1234-- 
==1234== 
==1234== For counts of detected and suppressed errors, rerun with: -v
==1234== Use --history-level=approx or =none to gain increased speed, at
==1234== the cost of reduced accuracy of conflicting-access information
==1234== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

*/
/*
- race conditions xảy ra tại biến toàn cục counter
- nhiều luồng đang cùng thao tác (tăng giá trị) lên biến counter mà không có bất kỳ cơ chế 
đồng bộ hóa nào để đảm bảo tính nhất quán.

- Race conditions xảy ra khi một hoặc nhiều luồng thực hiện các thao tác đọc và ghi trên 
cùng một biến mà không có sự đồng bộ hóa.
- nhiều luồng đang thực hiện phép tăng (counter++) đồng thời mà không có biện pháp bảo vệ.

- Để giải quyết race conditions, bạn có thể sử dụng các cơ chế đồng bộ hóa như mutex. 
Dưới đây là một ví dụ với việc sử dụng std::mutex để bảo vệ biến toàn cục:
*/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int counter = 0;
std::mutex counterMutex;  // Mutex để bảo vệ biến counter

void incrementCounter() {
    for (int i = 0; i < 1000000; ++i) {
        // Sử dụng std::lock_guard để tự động giải phóng mutex khi kết thúc scope
        std::lock_guard<std::mutex> lock(counterMutex);
        counter++;
    }
}

int main() {
    const int numThreads = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementCounter);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Final Counter Value: " << counter << std::endl;

    return 0;
}
/*
- std::mutex được sử dụng để đảm bảo rằng chỉ một luồng có thể thay đổi giá trị 
của counter tại một thời điểm.
- std::lock_guard được sử dụng để tự động giải phóng mutex khi kết thúc phạm vi 
của nó, giúp tránh thiếu sót trong việc giải phóng mutex.
*/