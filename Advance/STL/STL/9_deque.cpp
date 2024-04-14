//TOPIC: std::deque in C++ (Double Ended Queue)
/*
NOTES:
1. std::deque is an indexed sequence container
2. It allows fast insertion at both beginning and end
3. Unlike vector elements of deque are not stored contiguous
4. It uses individual allocated fixed size array, with additional bookkeeping,
    meaning index based access to deque must perform two pointer dereference, but in vector we get in one dereference
5. The storage of deque is automatically expanded and contracted as needed.
cheaper than expension of vector
6. Expension of deque is cheaper than expension of vector
7. A deque holding just one element has to allocate its full internal array (e.g 8 times the object size on 
    64-bit libstdC++; 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libC++).

TIME COMPLEXITY:
- Random access - constant 0(1)
- Insertion or removal of elements at the end or beginning - constant 0(1)
- Insertion or removal of elements - linear 0(n) 

*/

#include <iostream>
#include <deque>
using namespace std;

void print(const std::deque<int>& dqu) {
    for(int num: dqu)
        cout << num << " ";
        cout << endl;
}

int main() {
    {
        std::deque<int> dqu = {2, 3, 4};
        dqu.push_front(1);
        dqu.push_back(5);
        print(dqu);
    }
    {
        std::deque<int> dqu = {2, 3, 4};
        dqu.pop_front();
        dqu.pop_back();
        print(dqu);
    }

    return 0;
}