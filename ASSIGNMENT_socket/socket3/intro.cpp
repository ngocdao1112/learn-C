/* https://www.youtube.com/watch?v=gntyAFoZp-E
Winsock:
    - developed for Unix
    - Window sockets API (WSA)
    - ws2_32.dll (C:\WINDOWNS\System32) - dll - dynamic link libary
OSI 7 Layers:
    - Session -> socket :  setup, authentication, termination, and reconnections
    - Transport: segment -> TCP, datagram -> UDP

-> Server is continually waiting for incoming connections. This is called listening

IP address:
    - The IP address of both server and client is configured during Network setup unless it is allocated dynamically.
    - Port number of the 'server' is usually within the code, whereas the client port number is allocated by the O/S.
    - Loopback address 127.0.0.1 refers to the current machine
Port:
    - Ports 1..1023 are described as well know ports and are reserved for specific applications (port 21 FTP).
    - It is recommended to choose a number over 1024
Sockets:
    - There are common types for a socket
        + Streaming socket (SOCK_STREAM) TCP
        + Datagram socket (SOCK_DGRAM) UDP
    - Create a socket:
        + Server create a new socket. When created it is 'yet' to be bound to an IP or port number -> Unboud
        + Binding server to a valid IP address & port number
        + Listening: after socket is bound, it is put into listening state (is waiting incoming connection)
Client:
    - unbound -> bound -> connected with server (create new socket)
    - While communicate, it is keep listening for other connections.
Server Functions:
    1. Initialize WSA - WSAStarup().
    2. Create a socket - socket().
    3. Bind the socket - bind()
    4. Listen on the socket - listen()
    5. Accept a connection - accept(), connect()
    6. Send and receive data - recv(), send(), recvfrom(), sendto()
    7. Disconnect - closesocket()

Client Functions:
    1. Initialize WSA - WSAStarup()
    2. Create a socket - socket()
    3. Connect to the server - connect()
    4. Send and receive data - recv(), send(), recvfrom(), sendto()
    5. Disconnect - closesocket()

The Server Code:
    - The Server must load the DLL by invoking WSAStartup (call DLL)
    - It then creates a socket specifying the protocol to be used (TCP/ UDP)
    - It binds the server's IP address to the socket (bind)
    - Then listens for clients trying to establish connections (listen)
    - On a client connecting the server creates a new socket to handle the client server communication (new socket)
The Client Code:
    - The Client must load the DLL by invoking WSAStartup (call DLL)
    - It then creates a socket
    - It then connects to the server by assigning the servers IP address & port to a sockaddr structure and passing this along with
        the client socket to the connet function
SERVER FUNCTIONS
STEP 1: 
Initialize DLL:
    - int WSAStartup( WORD wVersionRequested, LPWSADATA IpWSAData); // WORD -> 16-bit
        + wVersionRequested -> lastest version
        + LPWSADATA: pointer to the LPWSADATA data structure that is to receive details of the window sockets implementation
            + WSADATA structure contains infor about the Windows Sockets implementation
                typedef struct WSAData {
                    WORD wVersion;
                    WORD wHigh Version;
                    char szDescription [WSADESCRIPTION_LEN+1];
                    char szSystemStatus [WSASYS_STATUS_LEN+1];
                    unsigned short iMaxSockets;
                    unsigned short iMaxUdpDg;
                    char FAR *IpVendorInfo; }
            + WSAStartup function return a pointer to the WSADATA structure in the IpWSAData param

        + if successful, the WSAStartup will return 0
        + Example:
            WSADATA wsaData;
            int wsaerr;
            WORD wVersionRequested = MAKEWORD(2, 2);
            wsaerr = WSAStartup(wVersionRequested, &wsaData); if (wsaerr != 0) {
                cout << "The Winsock dll not found!" << endl; return 0;
            }
            else {
                cout << "The Winsock dll found!" << endl;
            }
            cout << "The status: " << wsaData.szSystemStatus << endl;
STEP 2: CREATE SOCKET
-> SOCKET WSAAPI socket(int af, int type, int protocol);

Deregister Winsock2 DLL:
    - int WSACleanup(void);
    - Example:
        SOCKET serverSocket = INVALID_SOCKET;
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(serverSocket == INVALID_SOCKET) {
            cout << "Error at socket(): " << WSAGetLastError() << endl;
            WSACleanup();
            return 0;
        }
        else {
            cout << "socket() is OK!" << endl;
        }
        //...
        WSACleanup();

Close socket:
    - int closesocket(Socket s);
    - Example:
        SOCKET serverSocket;
        serverSocket = INVALID_SOCKET;
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        //Process socket
        closesocket(serverSocket);

STEP 3: BIND SOCKET
-> int bind(SOCKET s, const struct sockaddr* name, int socklen);
-> struct sockaddr_in { short sin_family;   // AF_INET
                        unsigned short sin_port;
                        struct in_addr sin_addr;
                        char sin_zero[8];
                        }
    - Example:
        sockaddr_in service;
        service.sin_family = AF_INET;
        InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
        service.sin_port = htons(port);     //host to network short
        if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
            cout << "bind() failed: " << WSAGetLastError() << endl;
            closesocket(serverSocket);
            WSACleanup();
            return 0;
        }
        else {
            cout << "bind() is OK!" << endl;
        }

STEP 4: LISTEN
-> int listen(SOCKET s, int backlog);
    - s: Descriptor identifying a bound, unconnected socket.
    - backlog: The maximum number of connections allowed (also OS dependant).
    - Example:
        if(listen(serverSocket, 1) == SOCKET_ERROR)
            cout << "listen(): Error listening on socket" << WSAGetLastError() << endl;
        else
            cout << "listen() is OK, I'm waiting for connections..." << endl;

STEP 5:
    - This is blocking function
        SOCKET accept(SOCKET s, struct sockaddr* addr, int* addrlen);
            - s: Descriptor that identifies a socket that has been placed in a listening state with the listen() function.
            - addr: Optional structure containing the client address information
            - Addrlen: Optional size of the address structure (if included).
            - If no error occurs, accept() returns a value of type SOCKET that is a descriptor for the new socket that is connected to the client. 
                The original listening socket can be used to listen for more incoming calls.
            - Example:
                SOCKET acceptSocket;
                acceptSocket = accept(serverSocket, NULL, NULL);
                if(acceptSocket == INVALID_SOCKET) {
                    cout << "accept failed: " << WSAGetLastError() << endl;
                            WSACleanup();
                            return -1;
                }

CLIENT FUNCTIONS
STEP 3: Connect
-> int connect (SOCKET s, const struct sockaddr* addr, socklen_t addrlen);
    - s: Descriptor that identifies a socket.
    - addr: Structure containing server IP address and port.
    - addrlen: Size in bytes of addr structure
    - Connect will wait 75 seconds for server to respond.
    - Returns O if successful or SOCKET_ERROR if not.
    - Example:
        sockaddr_in clientService;
        clientService.sin_family = AF_INET;
        InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
        clientService.sin_port = htons(port);
        if(connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
            cout << "Client: connect() - Failed to connect." << endl;
            WSACleanup();
            return 0;
        }
        else {
            cout << "Client: connect() is OK." << endl;
            cout << "Client: Can start sending and receiving data..." << endl;
        }



*/