#include <iostream>
#include "Atm.hpp"
#include "Transactions.hpp"
#include "Utilities.hpp"
#include "FilesLogger.hpp"

int main() {
    // Test the hashPIN function
    std::string testPin = "1234";
    std::string hashedTestPin = hashPIN(testPin);
    std::cout << "Testing hashPIN function:\n";
    std::cout << "Original PIN: " << testPin << "\n";
    std::cout << "Hashed PIN: " << hashedTestPin << "\n";
    std::cout << "------------------------\n";

    ATM atmMachine("National Bank", "93221", 2.5);

    std::cout << "Adding accounts...\n";
    atmMachine.addBankAccount("123456", "rahma", "Savings", "123", 1000.0); 
    atmMachine.addBankAccount("654321", "abdelkader", "Checking", "321", 2000.0); 
    atmMachine.addBankAccount("111111", "mohmed", "Savings", "111", 3000.0);

    // Display all accounts
    std::cout << "\nAll Bank Accounts:\n";
    std::cout << "--------------------\n";
    std::cout << "Total Bank Funds: " << atmMachine.getTotalFunds() << "\n";

    // User authentication
    std::string accountNumber;
    std::string pin;
    int attempts = 3;

    while (true) {
        std::cout << "\nEnter your account number: ";
        std::cin >> accountNumber;

        // Check if the account exists
        bool accountFound = false;
        for (const auto& account : atmMachine.getAccounts()) {
            if (account->getAccNumber() == accountNumber) {
                accountFound = true;
                break;
            }
        }

        if (!accountFound) {
            std::cout << "Account not found! Please try again.\n";
            continue; 
        }

        while (attempts > 0) {
            std::cout << "Enter your PIN: ";
            std::cin >> pin;

            // Authenticate the user
            auto currentAccount = atmMachine.authenticate(accountNumber, pin); 
            if (currentAccount) {
                std::cout << "Login successful!\n";
                break; 
            } else {
                attempts--;
                if (attempts > 0) {
                    //std::cout << "Authentication Failed! Attempts remaining: " << attempts << "\n";
                } else {
                    std::cout << "Authentication failed! Exiting program.\n";
                    return 0; 
                }
            }
        }

        break; 
    }

    // At this point, the user has successfully authenticated
    auto currentAccount = atmMachine.authenticate(accountNumber, pin);
    if (!currentAccount) {
        std::cout << "Unexpected error. Exiting program.\n";
        return 0;
    }

    // Lambda function to perform actions (deposit, withdraw, balance, history)
    auto performAction = [&](std::string_view action, double amount = 0) {
        std::string status;
        std::string timeStamp = getCurrentTime();

        if (action == "deposit") {
            if (currentAccount->deposit(amount)) {
                status = "Success";
            } else {
                status = "Failed";
            }
        } else if (action == "withdraw") {
            if (currentAccount->withdraw(amount)) {
                status = "Success";
            } else {
                status = "Failed";
            }
        } else if (action == "balance") {
            std::cout << "Your balance is: " << currentAccount->getBalance() << std::endl;
            return;
        } else if (action == "history") {
            currentAccount->showTransactionsHistory();
            return;
        } else {
            std::cout << "Invalid action!\n";
            return;
        }

        // Log the transaction using FilesLogger
        FilesLogger::logTransaction(status, std::string(action), currentAccount->getAccNumber(), timeStamp);

        std::cout << "Transaction recorded: " << action << " - " << status << "\n";
    };

    std::string action;
    double amount;
    while (true) {
        std::cout << "\nChoose an action (deposit, withdraw, balance, history, exit): ";
        std::cin >> action;

        if (action == "exit") {
            std::cout << "Exiting program...\n";
            break;
        }

        if (action == "deposit" || action == "withdraw") {
            std::cout << "Enter amount: ";
            std::cin >> amount;
            performAction(action, amount);
        } else {
            performAction(action);
        }
    }

    std::cout << "\nApplying interest to all accounts...\n";
    atmMachine.applyInterest();

    std::cout << "\nRemoving account 654321...\n";
    atmMachine.removeBankAccount("654321");

    std::cout << "\nTotal bank funds after operations: " << atmMachine.getTotalFunds() << "\n";

    return 0;
}