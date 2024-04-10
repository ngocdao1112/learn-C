// https://www.youtube.com/watch?v=dXI9_9WoTVw
#include <iostream>
#include <list>
using namespace std;

int main() {
// How to add elements to the list ?
    // list<int> myList;
    // myList.push_back(10);
    // myList.push_back(20);
    // myList.push_front(30);
    // myList.erase(myList.begin());

    // for(list<int>::iterator it = myList.begin(); it != myList.end(); it++) {
    //     cout << *it << endl;
    // }
}
// Creating a matchmaking system ?
void displayRatings(const list<int>& playerRatings) {
    for(list<int>::const_iterator it = playerRatings.begin(); it != playerRatings.end(); it++) {
        cout << "Players rating: " << *it << endl;
    }
}

int main() {
    list<int> allPlayers = {2,9,6,7,3,1,4,8,3,2,9};
    list<int> beginners; //rating 1-5
    list<int> pros; //rating 6-10

    for(list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++) {
        int rating = *it;
        if(rating >= 1 && rating <= 5)
            beginners.push_back(rating);
        else if(rating >= 6 && rating <= 10)
            pros.push_back(rating);
    }

    cin.get();
}