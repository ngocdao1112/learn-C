// en.cppreference.com/w/cpp/language/namspace
#include <iostream>
#include <string>
#include <algorithm>

/*
// namespace apple {
    void print(const char* text) {
        std::cout << text << std::endl;
    }
// }

// namespace orange {
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
// }

// using namespace apple;
// using namespace orange;

int main() {

    print("Hello");
    
    std::cin.get();

}
*/
/*ERROR
D:/VSCode/LearnC_C++/learn-C/C++/STD/2_namespace.cpp:13:10: error: redefinition of 'void print(const char*)'
   13 |     void print(const char* text) {
      |          ^~~~~
D:/VSCode/LearnC_C++/learn-C/C++/STD/2_namespace.cpp:7:10: note: 'void print(const char*)' previously defined here
    7 |     void print(const char* text) {

*/
//===============================================
/*
namespace apple {
    // namespace functions {
        void print(const char* text) {
            std::cout << text << std::endl;
        }
    // }
}

namespace orange {
    // namespace functions {
        void print(const char* text) {
            std::string temp = text;
            std::reverse(temp.begin(), temp.end());
            std::cout << temp << std::endl;
        }
    // }
}

int main() {

    apple::print("Hello");
    
    std::cin.get();

}
*/
//===============================================
// namespace apple {
namespace apple::functions {
    // namespace functions {
        void print(const char* text) {
            std::cout << text << std::endl;
        }
    // }
    void print_again() {}
}

namespace orange {
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

int main() {
    // using namespace apple;
    // using apple::print;
    // print("Hello");
    // apple::print_again();
    // print_again();

    // namespace a = apple;
    // using namespace apple::functions; //1
    // using namespace a = apple::functions; //3
    //a::print("Hello"); //3

    using namespace apple; //2
    using namespace functions; //2

    apple::functions::print("Hello");

    apple::print_again();
    
    
    std::cin.get();
}