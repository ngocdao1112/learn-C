#include <iostream>
#include <cstring>
using namespace std;

struct Book  // Removed the semicolon and fixed the struct name
{
    char title[100];
    char author[100];
    float priceBook;
};

int main() {
    // Initializing an object
    Book book1;

    cout << "Enter title: ";
    // gets(book1.title);
    fgets(book1.title, sizeof(book1.title), stdin);

    cout << "Enter author: ";
    // gets_s(book1.author);
    fgets(book1.author, sizeof(book1.author), stdin);

    cout << "Enter priceBook: ";
    cin >> book1.priceBook;

    //sao chép thông tin đối tượng book1 cho book2
    Book book2 = book1; // sao chép, và mỗi thằng quản lý 1 ô nhớ riêng
    //xuất thông tin  
    cout << "Infor book2: " << endl;
    cout << "Title book: " << book2.title;
    cout << "Author book: " << book2.author;
    cout << "PriceBook: " << book2.priceBook;
    cout << endl;
    // thay đổi infor book1
    book1.priceBook = 9999;
    // xuất infor của book1 và book2 sau khi thay đổi
    cout << "PriceBook 2 = " << book2.priceBook << endl;
    cout << "PriceBook 1 after changed = " << book1.priceBook << endl;

    //check địa chỉ ô nhớ
    cout << "Address ô nhớ book 1: " << &book1 << endl;
    cout << "Address ô nhớ book 2: " << &book2 << endl;

    return 0;
}


