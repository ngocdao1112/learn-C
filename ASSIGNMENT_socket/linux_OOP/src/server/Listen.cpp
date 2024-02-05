#include "PrintError.cpp"
#include "./Server.h"
/*
backlog: Nếu có nhiều kết nối đến cùng một lúc mà socket không thể xử lý ngay lập tức, 
hệ thống sẽ giữ chúng trong hàng đợi (backlog) và xử lý chúng theo thứ tự.
*/
void Listen(int sockfd, int backlog) {
    if(listen(sockfd, backlog) < 0) {
        PrintError();
        throw runtime_error("Failed to listen!")

    }
}