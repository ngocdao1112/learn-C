#include <iostream>
using namespace std;

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
//pointer to pointer
    // int main() {
    //     int value = 42;
    //     int* pointerToValue = &value;  // Con trỏ trỏ tới biến value
    //     int** pointerToPointer = &pointerToValue;  // Con trỏ trỏ tới con trỏ

    //     // In giá trị và địa chỉ của biến
    //     cout << "Value: " << value << endl;
    //     cout << "Address of value: " << &value << endl;

    //     // In giá trị và địa chỉ của con trỏ
    //     cout << "Value pointed by pointerToValue: " << *pointerToValue << endl;
    //     cout << "Address stored in pointerToValue: " << pointerToValue << endl;

    //     // In giá trị và địa chỉ của con trỏ tới con trỏ
    //     cout << "Value pointed by pointerToPointer: " << **pointerToPointer << endl;
    //     cout << "Address stored in pointerToPointer: " << *pointerToPointer << endl;

    //     return 0;
    // }
//passing_pointers_to_functions
    // Hàm nhận một con trỏ và thay đổi giá trị mà nó trỏ tới
    // void modifyValue(int* pointer) {
    //     *pointer = 100;  // Thay đổi giá trị mà con trỏ trỏ tới
    // }

    // int main() {
    //     int myValue = 42;

    //     // Khai báo con trỏ và truyền địa chỉ của biến myValue vào nó
    //     int* myPointer = &myValue;
    //     cout << "Before function call: " << myValue << endl;

    //     // Gọi hàm và truyền con trỏ vào để thay đổi giá trị
    //     modifyValue(myPointer);
    //     cout << "After function call: " << myValue << endl;

    //     return 0;
    // }
//return_pointer_from_functions
    // Hàm trả về một con trỏ được cấp phát động
    int* createDynamicArray(int size) {
        int* newArray = new int[size];

        // Gán giá trị cho mảng
        for (int i = 0; i < size; ++i) {
            newArray[i] = i * 2;
        }

        return newArray;  // Trả về con trỏ tới mảng được cấp phát động
    }

    int main() {
        int arraySize = 5;

        // Gọi hàm để nhận con trỏ tới mảng
        int* myArray = createDynamicArray(arraySize);

        // In ra các phần tử của mảng
        for (int i = 0; i < arraySize; ++i) {
            cout << myArray[i] << " ";
        }

        // Nhớ giải phóng bộ nhớ khi không cần thiết nữa
        delete[] myArray;

        return 0;
    }
//function_pointer

