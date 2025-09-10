#include "Transaction.h"

// set up the parameters of displaying the transaction history
Transaction::Transaction(std::string type, double amount, std::string desc)
    : type(type), amount(amount), description(desc) {}

// function that displays the transactions
void Transaction::displayTransaction() {
    std::cout << type << ": $" << amount << " - " << description << "\n";
}
