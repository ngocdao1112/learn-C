/*
Group Chat Application | Multi Threaded + Multiple
https://www.youtube.com/watch?v=KEiur5aZnIM

*/
#include <stdio.h>
// #include <sys/socket.h>  // linux
#include <Ws2tcpip.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
#include <winsock2.h>
#include <string.h>
#include <malloc.h>
#include "socketuntil.h"

#pragma comment (lib, "ws2_32.lib")

// struct sockaddr_in* createIPv4Address(char *ip, int port); 
// int createTCPIpv4Socket();

// struct sockaddr_in* createIPv4Address(char *ip, int port) {
//     // char* ip = "172.253.122.139";
//     struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in));
//     address->sin_family = AF_INET; //Socket INterface FAMILY
//     address->sin_port = htons(port);
//     inet_pton(AF_INET, ip, &address->sin_addr.s_addr);//Internet Presentation to Numeric ("235.3.42.1" -> binary)
//                                                     // sin_add - Socket INternet ADDRess - chứa đ.chỉ IP client/server ở dạng text(chuỗi ký tự) 
//                                                     // s_add - chứa địa chỉ IP ở dạng binary 
//     return address;
// }

int main() {
    //để viết socket client ta cần gọi func socket
    //socket(domain, type, protocol);
    int socketFD = createTCPIpv4Socket();
    // int socketFD = socket(AF_INET, SOCK_STREAM, 0); // (IPv4, TCP, default for IPv4 & TCP)
    struct sockaddr_in *address = createIPv4Address("172.253.122.139", 80);

    int result = connect(socketFD, address, sizeof (*address));

    if(result == 0) {
        printf("connection was successful\n");
    }

    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google.com\r\n\r\n";
    send(socketFD, message, strlen(message), 0);
    char buffer[1024];
    recv(socketFD, buffer, 1024, 0);

    printf("Response was %s\n ", buffer);

    return 0;
}

