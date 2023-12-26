/*
Định nghĩa cách biến và hàm được lưu trữ và hoạt động trong bộ nhớ của máy tính. 
Các lớp lưu trữ quy định phạm vi và thời gian tồn tại của biến hoặc hàm.

1. Auto (auto):
    - Từ khóa auto thường không được sử dụng, vì nó là giá trị mặc định cho biến cục bộ.
        void example() {
            auto int x = 10;
        }
2. Register (register):
    - Biến được lưu trữ trong thanh ghi máy tính để truy cập nhanh hơn.
    - Không thể sử dụng địa chỉ của biến register.
    - Compiler có thể bỏ qua yêu cầu và lưu trữ biến trong bộ nhớ nếu cần.
        register int count = 0;
3. Static (static):
    - Biến static có thời gian tồn tại suốt chương trình.
    - Nếu được khai báo trong hàm, giá trị của biến sẽ được giữ nguyên giữa các lần gọi hàm.
    - Nếu được khai báo ở mức file, biến sẽ có phạm vi toàn cục trong file đó.
        static int globalVar = 0; // static biến toàn cục

        void example() {
            static int localVar = 0; // static biến cục bộ
        }
4. Extern (extern):
    - Biến được khai báo với từ khóa extern sẽ được tìm kiếm ở bất kỳ đâu trong chương trình.
    - Thường được sử dụng để khai báo biến toàn cục được định nghĩa ở một nơi khác.
        extern int globalVar; // Khai báo biến toàn cục ở một file khác

*/