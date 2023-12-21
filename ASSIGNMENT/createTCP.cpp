#include <iostream>
#include <winsock2.h>
#include <Ws2tcpip.h>

#pragma comment (lib, "ws2_32.lib")
// #pragma comment(lib, "ws2_32")

using namespace std;

void main() {
    // Initialize winsock / để khởi tạo môi trường
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData); //Thông tin về phiên bản và khởi tạo sẽ được lưu trữ trong biến 'wsData'
    if(wsOk != 0) {
        cerr << "Can't initialize winsock! Quitting" << endl;
        return;
    }
    // Create a socket /  sử dụng hàm socket() để tạo một socket.
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0); // AF_INET - IPv4,
                                                        // SOCK_STREAM - loại TCP, 
                                                        // 0 -  Winsock sẽ tự động chọn giao thức phù hợp cho loại socket và địa chỉ mạng đã chọn
    if(listening == INVALID_SOCKET) {
        cerr << "Can't create a socket! Quitting" << endl;
    }
    // Bind the IP address and port to a socket
    //cấu hình và gán một địa chỉ và cổng cho socket đã được tạo
    sockaddr_in hint; 
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000); //cổng mà bạn muốn socket lắng nghe
                                //hàm htons() được sử dụng để chuyển đổi từ định dạng máy tính thành định dạng mạng (Network Byte Order).
    hint.sin_addr.S_un.S_addr = INADDR_ANY; // Could alse use inet_pton ...
                                            // socket sẽ lắng nghe tất cả các địa chỉ IP của máy chủ
                                            // INADDR_ANY có thể được sử dụng để liên kết socket với tất cả các địa chỉ IP trên máy chủ.
    bind(listening, (sockaddr*)&hint, sizeof(hint)); // con trỏ đến cấu trúc sockaddr chứa thông tin địa chỉ và cổng (&hint)
                                                    // bind này xác định nơi mà socket sẽ lắng nghe và chấp nhận kết nối.
                                                    // gọi hàm listen để bắt đầu lắng nghe kết nối đến trên socket này.
    // Tell winsock the socket is for listening
    listen(listening, SOMAXCONN); // (SOMAXCONN) là số lượng tối đa các kết nối có thể đợi trong hàng đợi kết nối đến.

    // Wait for a connection
    sockaddr_in client; // sockaddr_in lưu trữ thông tin về client khi một kết nối được chấp nhận
    int clientsize = sizeof(client); // clientsize được sử dụng để lưu trữ kích thước của cấu trúc sockaddr_in.

    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientsize); // accept: chấp nhận một kết nối đến từ một client
                                                                            //  con trỏ đến cấu trúc sockaddr để lưu trữ thông tin về client ((sockaddr*)&client)

    char host[NI_MAXHOST]; //client's remote name
    char service[NI_MAXSERV]; // service (i.e. port) the client is connect on

    ZeroMemory(host, NI_MAXHOST); // same as memset(host, 0 , NI_MAXHOST);
    ZeroMemory(service, NI_MAXHOST);

    if(getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        cout << host << " connected on port " << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << 
            ntohs(client.sin_port) << endl;
    }
    // Close listening socket
    closesocket(listening);

    // While loop: accept and echo message back to client
    char buf[4096];

    while(true) {
        ZeroMemory(buf, 4096);

        //wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if(bytesReceived == SOCKET_ERROR) {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }
        if(bytesReceived == 0) {
            cout << "Client disconnected " << endl;
            break;
        }
        //Echo message back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
    }
    // Close the sock
    closesocket(clientSocket);

    // Shutdown winsock
    WSACleanup();
}