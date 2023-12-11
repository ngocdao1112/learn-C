//find the eligibility of admission for an engineering course based on the criteria
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int candiateage;

    cout << "Input the age of the candidate: ";
    cin >> candiateage;

    if(candiateage < 18) {
        cout << "Sorry, you are not eligible to cast your vote." << '\n';
        cout << "You would be able to cast your vote after " << 18-candiateage << " year";
    }
    else
        cout << "Congratulation! you are eligible for casting your vote.";

    return 0;
}