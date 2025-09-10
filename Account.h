#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include <memory>
#include "Transaction.h"

class Account
{
protected:
    // account num stored in str
    std::string accountNumber;
    // account name stored in str
    std::string ownerName;
    // balance stored in double
    double balance;
    // transactions stored as vector
    std::vector<Transaction> transactions;

public:
    // parameters of account
    Account(std::string num, std::string name, double bal);
    // 
    virtual void displayAccount() = 0;
    virtual void accountMenu() = 0;
    void recordTransaction(const std::string &type, double amount, const std::string &description);
    void showTransactions();
};

class CheckingAccount : public Account
{
public:
    // checking account parameters
    CheckingAccount(std::string num, std::string name, double bal);
    void displayAccount() override;
    void accountMenu() override;
};

class CreditCardAccount : public Account
{
    // credit limit stored in double
    double creditLimit;

public:
    // credit card account parameters
    CreditCardAccount(std::string num, std::string name, double bal, double limit);
    void displayAccount() override;
    void accountMenu() override;
};

class MortgageAccount : public Account
{
    // rate stored in double
    double interestRate;
    // years stred in integer
    int termYears;

public:
    // mortgage account parameters
    MortgageAccount(std::string num, std::string name, double bal, double rate, int term);
    void displayAccount() override;
    void accountMenu() override;
    void displayAmortizationSchedule();
};

#endif
