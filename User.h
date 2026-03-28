#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string hashPassword(std::string password);
    bool userExists(std::string username);

public:
    void registerUser();
    bool loginUser(std::string& loggedInUser);
    bool adminLogin();
};

#endif
