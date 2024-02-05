
#include "./server.h"
#include <string.h>

std::string GetPeopleList(
    const std::string &chatRoomName,
    const FdToName &names,
    const ChatRoomToFdList &chatRooms,
)
{
    FdList peopleInRoom = chatRooms.at(chatRoomName);
    std::string response;
    for(auto fd : peopleInRoom) {
        if(names.count(fd) != 0 && !names.at(fd).empty()) {
            response += "\n" + names.at(fd) + " <" + getPeerName(fd) + ">";
        }
    }
    return response;
}