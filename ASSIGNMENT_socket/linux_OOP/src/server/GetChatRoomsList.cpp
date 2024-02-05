#include "./server.h"
#include <string.h>

std::string GetChatRoomsList(const ChatRoomToFdList &chatRooms) {
    std::string chatRoomsList = "INFO" + DELIM + "ROOMS" + DELIM + "\n";
    for(const auto &room : chatRooms) {
        chatRoomsList += "\n" + room.first + " <"
                         + std::to_string(room.second.size()) + ">";
    }
    return chatRoomsList;
}