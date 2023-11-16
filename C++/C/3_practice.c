#include <stdio.h>
#include <stdlib.h>

// This stores the total number of books in each shelf.
// lưu tổng số sách trên mỗi kệ
int* books;

// This stores the total number of pages in each book of each shelf.
// lưu tổng số trang của mỗi sách của mỗi kệ
// The rows represent the shelves and the columns represent the books.
// row đại diện cho kệ, column thì đại diện cho sách
int** pages;

int main()
{
    int shelves;
    scanf("%d", &shelves);
    
    int queries;
    scanf("%d", &queries);
    
    while (queries--) {
        int query;
        scanf("%d", &query);
        
        if (query == 1) {
            books = (int*)malloc(shelves* sizeof(int)); //5 - shelves
            
            int x, y;
            scanf("%d %d", &x, &y);

        } else if (query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(books + x));
        }
    }

    // if (total_number_of_books) {
    //     free(total_number_of_books);
    // }
    
    // for (int i = 0; i < total_number_of_shelves; i++) {
    //     if (*(total_number_of_pages + i)) {
    //         free(*(total_number_of_pages + i));
    //     }
    // }
    
    // if (total_number_of_pages) {
    //     free(total_number_of_pages);
    // }
    
    return 0;
}