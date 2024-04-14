/* NOTEs: 
1. std::vector is a 'SEQUENCE CONTAINER' and also known as Dynamic Array or Array List
2. It's size can grow and shrink dynamically, and no need to provide size at complete time.

ELEMENT ACCESS
- at(), [], front(), back(), data()

MODIFIERS:
- insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()
- size(),
*/

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     // Declarations
//     std::vector<int> arr1;
//     std::vector<int> arr2 (5, 20);
//     std::vector<int> arr3 = {1, 2, 3, 4, 5}; // initializer list
//     std::vector<int> arr4 {1, 2, 3, 4, 5}; // uniform initialization

//     // Accessing Elements
//     arr2[3] = 10;
//     arr2.at(3) = 10;


// }

// Optimized way to use Vector in C
// TOPIC: Best way to use vector in C++

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> Vec;
    // Vec.reserve(1000);
    Vec.reserve(31);
    /*
    Size: 1 Capacity: 31
    Last element: 0
    Size: 2 Capacity: 31
    Last element: 1
    ..........
    Size: 31 Capacity: 31
    Last element: 30
    Size: 32 Capacity: 62
    Last element: 31
    */
    for(int i=0; i<32; ++i) {
        Vec.push_back(i);
        cout << "Size: " << Vec.size() << " Capacity: " << Vec.capacity() << endl;
        cout << "Last element: " << Vec.back() << endl; // In ra phần tử cuối cùng
    }
}