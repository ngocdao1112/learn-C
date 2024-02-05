#ifndef SRC_SERVER_SERVER_H_
#define SRC_SERVER_SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <iostream>
#include <stdexcept>
#include <cerrno>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include "../db/database.h"
#include "../db/user.h"

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;
using FdList = set<int>;
using FdToName = map<int, string>;
using ChatRoomToFdList = map<string, FdList>;

namespace cmd {
    enum Commands {
        NOT_CMD,
        INVALID,
        JOIN,
        LEAVE,
        LIST_CHATROOMS,
        LIST_PEOPLE
    };
}

namespace color {
    const string red("\033[0;31m");
    const string green("\033[1;32m");
    const string yellow("\033[1;33m");
    const string cyan("\033[0;36m");
    const string magenta("\033[0;35m");
    const string reset("\033[0m");
}

int Socket();
void Bind(int sockfd, int port);
void Listen(int sockfd, int backlog);
int Accept(int sockfd);

// Print the 'errno' codes
void PrintError();

// Login a user
string Login(const Database<User> &db, const string &uname, const string &pass);

// Logout a user
bool Logout(const Database<User> &db, const string &uname);

// Main chat function
int ServerChat(int sockfd);

// Add a client to chat system (with login)
bool AddClient(
    const int currentClientFd,
    fd_set *master,
    const Database<User> &db,
    FdToName &names
);

// Get the msg type - regular msg or some command
cmd::Commands GetMessageType(const std::string &);

// Response for '/list rooms'
std::string GetChatRoomsList(const ChatRoomToFdList &chatRooms);

// Response for '/list people'
std::string GetPeopleList(
    const std::string &chatRoomName,
    const FdToName &names,
    const ChatRoomToFdList &chatRooms
);

// Broadcast msg to all 'clients' except 'currentClientFd (sender)
void Broadcast(
    const FdList &clients,
    const int currentClientFd,
    const string &msg
);

// Handle private messages
void privateChat(
  const FdToName &clients,
  int currentClientFd,
  const string &msg,
  string clientName
);

// Add a user to a chatroom '/join #chatroom'
void JoinChatRoom(
    const std::string chatRoomName,
    const int clientFd,
    FdToName &clients,
    ChatRoomToFdList &chatRooms
);

// Remove a user from a chatroom './leave #chatroom'
void LeaveChatRoom(
    const std::string chatRoomName,
    const int clientFd,
    const FdToName &names,
    ChatRoomToFdList &chatRooms
);

/* Handle lost connection request
    - Remove connection from active connections
    - Notify chatroom mates.
*/
void HandleLostConnection(
    const int currentClientFd,
    ChatRoomToFdList &chatRooms,
    FdToName &clients,
    fd_set &master,
    Database<User> &db
);

// Hanlde incoming msg:
    // if private send it to the particular client else broadcast it to chatroom
void HandleMsg(
    const int currentClientFd,
    const ChatRoomToFdList &chatRooms,
    const FdToName &clients,
    string msg
);

// Get the 'ip:port' for a given client
std::string GetPeerName(const int sockfd);

const int BUFFER_SIZE = 1024;
const string DELIM("$$$");

vector<string> split(const string &str, const string &delim, const int limit);

#endif // SRC_SERVER_SERVER_H_