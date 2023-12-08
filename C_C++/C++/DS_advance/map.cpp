#include <iostream>
#include <map>
// #include <unordered_map>
#include <string>
#include <list>
using namespace std;
/*
cấu trúc dữ liệu từ điển, lưu trữ các cặp giá trị khóa-đối tượng
Mỗi khóa là duy nhất và map tự động sắp xếp các khóa theo thứ tự tăng dần.
*/
int main() {
    // map<string, string> myDictionary; //strintg 1st là khóa, string 2nd là đối tượng
    // myDictionary.insert(pair<string, string>("apple", "der Adfel"));
    // myDictionary.insert(pair<string, string>("orange","die Orange, die Apfelsine"));
    // myDictionary.insert(pair<string, string>("straberry", "die Erdbeere"));
    // myDictionary.insert(pair<string, string>("banana", "die Banana"));

    // for(auto pair:myDictionary)
    //     cout << pair.first << " - " << pair.second << endl;

    map<string, list<string>> pokedex;
    list<string> pikachuAttacks {"thunder shock", "tail whip", "quick attack"};
    list<string> charmanderAttacks {"flame thrower", "scary face"};
    list<string> chikoriAttacks {"razor leaf", "poison powder"};

    pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
    pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
    pokedex.insert(pair<string, list<string>>("Chikorita", chikoriAttacks));

    for(auto pair:pokedex) {
        cout << pair.first << " - ";
        for(auto attack:pair.second)
            cout << attack << ", ";

        cout << endl;
    }

    // system("pause > 0");
}