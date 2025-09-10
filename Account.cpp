#include "Account.h"
#include <iostream>
#include <cmath>

// Base class Account
Account::Account(std::string num, std::string name, double bal)
    : accountNumber(num), ownerName(name), balance(bal) {}

// function that records transactions of user in given account
void Account::recordTransaction(const std::string& type, double amount, const std::string& description) {
    transactions.emplace_back(type, amount, description);
}

// displays transaction history
void Account::showTransactions() {
    for (auto& transaction : transactions) {
        transaction.displayTransaction();
    }
}

// CheckingAccount methods
CheckingAccount::CheckingAccount(std::string num, std::string name, double bal)
    : Account(num, name, bal) {}

// display checking account information
void CheckingAccount::displayAccount() {
    std::cout << "Checking Account: " << ownerName << " - Balance: $" << balance << "\n";
}

// user menu choices for checking account
void CheckingAccount::accountMenu() {
    int choice;
    do {
        // user choices for checking account
        std::cout << "\nChecking Account Menu:\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Show Balance\n";
        std::cout << "4. Show Transactions\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // deposits user-selected amount into account
                double amount;
                std::cout << "Enter amount to deposit: $";
                std::cin >> amount;
                balance += amount;
                recordTransaction("Deposit", amount, "Deposit into account");
                std::cout << "Deposited $" << amount << "\n";
                break;
            }
            case 2: {
                // withdraws user-selected amount into account
                double amount;
                std::cout << "Enter amount to withdraw: $";
                std::cin >> amount;
                // if amount is higher than balance
                if (amount > balance) {
                    std::cout << "Insufficient funds.\n";
                } else {
                    balance -= amount;
                    recordTransaction("Withdrawal", amount, "Withdrawal from account");
                    std::cout << "Withdrew $" << amount << "\n";
                }
                break;
            }
            case 3:
                // displays current ballance
                std::cout << "Current balance: $" << balance << "\n";
                break;
            case 4:
                // shows transactions
                showTransactions();
                break;
            case 5:
                // exit menu
                std::cout << "Exiting account menu.\n";
                break;
            default:
                // asks user for correct info
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}


// CreditCardAccount methods
CreditCardAccount::CreditCardAccount(std::string num, std::string name, double bal, double limit)
    : Account(num, name, bal), creditLimit(limit) {}

void CreditCardAccount::displayAccount() {
    std::cout << "Credit Card Account: " << ownerName << " - Balance: $" << balance << ", Limit: $" << creditLimit << "\n";
}

void CreditCardAccount::accountMenu() {
    int choice;
    do {
        // menu for credit account
        std::cout << "\nCredit Card Account Menu:\n";
        std::cout << "1. Pay Credit\n";
        std::cout << "2. Charge to Card\n";
        std::cout << "3. Increase Credit Limit\n";
        std::cout << "4. Show Transactions\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // pay credit charge
                double amount;
                std::cout << "Enter amount to pay: $";
                std::cin >> amount;
                balance -= amount;
                recordTransaction("Payment", amount, "Payment to credit card");
                std::cout << "Payment of $" << amount << " made.\n";
                break;
            }
            case 2: {
                // charge amount to card
                double amount;
                std::cout << "Enter amount to charge: $";
                std::cin >> amount;
                if (amount + balance > creditLimit) {
                    std::cout << "Credit limit exceeded.\n";
                } else {
                    balance += amount;
                    recordTransaction("Charge", amount, "Charge on credit card");
                    std::cout << "Charged $" << amount << " to the card.\n";
                }
                break;
            }
            case 3: {
                // increase credit limit
                double amount;
                std::cout << "Enter new credit limit: $";
                std::cin >> amount;
                creditLimit = amount;
                std::cout << "Credit limit increased to $" << creditLimit << "\n";
                break;
            }
            case 4:
                // display transaction history
                showTransactions();
                break;
            case 5:
                // exit menu
                std::cout << "Exiting account menu.\n";
                break;
            default:
                // asks user for correct info
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}


// MortgageAccount methods
MortgageAccount::MortgageAccount(std::string num, std::string name, double bal, double rate, int term)
    : Account(num, name, bal), interestRate(rate), termYears(term) {}

void MortgageAccount::displayAccount() {
    std::cout << "Mortgage Account: " << ownerName << " - Loan Amount: $" << balance << ", Rate: " << interestRate << "%, Term: " << termYears << " years\n";
}

void MortgageAccount::accountMenu() {
    int choice;
    do {
        // menu for mortgage account
        std::cout << "\nMortgage Account Menu:\n";
        std::cout << "1. Make Payment\n";
        std::cout << "2. Display Amortization Schedule\n";
        std::cout << "3. Show Balance\n";
        std::cout << "4. Show Transactions\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double payment;
                std::cout << "Enter payment amount: $";
                std::cin >> payment;
                balance -= payment;
                recordTransaction("Payment", payment, "Mortgage payment");
                std::cout << "Payment of $" << payment << " made.\n";
                break;
            }
            case 2:
                displayAmortizationSchedule();
                break;
            case 3:
                std::cout << "Current balance: $" << balance << "\n";
                break;
            case 4:
                // display transaction history
                showTransactions();
                break;
            case 5:
                // exirs menu
                std::cout << "Exiting account menu.\n";
                break;
            default:
                // asks user for correct info
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void MortgageAccount::displayAmortizationSchedule() {
    // calculate interest rate
    double monthlyRate = interestRate / 100 / 12;
    // 12 months in 1 year
    int totalPayments = termYears * 12;
    // calculate monthy payment
    double monthlyPayment = balance * (monthlyRate * pow(1 + monthlyRate, totalPayments)) /
                            (pow(1 + monthlyRate, totalPayments) - 1);

    // display amortization schedule
    std::cout << "\nAmortization Schedule:\n";
    std::cout << "Month | Payment | Interest | Principal | Remaining Balance\n";
    double currentBalance = balance;
    for (int i = 1; i <= totalPayments; ++i) {
        double interest = monthlyRate * currentBalance;
        double principal = monthlyPayment - interest;
        currentBalance -= principal;
        std::cout << i << " | $" << monthlyPayment << " | $" << interest << " | $" << principal << " | $" << currentBalance << "\n";
    }
}

