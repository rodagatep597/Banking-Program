#ifndef BANK_H
#define BANK_H

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Account.h"

class Bank {
private:
    std::map<std::string, std::vector<std::shared_ptr<Account>>> userAccounts;
    std::map<std::string, std::string> userCredentials;  // Username to password mapping

public:
    Bank();
    // add user to database
    void addUser(const std::string& username, const std::string& password);
    void addAccount(const std::string& username, const std::string& password, std::shared_ptr<Account> acc);

    // displays the 3 accounts
    void displayAccounts(const std::string& username);

    // user login 
    bool login();

    // runs program
    void run();
};

#endif
