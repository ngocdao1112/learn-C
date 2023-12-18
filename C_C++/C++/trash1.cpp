#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    
    // Create a vector of n vectors
    vector<vector<int>> a(n);
    
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }    
    }
    
    for (int i = 0; i < q; i++) {
        int j, k;
        cin >> j >> k;
        cout << a[j][k] << endl;
    }

    return 0;
}
