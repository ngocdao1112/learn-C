#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//hàm dùng nhiều nhất trong vector: push_back
//size: in ra số lượng ptu trong vector
int main() {
    #ifndef ONLINE_JUDGE
    freopen(".//txt/input.txt", "r", stdin);
    freopen(".//txt/output.txt", "w", stdout);
    #endif
    // vector<int> v(10); mảng tĩnh có sẵn 10 ptu
    vector<int> v; //{}
    v.push_back(3); //{3}
    v.push_back(2); //{3, 2}
    v.push_back(1); //{3, 2, 1}
    v.push_back(5); //{3, 2, 1, 5}
    cout << v.size() << endl;


}