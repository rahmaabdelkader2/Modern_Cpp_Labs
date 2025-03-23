#include "Account.hpp"

// Constructor
Account::Account(std::string accNumber, std::string accName, std::string accType, double balance, const std::string& pin)
    : accNumber(accNumber), accName(accName), accType(accType), balance(balance), hashedPin(hashPIN(pin)), failedAttempts(0), isLocked(false) {}

// Getters
std::string Account::getAccNumber() const { return accNumber; }
std::string Account::getAccName() const { return accName; }
std::string Account::getAccType() const { return accType; }
double Account::getBalance() const { return balance; }
std::string Account::getHashedPin() const { return hashedPin; }
bool Account::getIsLocked() const { return isLocked; }
int Account::getFailedAttempts() const { return failedAttempts; }

// Setters
void Account::setAccNumber(std::string accNumber) { this->accNumber = accNumber; }
void Account::setAccName(std::string accName) { this->accName = accName; }
void Account::setAccType(std::string accType) { this->accType = accType; }
void Account::setBalance(double balance) { this->balance = balance; }
void Account::setPin(const std::string& pin) { hashedPin = hashPIN(pin); }

// Deposit money into the account
bool Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::string timeStamp = getCurrentTime();
        transactions.emplace_back("Deposit", amount, timeStamp, "Success");

        std::cout << "The deposit process is done successfully.\n";
        FilesLogger::logTransaction("Success", "Deposit", accNumber, timeStamp);
        return true;
    }

    std::cout << "Invalid deposit amount.\n";
    FilesLogger::logTransaction("Failed", "Deposit", accNumber, getCurrentTime());
    return false;
}

// Withdraw money from the account
bool Account::withdraw(double amount) {
    std::string timeStamp = getCurrentTime();

    if (amount <= 0) {
        std::cout << "Invalid amount.\n";
        FilesLogger::logTransaction("Failed", "Withdraw", accNumber, timeStamp);
        return false;
    }

    if (balance >= amount) {
        balance -= amount;
        transactions.emplace_back("Withdraw", amount, timeStamp, "Success");

        std::cout << "The withdraw process is done successfully.\n";
        FilesLogger::logTransaction("Success", "Withdraw", accNumber, timeStamp);
        return true;
    }

    std::cout << "Insufficient balance.\n";
    FilesLogger::logTransaction("Failed", "Withdraw", accNumber, timeStamp);
    return false;
}

// Authentication
bool Account::authenticate(const std::string& inputAccountNumber, const std::string& pin) {
    if (isLocked) {
        std::cout << "Account is locked. Please contact the bank.\n";
        return false;
    }

    // Check if the provided account number matches
    if (inputAccountNumber != accNumber) {
        std::cout << "Invalid account number.\n";
        return false;
    }

    if (hashPIN(pin) == hashedPin) {
        failedAttempts = 0; // Reset failed attempts on successful authentication
        std::cout << "Authentication successful!\n";
        return true;
    } else {
        failedAttempts++; // Increment failed attempts
        //std::cout << "Authentication failed. Attempts remaining: " << (3 - failedAttempts) << "\n";

        if (failedAttempts >= 3) {
            isLocked = true; // Lock the account after 3 failed attempts
            std::cout << "Account locked due to too many failed attempts. Please contact the bank.\n";
        }
        return false;
    }
}

// Show transaction history
void Account::showTransactionsHistory() const {
    if (transactions.empty()) {
        std::cout << "No transactions available.\n";
        return;
    }

    for (const auto& transaction : transactions) {
        std::cout << "Type: " << transaction.getType() << "\n";
        std::cout << "Amount: " << transaction.getAmount() << "\n";
        std::cout << "Time: " << transaction.getTimeStamp() << "\n";
        std::cout << "------------------------\n";
    }
}

// Show balance
void Account::showBalance() const {
    std::cout << "Balance: " << balance << std::endl;
}