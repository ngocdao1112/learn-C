#include <iostream>
using namespace std;

class Book {
public:
    string Title;
    string Author;
    float* Rates;
    int RatesCounter;

    Book(string tiltle, string author) {
        Title = tiltle;
        Author = author;

        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 5;
        Rates[1] = 4;
        cout << Title + " constructor invoked\n";
    }

    ~Book() {
        delete []Rates; //nếu không xóa Rates = nullptr; sẽ bị memory leak
        Rates = nullptr;
        cout << Title + " destructor invoked\n";
    }
    Book(const Book& original) { // tham chiếu (reference), truyền đối tượng vào hàm mà không tạo ra một bản sao của đối tượng đó.
                                // tăng hiệu suất và tiết kiệm bộ nhớ
                                // original sẽ trỏ đến cùng một đối tượng mà bạn truyền vào, không tạo bản sao mới
                                // muốn sao chép nội dung của một đối tượng vào một đối tượng mới mà không làm thay đổi đối tượng gốc
        Title = original.Title;
        Author = original.Author;
        // Rates = original.Rates;
        RatesCounter = original.RatesCounter;

        Rates = new float[RatesCounter];
        for(int i=0; i < RatesCounter; i++) {
            Rates[i] = original.Rates[i];
        
        }
        cout << "copy" << endl;

    }

};
void PrintBook(Book book) {
    cout << "Title: " << book.Title << endl;
    cout << "Author: " << book.Author << endl;

    float sum = 0;
    for(int i=0; i < book.RatesCounter; i++) {
        sum += book.Rates[i];
    }
    cout << "Avg rate: " << sum/book.RatesCounter << endl;
}
int main() {
    Book book1("Milionaire Fastlane", "M. J. DeMarco");
    Book book2("C++ Lambda Story", "Bartek Filipek");
    // Book book3(book1); //cách 1
    Book book3=book1;   //cách 2
    // book3 = book2; // gán lại các giá trị mới cho 1 object đã tồn tại
    PrintBook(book1);
    PrintBook(book2);
    PrintBook(book3);

    return 0;
}
/*
1. trong 1 class chung
2. void
3. cùng tên với class, nhận 1 tham số và tham số đó cùng kiểu với class
*/