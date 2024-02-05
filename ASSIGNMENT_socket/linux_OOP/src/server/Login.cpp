#include "./server.h"

std::string Login(
    const Database<User> &db,
    const string &uname,
    const string &pass,
)
{
    auto record = db.get(uname).first;
    auto user = record.get();

    // register user if not exists and login
    if(user["status"] == "undefined") {
        db.add(User({uname, pass, "1"}));
        cout << color::green << "[CLIENT:REGISTER] " << color::reset
             << "<" << uname << "> registered" << endl;
        return "SUCCESS";
    }

    // check credentials and state
    if(user["password"] == pass) {
        if(user["status"] == "1")
            return "ALREADY LOGGED IN";
        db.update(record, User({uname, pass, "1"}));
        return "SUCCESS";
    }

    return "FAILED!";
}