#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
public:
    // type, money, and type of transaction
    std::string type;
    double amount;
    std::string description;

    // calls functinon from transaction.cpp
    Transaction(std::string type, double amount, std::string desc);
    void displayTransaction();
};

#endif
