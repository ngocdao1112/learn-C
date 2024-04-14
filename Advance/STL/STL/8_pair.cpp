//TOPIC: std::pair In C++

/* SYNTAX:
std::pair<T1, T2> obj;
NOTES:
1. std::pair is a struct templace that provides a way to store two heterogeneous objects as a single unit
2. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures
*/

#include <iostream>
#include <vector>
using namespace std;

void print(std::pair<int, int>& obj) {
    cout << obj.first 
         << " "
         << obj.second
         << endl;
}

int main() {
    {
        std::pair<int, int> obj(10, 20);
        print(obj);
    }
    {
        std::pair<int, int> obj = std::make_pair(10, 20);
        print(obj);
    }
    {
        std::vector<std::pair<std::string, unsigned int>> list; // uint
        list.push_back(make_pair("Rupesh", 30));
        list.push_back(make_pair("Hitesh", 28));
        // list.push_back(std::pair<std::string, int>("Bhupendra", 22));
        list.push_back(std::pair("Bhupendra", 22));
        list.push_back(std::pair("Sagar", 18));

        for(auto& elm: list) {
            cout << elm.first << " " 
                 << elm.second << endl;
        }
    }

    return 0;
}

/*
    10 20
    10 20
    Rupesh 30
    Hitesh 28
    Bhupendra 22
    Sagar 18
*/
/*
std::make_pair<int, int>(10, 20); // Cách cũ không sử dụng auto
=====
std::make_pair(10, 20); // Sử dụng auto để tự động suy luận kiểu dữ liệu
*/