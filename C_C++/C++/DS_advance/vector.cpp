#include <bits/stdc++.h>
using namespace std;
//Vector, Iterator, Pair, Set(find, count, erase)
using ll = long long;
//hàm dùng nhiều nhất trong vector: push_back
//size: in ra số lượng ptu trong vector
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen(".//txt/input.txt", "r", stdin);
    // freopen(".//txt/output.txt", "w", stdout);
    // #endif
    // vector<int> v(10); mảng tĩnh có sẵn 10 ptu
    
    // vector<int> v; //{}
    // v.push_back(3); //{3}
    // v.push_back(2); //{3, 2}
    // v.push_back(1); //{3, 2, 1}
    // v.push_back(5); //{3, 2, 1, 5}

    // vector<int> v(3, 100); //{100, 100, 100}
    // v.push_back(3); //{100, 100, 100, 3}
    // v.push_back(2); //{100, 100, 100, 3, 2}
    // v.push_back(1); //{100, 100, 100, 3, 2, 1}
    // v.push_back(5); //{100, 100, 100, 3, 2, 1, 5}
    // cout << v.size() << endl;
    // for(int item:v) { //foreach
    //     cout << item << ' ';
    // }
    // cout << v[2] << endl;
    // for(int i=0; i<v.size(); i++) { //in theo thu tu
    //     cout << v[i] << ' ';
    // }
    // for(int i=v.size(); i>=0; i--) { //in nguoc lai
    //     cout << v[i] << ' ';
    // }

    //foreach: range base for loop
        // int a[5] = {3, 1, 2, 4, 5};
        // for(int item:a) {
        //     cout << item << ' ';
        // }
    //change ptu tron vector
        // for(int &x:v) { //tham chieu
        //     x=1000;
        // }
        // for(int i=0; i<v.size(); i++) { 
        //     v[i]=1000;
        // }
        // for(int x:v) {
        //     cout << x << ' ';
        // }
    //iterator: the same pointer
    // truy cập tuần tự các phần tử mà không cần biết cụ thể về cấu trúc của dãy đó.
    // cho phép lặp qua các phần tử của một dãy, như array hoặc list.
        // vector<int>::iterator it = v.begin();
        // ++it;
        // it +=2;
        // cout << *it << endl;
        // --it;
        // cout << *it << endl;
        // it +=3;
        // cout << *it << endl;

        // vector<int>::iterator it;
        // for(it = v.begin(); it != v.end(); it++) {
        //     cout << *it << ' ';
        // }
        // vector<int>::iterator it = v.end(); 
        // cout << *it << endl; // 0

        // vector<int>::iterator it = v.begin() + 4; //tro den ptu thu 5
        // cout << *it << endl;
    //nhap 1 so tu ban phim cho vector
        // vector<int> v;
        // int n; cin >> n;
        // for(int i=0; i<n; i++) { //cach 1
        //     int tmp; cin >> tmp;
        //     v.push_back(tmp);
        // }

        // int n; cin >> n;
        // vector<int> v(n); //cach 2
        // for(int i=0; i<n; i++) { 
        //     cin >> v[i];
        // }
        // // v.insert(v.begin() + 2, 100); //add vao ptu giua
        // // v.erase(v.begin() + 4); //xoa ptu o index 4
        // // v.pop_back(); //xoa ptu o cuoi
        // for(int x:v) cout << x << ' ';

    //auto: co the thay co vector, pair, set, map, iterator
    //vector<int>::iterator => auto
        // auto it = v.begin();
        // auto x = 100; //tu hieu int nhung phai gan gia tri neu ko loi
        // auto y = '@'; //tu hieu char
    //pair: lưu 1 cặp phần tử, sử dụng để kết hợp hai giá trị không liên quan với nhau
    //first
    //second
        // pair<int, int> p;
        // pair<int, long long> p;
        // pair<char, int> p;
        // pair<int, int> p = make_pair(10, 20);
        // pair<int, int> p = {10, 20};
        // cout << p.first << ' ' << p.second << endl;
        // pair<char, int> p1 = p;
        // cout << p1.first << ' ' << p1.second << endl;

        // int n; cin >>n;
        // pair<int, int> a[n];
        // for(int i=0; i<n; i++) {
        //     cin >> a[i].first >> a[i].second;
        // }
        // vector<pair<int, int>> v;
        // pair<int, pair<int, int>> p;
        // p.first = 10;
        // p.second.first = 20;
        // p.second.second = 30; //{10, 20, 30}
        // pair<int, vector<int>> p;

    //set: ko lưu trùng và tự động sắp xếp các ptu, multiset có thể lưu trùng số
    //insert: 0(logN), đi cùng với fine, count, erase
        // set<int> se; //{}
        // se.insert(2); //{2}
        // se.insert(2); //{2}
        // se.insert(3); //{2, 3}
        // se.insert(1); //{1, 2, 3}
        // cout << se.size() << endl; //3
        // for(int x:se) {
        //     cout << x << ' '; //1 2 3
        // }
        // cout << endl;
        // for(auto it=se.begin(); it != se.end(); it++) {
        //     cout << *it << ' '; // 1 2 3
        // }
        // cout << endl;
        // auto it = se.begin();
        // it += 1; //ko cho dịch vì set là dạng cây
        // cout << *it << endl;
        
        //dùng vector iterator ngược
        // for(auto  it = se.rbegin(); it != se.rend(); it++) {
        //     cout << *it << ' ';
        // }
    //find nhưng có iterator
        // int n;  cin >> n;
        // set<int> se;
        // for(int i=0; i<n; i++) {
        //     int x; cin >> x;
        //     se.insert(x);
        // }
        // if(se.find(15) != se.end()) {
        //     cout << "FOUND\n";
        // }
        // else {
        //     cout << "NOT FOUND\n";
        // }
    //count: the same find
        // int n;  cin >> n;
        // set<int> se;
        // for(int i=0; i<n; i++) {
        //     int x; cin >> x;
        //     se.insert(x);
        // }
        // if(se.count(15) != 3) {
        //     cout << "FOUND\n";
        // }
        // else {
        //     cout << "NOT FOUND\n";
        // }
        // se.erase(5); //nếu k tìm thấy 5 sẽ bị lỗi, sử dụng count or find để check xem có không rồi mới xóa
        // for(int x:se) cout << x << ' ';
    //xóa phần tử trong multiset
        // int n;  cin >> n;
        // multiset<int> se;
        // for(int i=0; i<n; i++) {
        //     int x; cin >> x;
        //     se.insert(x);
        // }
        // // se.erase(5); //sẽ xóa hết số 5 nếu có nhiều số 5 trong mảng
        // auto it = se.find(5);
        // se.erase(it); // chỉ xóa phần tử đầu tiên
        // for(int x:se) cout << x << ' ';
    //unordered_set: ít dùng
    //BTAP:
        // int a[7] = {5, 5, 1, 2, 3, 4, 5};
        // set<int> se(a, a+7);
        // auto it = se.find(7);
        // --it;
        // cout << *it << endl; //5

        // int a[7] = {5, 5, 1, 2, 3, 4, 5};
        // set<int> se(a, a+7);
        // auto it = se.find(4);
        // it -= 2; //error do set là dạng cây
        // cout << *it << endl;

        
    

    return 0;
}