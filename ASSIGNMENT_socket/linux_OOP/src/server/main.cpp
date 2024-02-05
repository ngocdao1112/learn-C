/*  Server for chat application
    Usage:
    $ ./server [PORT=8000] [BACKLOG=5]
*/

#include "./server.h"

// argument count & argument vector
int main(int argc, char *argv[]) {

    // atoi -> ASCII to Integer
    const int port = (argc > 1) ? atoi(argv[1] : 8000);
    const int backlog = (argc > 2) ? atoi(argv[2] : 5);

    // sockfd -> file descriptor
    const int sockfd = CreateSocket();

    // (bind) a created socket to a specific address and port.
    Bind(sockfd, port);

    Listen(sockfd, backlog);

    ServerChat(sockfd);

    close(sockfd);

    return 0;
}

