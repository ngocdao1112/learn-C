#include <iostream>
#include <vector>
using namespace std;
/*
Vector có nghĩa là nó giống như 1 container che giấu hoàn toàn việc quản lý bộ nhớ khỏi deverloper

- STATIC ARRAY:
    1. lưu ptu ở vị trí bộ nhớ tiếp theo, chứa các phần tử có cùng datatype & có kích thước cố định
    2. có thể access nhanh chóng
    3. được khởi tạo sẵn, và k thể change trong quá trình chạy
- VECTOR & DYNAMIC ARRAY
    1. luôn dùng vector thay vì dynamic arr
    2. 
*/
int main() {
    vector<int> Numbers;
    // Numbers.push_back(0);

    // for(int i=1; i<=3; i++) {
    //     Numbers.push_back(i);
    // }

    // for(int number : Numbers)
    //     cout << number << endl; //1 2 3

    // for(auto it = Numbers.begin(); it != Numbers.end(); it++) {
    //     // cout << it << endl; error
    //     // cout << *it << endl;
    //     // cout << &it << endl; //in địa chỉ của pointer it
    //     // cout << &(*it) << endl; // In địa chỉ của phần tử mà con trỏ it đang trỏ đến.
    // }
    
    // auto it = Numbers.begin();
    // cout << *(it+5); //5 và nếu bắt đầu từ 1 thì in ra 6

    // for(auto it=Numbers.begin(); it != Numbers.end(); it++) {
    //     *it = 20; 
    //     cout << *it << endl; //in ra 20 20 20
    // }

    // for(auto it=Numbers.cbegin(); it != Numbers.cend(); it++) {
    //     *it = 20; //error vì ở trên là const nên k thể change value
    //     cout << *it << endl; 
    // }

    for(int i=1; i<=10; i++) {
        Numbers.push_back(i);
    }
    // cout << "Size: " << Numbers.size() << endl;
    // cout << "Max size: " << Numbers.max_size() << endl;
    // cout << "Capacity: " << Numbers.capacity() << endl;
    // Numbers.resize(5);
    // cout << "Size: " << Numbers.size() << endl;
    // if(Numbers.empty())
    //     cout << "Vector is empty\n";
    // else    
    //     cout << "Vector is not empty\n";
    // cout << "Element [0] is: " << Numbers[0] << endl;
    // cout << "Element at(0) is: " << Numbers.at(0) << endl; //in phần tử đầu tiên nhưng dùng func
    // cout << "Front: " << Numbers.front() << endl;
    // cout << "Back: " << Numbers.back() << endl;
    // Numbers.clear();
    // cout << "Size: " << Numbers.size() << endl;

    Numbers.insert(Numbers.begin() + 5, 88);
    Numbers.erase(Numbers.begin() + 5);
    Numbers.pop_back();
    for(auto n:Numbers)
        cout << n << endl;

    // cin.get();
}