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
*/