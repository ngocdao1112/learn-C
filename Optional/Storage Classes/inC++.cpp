/*
tính năng mới liên quan đến lớp lưu trữ và hành vi của đối tượng
1. Auto:
    - Mặc định cho tất cả các biến cục bộ.
    - Từ khóa auto cũng được sử dụng để xác định kiểu dữ liệu tự động dựa trên giá trị khởi tạo.
        auto x = 10; // Tự động xác định kiểu dữ liệu của x
2. Register:
    - Biến được lưu trữ trong thanh ghi máy tính để truy cập nhanh hơn.
    - Tương tự như trong C, tuy nhiên, Compiler có quyền quyết định lưu trữ trong thanh ghi hay bộ nhớ.
        register int count = 0;
3. Static:
    - Được sử dụng trong việc lưu trữ biến và hàm cục bộ, biến và hàm toàn cục.
    - Có thể sử dụng từ khóa static trong lớp để tạo biến và hàm tĩnh (static members) cho lớp.
        class Example {
        public:
            static int staticVar; // Biến tĩnh
            static void staticFunction() {
                // Hàm tĩnh
            }
        };
4. Extern:
    - Được sử dụng để khai báo và sử dụng biến và hàm ở nơi khác trong chương trình.
        extern int globalVar; // Khai báo biến toàn cục ở một file khác
5. Mutable:
    - Chỉ áp dụng cho các thành viên (members) của lớp.
    - Cho phép các thành viên không constant trong các hàm constant.
        class Example {
        public:
            mutable int mutableVar; // Thành viên có thể thay đổi trong hàm constant
        };
6. Thread_local:
    - Biến có phạm vi chỉ trong một luồng thực thi (thread).
    - Được sử dụng để tạo biến có giá trị độc lập cho từng luồng.
        thread_local int threadVar; // Biến chỉ có phạm vi trong mỗi luồng
*/