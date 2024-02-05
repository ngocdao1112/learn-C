#include <winsock.h>
#include "database.h"
#include "./server.h"
#include "Accept.cpp"
#include "GetPeerName.cpp"
#include "HandleLostConnection.cpp"
#include "GetMessageType.cpp"
#include "HandleMsg.cpp"
#include "JoinChatRoom.cpp"
#include "LeaveChatRoom.cpp"
#include "GetChatRoomsList.cpp"
#include "GetPeopleList.cpp"

int ServerChat(int sockfd) {
    Database<User> db("./data/users/", "name");
    int maxfd = sockfd;
    char buffer[BUFFER_SIZE];
    FdToName clients;
    ChatRoomToFdList chatRooms;
    fd_set master;

    while(true) {
        FD_ZERO(&master);
        FD_SET(sockfd, &master);
        for(auto &p : clients) {
            FD_SET(p.first, &master);
            if(p.first > maxfd) {
                maxfd = p.first;
            }
        }
        select(maxfd + 1, &master, NULL, NULL, NULL);

        if(FD_LIST(sockfd, &master)) {
            const int newClient = Accept(sockfd);
            if(newClient < 0) {
                cout << color::red << "[CONNECTION:ERROR] " << color::reset
                     << "can not Accept from newClient = " << newClient << endl;
                continue;
            }
            cout << color::yellow << "[CONNECTION:INFO] " << color::reset
                 << "New client joined from <" << getPeerName(newClient) << ">" << endl;
            FD_SET(newClient, &master);
            clients[newClient] = "";
            continue;
        }

        for(auto &p : clients) {
            const int currentClientFd = p.first;

            if(!FD_ISSET(currentClientFd, &master))
                continue;
            fill_n(buffer, BUFFER_SIZE, '\0');
            const int bytesRead = recv(currentClientFd, buffer, sizeof(buffer), 0);
            bool connectionLost = (bytesRead <=0);

            if(connectionLost) {
                HandleLostConnection(currentClientFd, chatRooms, clients, master, db);
                continue;
            }

            //process messages
            string msg(buffer);
            auto type = GetMessageType(msg);
            if(type == cmd::NOT_CMD) {
                HandleMsg(currentClientFd, chatRooms, clients, msg);
                continue;
            }

            switch(type) {
                case cmd::JOIN: {
                    auto chatRoomName = split(msg, DELIM, 2)[1];
                    cout << color::green << "[CLIENT:JOIN] " << color::reset
                         << "<" << clients[currentClientFd] << "> requested to join #"
                         << chatRoomName << endl;
                    JoinChatRoom(chatRoomName, currentClientFd, clients, chatRooms);
                    continue;
                }

                case cmd::LEAVE: {
                    auto chatRoomName = split(msg, DELIM, 2)[1];
                    cout << color::green << "CLIENT:LEAVE " << color::reset
                         << "<" << clients[currentClientFd] << "> left #"
                         << chatRoomName << endl;
                    LeaveChatRoom(chatRoomName, currentClientFd, clients, chatRooms);
                    continue;
                }

                case cmd::LIST_CHATROOMS: {
                    auto response = GetChatRoomsList(chatRooms);
                    send(currentClientFd, response.c_str(), response.size(), 0);
                    continue;
                }

                case cmd::LIST_PEOPLE: {
                    auto chatRoomName = split(msg, DELIM, 2)[1];
                    auto lst = GetPeopleList(chatRoomName, clients, chatRooms);
                    auto response = "INFO" + DELIM + "PEOPLE#"
                                    + chatRoomName + DELIM + lst;
                    send(currentClientFd, response.c_str(), response.size(), 0);
                    continue;
                }

                case cmd::INVALID:
                default: continue;
            }
        } // end:range-for-clients
    } // end:while

    return 0;
}