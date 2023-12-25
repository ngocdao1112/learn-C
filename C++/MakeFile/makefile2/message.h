#ifndef MESSAGE_H
/*
- Đây là một lệnh tiền biên dịch (preprocessor directive) sử dụng để kiểm tra xem MESSAGE_H đã được định nghĩa trước đó trong quá trình biên dịch hay chưa.
- Nếu MESSAGE_H chưa được định nghĩa, đoạn mã trong #ifndef và #endif sẽ được bao quanh và thực thi. Nếu đã được định nghĩa, đoạn mã này sẽ bị bỏ qua, tránh việc định nghĩa trùng lặp.
*/
#define MESSAGE_H
/*
- Nếu MESSAGE_H chưa được định nghĩa, đoạn mã trong #define sẽ định nghĩa nó.
- Điều này giúp ngăn chặn định nghĩa trùng lặp của tên file trong quá trình biên dịch.
- #define MESSAGE_H: Nếu MESSAGE_H chưa được định nghĩa (tức là nếu không có #ifndef trước đó), 
lệnh #define sẽ định nghĩa macro MESSAGE_H. Điều này ngăn chặn việc định nghĩa trùng lặp của MESSAGE_H trong quá trình biên dịch.
*/

class message {
    public:
        void printMessage();
};

#endif //MESSAGE_H
/*
- Đây là lệnh tiền biên dịch đóng (#endif) để đóng kết thúc phần giữa #ifndef và #define.
- Kết thúc của mỗi tệp header thường kết thúc bằng một lệnh đóng như vậy để đảm bảo tính toàn vẹn của quá trình biên dịch và tránh định nghĩa trùng lặp.
*/

/*================================================================================
1. Lần đầu tiên message.h được include trong một file, MESSAGE_H chưa được định nghĩa.
2. #ifndef MESSAGE_H sẽ thành công vì MESSAGE_H chưa tồn tại.
3. #define MESSAGE_H sẽ định nghĩa MESSAGE_H, ngăn chặn việc xử lý đoạn mã bên trong #ifndef và #endif trong tương lai.
4. Lần thứ hai trở đi message.h được include, #ifndef MESSAGE_H sẽ thất bại vì MESSAGE_H đã được định nghĩa trước đó, 
và do đó đoạn mã bên trong #ifndef và #endif sẽ bị bỏ qua để tránh định nghĩa trùng lặp.
*/