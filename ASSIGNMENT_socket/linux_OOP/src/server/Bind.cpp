#include <cstring> //sizeof, memset
#include <stdexcept> //runtime_error
#include <sys/types.h> //setsockopt
#include <sys/socket.h> //setsockopt, bind, 
#include <netinet/in.h> //AF_INET, SO_REUSEADDR
#include <unistd.h> //AF_INET, SO_REUSEADDR
#include "PrintError.cpp"

using namespace std;

void Bind(int sockfd, int port) {

    // Initialize server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    // Set SO_REUSEADDR socket option
    const int enable_reuse = 1;
    if(setsockopt(
       sockfd, 
       SOL_SOCKET, 
       SO_REUSEADDR, 
    //    reinterpret_cast<const char*>(&reuse),
       &enable_reuse,
       sizeof(enable_reuse)) < 0) 
       {
            throw runtime_error("Failed to set SO_REUSEADDR socket option!");
       }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the socket
    if(bind(sockfd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)) < 0) {
        PrintError();
        throw runtime_error("Failed to bind socket");
    }
}