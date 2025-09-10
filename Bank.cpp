#include "Bank.h"
#include "Account.h"
#include <iostream>

Bank::Bank() {}

// function to add user(s) to system
void Bank::addUser(const std::string &username, const std::string &password)
{
    // Only add the user if they don't already exist
    if (userCredentials.find(username) == userCredentials.end())
    {
        userCredentials[username] = password;
    }
    else
    {
        std::cout << "User already exists.\n";
    }
}

// function to add account to system
void Bank::addAccount(const std::string &username, const std::string &password, std::shared_ptr<Account> acc)
{
    if (userCredentials.find(username) == userCredentials.end())
    {
        addUser(username, password);
    }
    userAccounts[username].push_back(acc);
}

// displays accounts
void Bank::displayAccounts(const std::string &username)
{
    int i = 1;
    for (auto &acc : userAccounts[username])
    {
        std::cout << i++ << ". ";
        acc->displayAccount();
    }
}

bool Bank::login()
{
    // prompts user for login info
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // checks if username and password match system
    if (userCredentials.find(username) != userCredentials.end() && userCredentials[username] == password)
    {
        // if info is correct
        std::cout << "Login successful!\n";
        int accountChoice;
        do
        {
            displayAccounts(username);
            std::cout << userAccounts[username].size() + 1 << ". Logout\n";
            std::cin >> accountChoice;
            if (accountChoice > 0 && accountChoice <= userAccounts[username].size())
            {
                userAccounts[username][accountChoice - 1]->accountMenu();
            }
            if (accountChoice == userAccounts[username].size() + 1)
            {
                return false;
            }
        } while (accountChoice != userAccounts[username].size() + 1);
        return true;
    }
    else
    {
        // if incorrect login info is entered
        std::cout << "Login failed!\n";
        return false;
    }
}

// runs program
void Bank::run()
{
    while (!login())
    {
        // repeatedly asks user for correct info
        std::cout << "Please try logging in again.\n";
    }
}
