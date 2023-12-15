//passing_arrays_to_functions
#include<iostream>
using namespace std;

// Hàm nhận một mảng thông qua tham chiếu
void processArray(int (&arr)[5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int myArray[5] = {1, 2, 3, 4, 5};

    // Gọi hàm và truyền mảng vào thông qua tham chiếu
    processArray(myArray);

    return 0;
}