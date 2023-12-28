/*
make
valgrind ./out
man malloc
- Kiểm tra heap memory leak:
valgrind --leak-check=full ./my_program

- Kiểm tra stack memory leak:
valgrind --leak-check=full --track-origins=yes ./my_program

- Kiểm tra sử dụng uninitialized values:
valgrind --track-origins=yes ./my_program

- Kiểm tra tất cả các loại lỗi (bộ nhớ, uninitialized values, v.v.):
valgrind --tool=memcheck ./my_program

*/