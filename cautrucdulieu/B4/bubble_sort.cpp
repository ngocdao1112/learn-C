#include <iostream>
#include <fstream>
using namespace std;

void _swap(int &a, int &b) {
    int x=a;
    a = b;
    b = x;
}
int main() {
    ifstream fi(".//bubbleInp"); 
    ofstream fo(".//bubbleOut");
    int n;
    fi >> n;
    int arr[10];
    for(int i=1; i<=n; i++) fi >> arr[i]; //nhap vao 1 mang
    for(int i=1; i<=n; i++) {
        bool check_swap = true;
        //nếu check_swap  = true thì trong vòng lặp ko cần đổi vị trí arr[i] và arr[i+1]
        //ngc lại nếu check_swap = false thì trong vòng lặp đã đổi vị trí của arr[i] và arr[i+1]
        for(int j=1; j <= n-i+1; j++) {
            if(arr[j] > arr[j+1]) {
                check_swap = false;
                _swap(arr[i], arr[i+1]);
            }
        }
        if(check_swap == true) break;
    }
    for(int i=1; i<=n;i++) fo << arr[i] << " ";

    return 0;
}