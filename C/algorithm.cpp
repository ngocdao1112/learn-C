//BUBBLE SORT
    // void BubbleSort(int *A, int n) {
    //     //simple bubble sort
    //     int temp;
    //     for(int i=0; i<n; i++) {
    //         for (int j=0; j<n-1; j++) {
    //             // if(A[j] > A[j+1]) //6 5 4 3 2 1 
    //             if(A[j] > A[j+1]) { //compare A[j] with A[j+1] and SWAP if needed, 1 2 3 4 5 6
    //                 temp = A[j];
    //                 A[j] = A[j+1];
    //                 A[j+1] = temp;
    //             }
    //         }
    //     }
    // }
    // int main() {
    //     int A[] = {3,2,1,5,6,4}; // sort in increasing order => {1,2,3,4,5,6}
    //     BubbleSort(A,6);
    //     for(int i=0; i<6; i++) {
    //         printf("%d ", A[i]);
    //     }
    // }
/*
callback function should compare two integers, should return 1 if first element has higher rank, 
0 if elements are equal and -1 if second element has higher rank
*/
    // int compare(int a, int b) {
    //     if(a>b)
    //         // return 1; // 1 2 3 4 5 6
    //         return -1;
    //     else
    //         // return -1; //6 5 4 3 2 1 
    //         return 1;
    // }
    // void BubbleSort(int *A, int n, int (*compare)(int, int)) {
    //     //simple bubble sort
    //     int temp;
    //     for(int i=0; i<n; i++) {
    //         for (int j=0; j<n-1; j++) {
    //             if(compare(A[j], A[j+1]) > 0) { //compare A[j] with A[j+1] and SWAP if needed
    //                 temp = A[j];
    //                 A[j] = A[j+1];
    //                 A[j+1] = temp;
    //             }
    //         }
    //     }
    // }
    // int main() {
    //     int A[] = {3,2,1,5,6,4}; // sort in increasing/decreasing order
    //     BubbleSort(A, 6, compare);
    //     for(int i=0; i<6; i++) {
    //         printf("%d ", A[i]);
    //     }
    // }

    // int absolute_compare(int a, int b) {
    //     if(abs(a) > abs(b))
    //         return 1;
    //     return -1;
    // }
    // void BubbleSort(int *A, int n, int (*compare)(int, int)) {
    //     //simple bubble sort
    //     int temp;
    //     for(int i=0; i<n; i++) {
    //         for (int j=0; j<n-1; j++) {
    //             if(compare(A[j], A[j+1]) > 0) { //compare A[j] with A[j+1] and SWAP if needed
    //                 temp = A[j];
    //                 A[j] = A[j+1];
    //                 A[j+1] = temp;
    //             }
    //         }
    //     }
    // }
    // int main() {
    //     int A[] = {-31, 22, -1, 50, -6, 4}; // => {-1, 4, -6, 22, -31, 50}
    //     BubbleSort(A, 6, absolute_compare);
    //     for(int i=0; i<6; i++) {
    //         printf("%d ", A[i]);
    //     }
    // }

    // int compare(const void *a, const void *b) { //Hàm compare nhận vào hai con trỏ void, đại diện cho hai phần tử cần so sánh trong mảng A.
    //     int A = *((int*)a); // typecasting to int* and getting value
    //     int B = *((int*)b);
    //     // return A-B; // -31 -6 -1 4 22 50
    //     // return B-A; //50 22 4 -1 -6 -31
    //     return abs(A) - abs(B); // -1 4 -6 22 -31 50
    // }
    // int main() {
    //     int i, A[] = {-31, 22, -1, 50, -6, 4}; //=> {-1, 4, -6, 22, -31, 50}
    //     qsort(A, 6, sizeof(int), compare);
    //     /*  Tham số thứ nhất là mảng cần sắp xếp.
    //         Tham số thứ hai là số lượng phần tử trong mảng.
    //         Tham số thứ ba là kích thước của mỗi phần tử (ở đây là sizeof(int)).
    //         Tham số thứ tư là con trỏ đến hàm so sánh, ở đây là compare.
    //     */
    //     for(i=0; i<6; i++) {
    //         printf("%d ", A[i]); 
    //     }
    // }