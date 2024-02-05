#include "./server.h"

int Accept(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t len = static_cast<socklen_t>(sizeof(client_addr));
    const int clientSockfd = accept(sockfd,
                                    reinterpret_cast<struct sockaddr*>(&client_addr),
                                    &len);
    return clientSockfd;
}
