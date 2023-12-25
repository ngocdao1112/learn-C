#include <iostream>
#include <string>
using namespace std;

class Printer {
    string _name;
    int _availablePaper;
public:
    Printer(string name, int availablePaper) {
        _name = name;
        _availablePaper = availablePaper;
    }
    void Print(string txtDoc) {
        int requiredPaper = txtDoc.length() / 10; //40/10=4 //1 trang 10 char, 40 char là 4 trang
        if(requiredPaper > _availablePaper)
            throw "No paper";
            // throw 101; //error vì const ở dưới nên phải viết 1 khối khác để catch nó

        cout << "Printing ..." << txtDoc << endl;
        _availablePaper -= requiredPaper; //_availablePaper = _availablePaper - requiredPaper (4) = 10 - 4 = 6
                                        //_availablePaper = _availablePaper - requiredPaper (4) = 6 - 4 = 2
                                        //_availablePaper = _availablePaper - requiredPaper (4) = 2 - 4 = error
    }
};
int main() {
    Printer myPrinter("HP DesJet 1234", 10);
    try {
        myPrinter.Print("Hello, my name is Ngoc. I'm a Software Engineer.");
        myPrinter.Print("Hello, my name is Ngoc. I'm a Software Engineer.");
        myPrinter.Print("Hello, my name is Ngoc. I'm a Software Engineer.");
        myPrinter.Print("Hello, my name is Ngoc. I'm a Software Engineer.");
        myPrinter.Print("Hello, my name is Ngoc. I'm a Software Engineer.");
    }

    // catch (...) { //xử lý bất kỳ exception nào, nhưng sẽ ưu tiên theo tứ tự từ dưới lên 
    //     cout << "Exception happened!" << endl;
    // }

    catch (const char *txtException) { // lỗi vì để catch default ở trên
        cout << "Exception: " << txtException << endl;
    }

    // catch (int exCode) {
    //     cout << "Exception: " << exCode << endl;
    // }

    catch (...) { //xử lý bất kỳ exception nào, nhưng sẽ ưu tiên theo tứ tự từ dưới lên 
        cout << "Exception happened!" << endl;
    }

    return 0;
}