#include "./server.h"

int CreateSocket() {
    const int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // Check value of 'sockfd' < 0 (error message when creating socket)
    if(sockfd < 0) {
        throw std::runtime_error("Error opening socket!");
    }

    return sockfd;
}