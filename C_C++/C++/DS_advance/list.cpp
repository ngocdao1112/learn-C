#include <bits/stdc++.h>
using namespace std;
/*
  danh sách liên kết kép
 chèn và xóa hiệu quả ở cả đầu và cuối danh sách
*/
//list 1:
    // void showList(list <int> g) 
    // {
    //     list <int> :: iterator it;
    //     for(it = g.begin(); it != g.end(); it++)
    //         cout << *it << ' ';
    //     cout << '\n';
    // }

    // int main() {
    //     list <int> gqlist1, gqlist2;
    //     for(int i=0; i<10; i++) 
    //     {
    //         gqlist1.push_back(i*3);
    //         gqlist2.push_front(i*3);
    //     }

    //     cout << "First list: ";
    //     showList(gqlist1);
    //     cout << "Second list: ";
    //     showList(gqlist2);
    // }
        /*
        First list: 0 3 6 9 12 15 18 21 24 27  
        Second list: 27 24 21 18 15 12 9 6 3 0
        */
//list 2
    // void showList(list <int> g) {
    //     list <int> :: iterator it;
    //     for(it = g.begin(); it != g.end(); it++)
    //         cout << *it << " ";
    //     cout << '\n';
        
    // }

    // int main() {
    //     list <int> gqlist1;
    //     for(int i=0; i<10; i++) {
    //         gqlist1.push_back(i*3);
    //     }
    //     cout << "List: ";
    //     showList(gqlist1);
    //     gqlist1.pop_front();
    //     cout << "List after deletion from front: ";
    //     showList(gqlist1);
    //     gqlist1.pop_back();
    //     cout << "List after deletion from back: ";
    //     showList(gqlist1);
    // }
        /*
        List: 0 3 6 9 12 15 18 21 24 27 
        List after deletion from front: 3 6 9 12 15 18 21 24 27
        List after deletion from back: 3 6 9 12 15 18 21 24
        */
//list 3
    // void showList(list <int> g) {
    //     list <int> :: iterator it;
    //     for(it = g.begin(); it != g.end(); it++)
    //         cout << *it << " ";
    //     cout << '\n';
    // }

    // int main() {
    //     list <int> gqlist1;
    //     for(int i=0; i<10; i++) {
    //         gqlist1.push_back(i*3);
    //     }
    //     cout << "List: ";
    //     showList(gqlist1);
    //     gqlist1.reverse();
    //     cout << "List after reversal: ";
    //     showList(gqlist1);
    // }
        /*
        List: 0 3 6 9 12 15 18 21 24 27 
        List after reversal: 27 24 21 18 15 12 9 6 3 0
        */
//list 4
    // void showList(list <int> g) {
    //     list <int> :: iterator it;
    //     for(it = g.begin(); it != g.end(); it++)
    //         cout << *it << " ";
    //     cout << '\n';
    // }
    // int main() {
    //     list <int> gqlist1;
    //     for(int i=0; i<10; i++) {
    //         gqlist1.push_back(i*3);
    //     }
    //     cout << "List: ";
    //     gqlist1.reverse();
    //     showList(gqlist1);
    //     gqlist1.sort();
    //     cout << "List after sorting: ";
    //     showList(gqlist1);
    // }
        /*
        List: 27 24 21 18 15 12 9 6 3 0 
        List after sorting: 0 3 6 9 12 15 18 21 24 27
        */
//list 5
    void showList(list <int> g) {
        list <int> :: iterator it;
        for(it = g.begin(); it != g.end(); it++)
            cout << *it << " ";
        cout << '\n';
    }
    int main() {
        list <int> gqlist1;
        for(int i=0; i<10; i++) {
            gqlist1.push_back(i*3);
        }
        cout << "List: ";
        showList(gqlist1);
        gqlist1.remove(6);
        cout << "After removing 6: ";
        showList(gqlist1);
        gqlist1.clear();
        cout << "Size: " << gqlist1.size() << endl;
        
    }
        /*
        List: 0 3 6 9 12 15 18 21 24 27 
        After removing 6: 0 3 9 12 15 18 21 24 27
        Size: 0
        */