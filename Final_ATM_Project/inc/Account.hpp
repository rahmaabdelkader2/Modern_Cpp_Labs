#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Transactions.hpp"
#include "Utilities.hpp"
#include "FilesLogger.hpp"

class Account {
private:
    std::string accNumber;
    std::string accName;
    std::string accType;
    double balance;
    std::string hashedPin; // Store hashed PIN
    std::vector<Transactions> transactions;
    int failedAttempts; // Track failed PIN attempts
    bool isLocked; // Track whether the account is locked

public:
    // Constructor
    Account(std::string accNumber, std::string accName, std::string accType, double balance, const std::string& pin);

    // Getters
    std::string getAccNumber() const;
    std::string getAccName() const;
    std::string getAccType() const;
    double getBalance() const;
    std::string getHashedPin() const;
    bool getIsLocked() const;
    int getFailedAttempts() const;

    // Setters
    void setAccNumber(std::string accNumber);
    void setAccName(std::string accName);
    void setAccType(std::string accType);
    void setBalance(double balance);
    void setPin(const std::string& pin);

    // Deposit money into the account
    bool deposit(double amount);

    // Withdraw money from the account
    bool withdraw(double amount);

    // Authentication
    bool authenticate(const std::string& inputAccountNumber, const std::string& inputPin);

    // Show transaction history
    void showTransactionsHistory() const;

    // Show balance
    void showBalance() const;
};

#endif  // ACCOUNT_HPP