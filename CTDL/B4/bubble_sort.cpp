//total: sau mỗi vòng lặp, những số lớn nhất bị đẩy về sau cùng, và k được xét ở vòng lặp tiếp theo
#include <iostream>
#include <fstream>
using namespace std;

void _swap(int &a, int &b) {
    int x=a;
    a = b;
    b = x;
}
int main() {
    ifstream fi(".//CTDL//B4//bubbleInp"); 
    ofstream fo(".//CTDL//B4//bubbleOut");
    int n;
    fi >> n;
    int arr[5];
    for(int i=1; i<=n; i++) {
        fi >> arr[i]; //nhap vao 1 mang
    }
    for(int i=1; i<=n; i++) { //mục đích của i là để giảm phạm vi của vòng lặp
        bool check_swap = true;
        //nếu check_swap = true thì trong vòng lặp ko cần đổi vị trí arr[i] và arr[i+1]
        //ngc lại nếu check_swap = false thì trong vòng lặp đã đổi vị trí của arr[i] và arr[i+1]
        for(int j=1; j <= n-i+1; j++) { // dùng để duyệt qua từng phần tử
            if(arr[j] > arr[j+1]) {
                check_swap = false;
                _swap(arr[j], arr[j+1]);
            }
        }
        if(check_swap == true) break;
    }
    for(int i=1; i<=n; i++) {
        fo << arr[i] << " ";
    }

    return 0;
}

