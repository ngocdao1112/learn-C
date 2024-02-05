#include <iostream>
#include <errno.h> //errno
using namespace std;

void PrintError() {
    cout << "[ERROR]: ";
    switch (errno) { // 'errno' is global variable
    case EADDRINUSE:
        cout << "Address already in use!\n";
        break;
    case EBADF:
        cout << "Bad file descriptor invalid or closed before calling the function!\n";
        break;
    case EACCES:
        cout << "Permission denied!\n";
        break;
    default:
        cout << "Some unknow error!";
    }
}