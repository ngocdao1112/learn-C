#include <iostream>
using namespace std;

class Book {
public:
    string Title;
    string Author;
    int* Rates;
    int RatesCounter;

    Book(string tiltle, string author) {
        Title = tiltle;
        Author = author;

        RatesCounter = 2;
        Rates = new int[RatesCounter];
        Rates[0] = 4;
        Rates[1] = 5;

        cout << Title + "constructor invoked\n";
    }

    ~Book() {
        delete []Rates; //nếu không xóa Rates = nullptr; sẽ bị memory leak
        Rates = nullptr;
        // cout << Title + "destructor invoked\n";
    }
};
/*
1. có nhiều construc nhưng chỉ có 1 destruc
2. ko nên hủy destruc theo manually, nó sẽ tự động hủy trong phạm vi của mỗi object
3. destruc k có tham số
4. nếu làm việc với pointer thì phải cần destruc nếu k sẽ bị memory leak
*/
int main() {
    Book book1("Milionaire Fastlane", "M. J. DeMarco");
    Book book2("C++ Lambda Story", "Bartek Filipek");

    // Book book3 = book2;memory leak
    cin.get();
    return 0;
}