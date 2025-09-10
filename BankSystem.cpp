/*
 * This C++ program will simulate a bank website (such as Chase or Bank of America). This C++ program serves as our 
    final project for CECS 275. In this program, we will simulate an online banking website (such as Chase, Wells 
    Fargo, or Bank of America). This program is menu driven like lab 2 and uses object oriented programming. Our 
    program contains 3 accounts (checking, credit, and mortgage).
    
 * CECS 275 - Spring 2024 
 * @author Rod Agatep 
 * @author Matthew Margulies
 * @author Kenneth Tran
 * @version 1.2.5
 * Last updated 12:21 PM ~8:00 05/14/2024
 */

#include "Bank.h"

int main()
{
    Bank myBank;

    // Creating accounts and associating them with users

    // checking account                                                                             //amount
    myBank.addAccount("user1", "password1", std::make_shared<CheckingAccount>("123456", "John Doe", 1500.0));

    // credit card account                                                                           //amount, limit
    myBank.addAccount("user2", "password2", std::make_shared<CreditCardAccount>("654321", "Jane Doe", 500.0, 3000.0));

    // mortage account                                                                               //amount, interest, years
    myBank.addAccount("user3", "password3", std::make_shared<MortgageAccount>("112233", "Mary Smith", 200000.0, 3.5, 30));

    // Run the banking application
    myBank.run();

    return 0;
}
