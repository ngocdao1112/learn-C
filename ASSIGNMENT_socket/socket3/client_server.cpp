//https://www.youtube.com/watch?v=sXW_sNGvqcU&list=PL9HfA4ZKbzimKyvquT1MZ2x9d6UHjFNFA&index=13

/*
Sending Data:
    - SEND function sends data on a connected socket
        int send(SOCKET s,
                const char *buf,
                int len,
                int flags);
        + s: descriptor that identifies a connected socket
        + buf: a pointer to the buffer to the data to be transmitted
        + len: the length, in bytes, of the buffer pointed to by the 'buf' param
        + flags: optional set of flags that influences the behavior of this function(No routing etc)
        + if no error occurs, SEND returns the number of bytes sent.
            Otherwise SOCKET_ERROR is returned.
    - Example: we are using the socket variable named clientSocket but any valid
    socket connected socket on the server or client could be used.
        ...........
        char buffer[200];
        printf("Enter your message ");
        cin.getline(buffer, 200);
        int byteCount = send(clientSocket, buffer, 200, 0);
        if(byteCount == SOCKET_ERROR) {
            printf("Server send error %ld.\n", WSAGetLastError());
            return -1;
        }
        else {
            printf("Server: sent %ld bytes\n", byteCount);
        }
        .............
    - User Input:
        - Include <iostream> and using namspace std
        - Invoke cin.getline() to capture a series of characters (including spaces)
            entered into the console
        - Pass a valid char array and length of the array to getLine as arguments.
        ...........
            char buffer[200] = "";
            cout << "Enter the message ";
            cin.getline(buffer, 200);
            cout "You typed" << buffer << endl;
        ............
Receiving Data
    - The RECV function receives data from a connected socket
        ........................
        int recv(SOCKET s,
                char *buf,
                int len,
                int flags);
        .....................
        + if no error occurs, RECV returns the number of bytes received. if the connection has been
            gracefully closed, the return value is zero. Otherwise SOCKET_ERROR is returned.
    - Example: we are using the socket variable named acceptSocket but any valid socket connected socket on the server
        or client could be used.
        .......................
        char receiveBuffer[200] = "";
        int byteCount = recv(acceptSocket, receiveBuffer, 200, 0);
        if(byteCount < 0) {
            printf("Client: error%ld.\n", WSAGetLastError());
        }
        else {
            printf("Received data: %s \n", receiveBuffer);
        }
        ............................

Transmitting Objects:
    - Sending an object. Assuming the class Data has be defined elsewhere. Cast the objects address to a char*
        Data data;
        data.health = 100;
        byteCount = send(socket, (char*)&data, sizeof(Data), 0);
    - Receiving an object
        Data data;
        byteCount = recv(clientSocket, (char*)&data, sizeof(Data), 0);
        printf("Health: \"%d\"\n", data.health);
        Asigning Values to char array
    - When defining the char array we can initialise its value
        char sendBuffer[200] = "Message received by server";
    - We can't however use the assignment operator after it has been defined.
    - Instead we must use the strcpy function or if depreciated strcpy_s.
        char buffer[200];
        strcpy_s(buffer, "hello World");
    - Use the strlen function to return the number of char in the array
        strlen(sendBuffer);
Comparing char array
    - The strcmp() function compares two strings
        int strcmp(const char* string1, const char* string2);
    - Takes two string as arguments(pointers to char array)
    - Returns 0 if they are equal
    - Returns < 0 if string1 less than string2
    - Returns > 0 if string1 greater than string2
        if(strcmp(buffer, "PASSWORD") == 0) {
            //string are equal
        }
UDP:
    - Reduces the lag associated with TCP
    - Used in Multiplayer games where transmitted data is not critical
UDP setup:
    - Initialise the library as with TCP
    - Create a socket configured for UDP
    - For a server only bind the socket to an address
    - Invoke SENDTO to transmit data
    - Invoke RECVFROM to receive data
    - Note: There is no notion of a fixed connection between client & server and hence the server doesn't 
        utilise the accept function nor the client the connect function
UDP socket:
    - Invoke the socket function as with a TCP socket
        SOCKET WSAAPI socket(int af,
                            int type,
                            int protocol);
    - The addr family specification is AF_INET as with TCP
    - The type specification for UDP is SOCK_DGRAM
    - The protocol to be used IPPROTO_UDP
        socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
Sending data:
    - The SENDTO function sends data to a specific destination
        int sendto(SOCKET s, const char *buf, int len, int flags,
                    const struct sockadd *to, int tolen);
        + s: a descriptor indentifying a (possibly connected) socket.
        + buf: a pointer to the data to be transmitted
        + len: size in bytes, of the data pointed to by buf param
        + flags: flags that specify the way in which the call is made
        + to: an optional pointer to a sockaddr_in structure that contains the address of the target socket
        + tolen: the size, in bytes, of the address pointed to by the TO param
        + if no error occurs, SENDTO returns the total number of bytes sent else -1
UDP send example:
    .........................
    sockaddr_in address;
    address.sin_family = AF_INET;
    InetPton(AF_INET, _T("127.0.0.1"), &address.sin_addr.s_addr);
    address.sin_port = htons(5555);
    .........................
    char buffer[200] = "send this to server";
    int bytesSent = sendto(socket, (const char*)buffer, strlen(buffer), 0,
                        (struct sockaddr*)&address, sizeof(address));
    if(bytesSent == -1) {
        cout << "Error transmitting data. " << endl;
        WSACleanup();
        return 0;
    }
    else
        cout << "Data sent: " << buffer << endl;
Receiving  Data:
    - The recvfrom function receives a datagram and stores the source address. This is a blocking function.
        int recvfrom( SOCKET s, char *buf, int len, int flags, 
                    struct sockaddr *from, int *fromlen);
        + s: A descriptor identifying a bound socket.
        + buf: A buffer for the incoming data.
        + len: Size in bytes, of the buffer pointed to by the buf parameter.
        + flags: Flags that modify the behavior of the function.
        + from: An optional pointer to a buffer in a sockaddr_in structure that will hold the source address upon return.
        + fromlen: The size, in bytes, of the address pointed to by the from parameter.
        + If no error occurs, recvfrom returns the number of bytes received else -1
    
UDP receive Example:
        ....................
        char buffer[200] = "";
        sockaddr_in clientAddress;
        int clientAddress_length = (int)sizeof(clientAddress);
        int bytes_received = recvfrom(socket, buffer, 200, 0, (struct sockaddr *)&clientAddress, &clientAddress_length);
        if (bytes_received < 0){
            cout << "Could not receive datagram." << endl;
            WSACleanup();
            return 0;
        }
        .........................
Vector3D:
    - A class representing a 3D vector with x,y & z member variables. 
    - x,y & z are public and can therefore be manipulated directly.
        ....................
        class Vector3D {
            public:
            float x, y, z;
            Vector3D(float X, float Y, float Z): x(X), y(Y), z(Z) {}
        };
        Vector3D point(0.0, 0.0, 0.0);
        //point.x = 10;
        //point.y = 4.0;
        //point.z = 9.0;
        ....................
Converting lo char array:
    - Primitive data types should be converted to char array before being transmitted.
    - The sprintf() performs this task.
        sprintf(char* buffer, const char * format, list of arguments);
    - The % character in the format string is a placeholder 6.1 indicates the size and decimal places and the f that a float will be passed to it.
        Vector3D position (1.0, 2.0, 3.0);
        char positionBuffer[200] = "";
        sprintf(positionBuffer, "%6.1f %6.1f %6.1f", position.x, position.y, position.z);
*/