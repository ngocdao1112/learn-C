#include "socketuntil.h"

int createTCPIpv4Socket() { return socket(AF_INET, SOCK_STREAM, 0); }

struct sockaddr_in* createIPv4Address(char *ip, int port) {
    // char* ip = "172.253.122.139";
    struct sockaddr_in *address = malloc(sizeof(struct sockaddr_in));
    address->sin_family = AF_INET; //Socket INterface FAMILY
    address->sin_port = htons(port);
    inet_pton(AF_INET, ip, &address->sin_addr.s_addr);//Internet Presentation to Numeric ("235.3.42.1" -> binary)
                                                    // sin_add - Socket INternet ADDRess - chứa đ.chỉ IP client/server ở dạng text(chuỗi ký tự) 
                                                    // s_add - chứa địa chỉ IP ở dạng binary 
    return address;
}