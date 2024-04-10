//TOPIC: Best way to use vector in C++

//Problem in vector?
/*
Vector = LinkedList + Array
            |
        Dynamically

*/

#include <iostream>
#include <vector>
using namespace std;
/*
Vector: nếu dung lượng hiện tại không đủ lớn để chứa phần tử mới, 
vector sẽ cấp phát bộ nhớ mới với dung lượng lớn hơn, thường là gấp đôi dung lượng hiện tại.
*/
int main() {
    vector<int> Vec;
    // Vec.reserve(1000);
    Vec.reserve(31);
    for(int i=0; i<32; ++i) {
        Vec.push_back(i);
        cout << "Size: " << Vec.size() << "     Capacity: " << Vec.capacity() << endl;
    }

    return 0;
}