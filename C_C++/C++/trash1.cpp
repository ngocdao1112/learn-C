#include <iostream>
using namespace std;

// Khi bạn cần quản lý động bộ nhớ, tức là cấp phát và giải phóng bộ nhớ tại runtime.
// Dùng new để cấp phát bộ nhớ và delete để giải phóng.

//khởi tạo pointer
    // int *ptr;
    // *ptr = 5;


//pointer arithmetic
    // int ptr1[] = { 1,2,3,4,5};
    // int *ptr2 = ptr1;
    // for(int i=0; i<size(ptr1); i++) {
    //     cout << *(ptr2++) << " ";
    //     }


//array of pointer
    // int size;
    // cout << "size: ";
    // cin >> size;

    // int *arr = new int[size];
    // for(int i=0; i<size; i++) 
    // {
    //     cout << "arr[" << i <<"] = ";
    //     cin >> arr[i];
    // }
    // for(int i=0; i < size; i++) 
    // {
    //     // cout << arr[i] << ' ';
    //     cout << *(arr+i) << ' ';
    // }

    // delete [] arr;
    // arr = NULL;

//pointer to array
    // int arr[] = {12,3,4,512};
    // int *ptr3 = &arr[1];
    // for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
    //     cout << *(ptr3+i) << " ";
    // }

#include <iostream>

int* createArray(int size) {
    int* arr = new int[size]; // Tạo một mảng số nguyên động có kích thước 'size'
    
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // Gán giá trị từ 1 đến 'size' cho các phần tử trong mảng
    }
    
    return arr; // Trả về con trỏ tới mảng đã tạo
}

int main() {
    int* myArray = createArray(5); // Gọi hàm và nhận con trỏ tới mảng trả về
    
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << " "; // In ra các phần tử trong mảng đã tạo
    }
    
    delete[] myArray; // Xóa mảng để giải phóng bộ nhớ đã được cấp phát
    
    return 0;
}