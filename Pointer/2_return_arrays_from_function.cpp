#include<iostream>
using namespace std;
//return_arrays_from_function

// Hàm trả về một mảng nguyên
void createArray(int size, int result[]) {
    // Gán giá trị cho mảng
    for (int i = 0; i < size; ++i) 
    {
        result[i] = i*2;
    }
}

int main() {
    int arraySize = 5;
    int myArray[arraySize];

    // Gọi hàm để điền giá trị vào mảng
    createArray(arraySize, myArray);

    // In ra các phần tử của mảng
    for (int i = 0; i < arraySize; ++i) 
    {
        cout << myArray[i] << " ";
    }

    return 0;
}