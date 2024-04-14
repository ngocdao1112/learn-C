// TOPIC: forward list In STL
/*
1. This is single linked list what we know from C programing language.
2. Why forward list why not single list ?
3. We should use this class instead of traditional single linked list because
    a. Well tested
    b. Bunch of available function
4. Few Available Operations
    operator = assign, front, empty, max_size, clear, insert_after, emplace_after, reverse, sort, merge
    splice_after, unique, remove, remove_if, resize
*/

#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    // forward_list<int> list1 = {5, 4, 6, 2};
    forward_list<int> list1 = {5, 2, 4, 6, 2};
    forward_list<int> list2 = {7, 6, 1, 9};
    // list1.reverse(); case 2
    // list1.insert_after(list1.begin(), 8); // case 1

    // case 3
    // list1.sort();
    // list2.sort();
    // list1.merge(list2);

    // case 4: Chuyển các phần tử từ List2 vào sau phần tử đầu tiên của List1
    // list1.splice_after(list1.begin(), list2);

    // case 5:
    // list1.unique();
    // list1.remove(2);

    // case 6:
    // list1.remove_if([] (int n) {
    //     return n > 4;
    // });

    // case 7:
    // list1.resize(2);
    list1.resize(6); // 5 2 4 6 2 0 

    for(auto& elm: list1)
        cout << elm << " ";
    
    // cout << "\nSize of list2: "
    //      << std::distance(list2.begin(), list2.end())
    //      << endl;
    return 0;
}
/*case 1
5 8 4 6 2
*/

/*case 4
5 7 6 1 9 4 6 2
*/