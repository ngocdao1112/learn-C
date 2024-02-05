#include "./server.h"

using namespace std;
using namespace cmd;

cmd::Commands GetMessageType(const string &msg) {
    if(msg.find(DELIM) != 0)
        return NOT_CMD;
    string cmd(msg.substr(DELIM.size()));
    if (cmd.find("JOIN") == 0)
        return JOIN;
    if (cmd.find("LEAVE") == 0)
        return LEAVE;
    if (cmd.find("LIST_CHATROOMS") == 0)
        return LIST_CHATROOMS;
    if (cmd.find("LIST_PEOPLE") == 0)
        return LIST_PEOPLE;
    
    return INVALID;
}