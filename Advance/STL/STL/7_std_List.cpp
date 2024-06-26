// TOPIC: list in STL
/*
1. This is double linked list what we know from C programming language
2. List is sequence container that allow non-contiguous memory allocation
3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of
    insertion, removal and moving elenments in any position provided we have the iterator of the position
4. We should use this class instead of traditional double linked list because
    a. Well tested
    b. Bunch of available function
5. Few available operations
    operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back
    push_front, pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize.
*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    // list<int> list1 = {5, 2, 4, 6, 2};
    list<int> list2 = {7, 6, 1, 9};

    // list1.sort();
    // list2.sort();
    // list1.merge(list2);
        // 1 2 2 4 5 6 6 7 9

    // list1.splice(list1.begin(), list2);
        //7 6 1 9 5 2 4 6 2

    // list1 = list2; // 7 6 1 9 

    list<int> list1 = {5, 2, 4, 6, 2, 2};
    list1.sort(); // 2 4 5 6
    list1.unique(); //5 2 4 6 2

    for(auto& elm: list1)
        cout << elm << ' ';
    cout << endl;
    // for(auto& elm: list2)
    //     cout << elm << ' ';
    // cout << endl;
    return 0;
}
