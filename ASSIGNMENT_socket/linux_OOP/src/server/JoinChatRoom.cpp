#include "./server.h"
#include <string.h>
#include <Broadcast.cpp"

void JoinChatRoom(const std::string chatRoomName, const int clientFd, FdToName &names, ChatRoomToFdList &chatRooms) {
    auto chatRoomItr = find_if(
        chatRooms.begin(),
        chatRooms.end(),
        [&chatRoomName](auto const &itr) -> bool {
            return itr.first == chatRoomName;
        }
    );

    bool exists = chatRoomItr != chatRooms.end();
    if(!exists) {
        chatRooms[chatRoomName] = FdList{clientFd};
    }
    else {
        chatRooms[chatRoomName].insert(clientFd);
    }

    std::string response = DELIM + "JOIN" + DELIM + chatRoomName;
    send(clientFd, response.c_str(), response.size(), 0);

    //Let members of chatroom know of new user
    if(exists) {
        std::string msg = "INFO" + DELIM + names[clientFd] + DELIM
                     + "joined" + chatRoomName;
        Broadcast(chatRooms.at(chatRoomName), clientFd, msg);
    }
}