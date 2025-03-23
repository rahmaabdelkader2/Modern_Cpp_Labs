#include "Atm.hpp"

// Constructor
ATM::ATM(std::string bankName, std::string bankCode, double interestRate)
    : CentralBank(bankName, bankCode, interestRate) {}

// Authenticate a user
std::shared_ptr<Account> ATM::authenticate(std::string_view accountNumber, const std::string& pin) const {
    // Convert std::string_view to std::string for comparison
    std::string accNumberStr(accountNumber);

    for (const auto& accountIter : getAccounts()) {
        // Compare account numbers
        if (accountIter->getAccNumber() == accNumberStr) {
            if (accountIter->getIsLocked()) {
                std::cout << "Account is locked. Please contact the bank.\n";
                return nullptr;
            }

            // Authenticate using the provided PIN
            if (accountIter->authenticate(accNumberStr, pin)) {
                std::cout << "Authentication Successful!\n";
                FilesLogger::logTransaction("Success", "Authentication", accNumberStr, getCurrentTime());
                return accountIter;
            } else {
                std::cout << "Authentication Failed! Attempts remaining: " << (3 - accountIter->getFailedAttempts()) << "\n";
                FilesLogger::logTransaction("Failed", "Authentication", accNumberStr, getCurrentTime());
                return nullptr;
            }
        }
    }

    std::cout << "Account not found!\n";
    return nullptr;
}