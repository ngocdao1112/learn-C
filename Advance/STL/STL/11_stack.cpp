// TOPIC: std::stack in C++
/*
Notes:
0. std::stack class is a container adapter that gives the programmer the functionality of the stack
1. Internally it uses std::deque STL container
2. it is LIFO (last-in, first-out) data structure
3. std::stack allows to push(insert) and pop(remove) only from back

Functions provided:
- empty() - Returns whether the stack is empty - Time Complexity : 0(1)
- size() - Returns the size of the stack - Time Complexity : 0(1)
- top() - Returns a reference to the top most element of the stack - Time Complexity : 0(1)
- push() - Adds the element 'g' at the top of the stack - Time Complexity : 0(1)
- pop() - Deletes the top most element of the stack - Time Complexity : 0(1)
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// void print(std::stack<int> stk) {
void print(std::stack<int, std::vector<int>> stk) {
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop(); // remove from the back
    }
}

int main() {
    // std::stack<int> stk;
    std::stack<int, std::vector<int>> stk;

    stk.push(2);
    stk.push(3);
    stk.push(4);

    print(stk);

    return 0;
}