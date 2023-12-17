#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size;
    cin >> size;
    int arr[size];

    for(int i=1; i<=size; i++) {
        cin >> arr[i];
    }
    // reverse(dyArr, dyArr + size);
    for(int j=size; j>0; j--) {
        cout << arr[j] << ' ';
    }

    return 0;
}
