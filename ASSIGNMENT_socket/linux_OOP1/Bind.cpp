// #include <algorithm> //fill_n
#include <cstring> //sizeof, memset
#include <stdexcept> //runtime_error
#include <sys/types.h> //setsockopt
#include <sys/socket.h> //setsockopt, bind, 
#include <netinet/in.h> //AF_INET, SO_REUSEADDR
#include <unistd.h> //AF_INET, SO_REUSEADDR
#include "PrintError.cpp"


using namespace std;

//bind a 'sockfd' with 'address' and 'port'
void Bind(int sockfd, int port) {
    
    // Initialize server address structure
    struct sockaddr_in server_addr;

    // Note: 'reinterpret_cast' is used to convert the pointer from 'sockaddr_in' to a char* pointer to cast to 'fill_n'
    // 'fill_n' & 'memset': Sets the value for a continuous range of elements
    // fill_n(reinterpret_cast<char*>(&server_addr), sizeof server_addr, '\0');
    // memset(ptr, value, size of memory area) 
        // -> Set all bytes in the server_addr variable to 0 (null).
    memset(&server_addr, 0, sizeof(server_addr));
        // -> The server_addr variable does not contain any garbage values, especially if it is reused from previous uses
    
    const int reuse = 1;
    if(setsockopt(
        sockfd,
        SOL_SOCKET, // socket options level
        SO_REUSEADDR, // socket options allow reuse addr & port,
                    // even if it still has pending connections
        reinterpret_cast<const char*>(&reuse), //convert pointer from int* to const char*
        sizeof(reuse)) < 0) 
        {
            throw runtime_error("setsockopt(SO_REUSEADDR) failed");
        }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // 'res' saves the return value of the 'bind' function
    // check 'res' is 0 or -1
    /*int res = bind(sockfd,
                   reinterpret_cast<struct sockaddr*>(&server_addr),
                   sizeof server_addr);
    if(res < 0) {
        PrintError();
        throw runtime_error("Error in binding socket");
    }*/

    // Bind the socket
    if (bind(sockfd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)) < 0) {
        PrintError();
        throw runtime_error("Failed to bind socket");
    }
}