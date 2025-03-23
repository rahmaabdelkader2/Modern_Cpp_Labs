#ifndef CENTRALBANK_HPP
#define CENTRALBANK_HPP

#include <vector>
#include <string>
#include <memory>
#include "Account.hpp"

class CentralBank {
protected:
    std::string bankName;
    std::string bankCode;
    double interestRate;
    std::vector<std::shared_ptr<Account>> accounts;

public:
    // Constructor
    CentralBank(std::string bankName, std::string bankCode, double interestRate);

    // Add a bank account
    void addBankAccount(std::string accNumber, std::string accName, std::string accType, const std::string& pin, double balance);

    // Remove a bank account
    void removeBankAccount(std::string accNumber);

    // Apply interest to all accounts
    void applyInterest();

    // Get total funds in the bank
    double getTotalFunds() const;

    // Get all accounts
    const std::vector<std::shared_ptr<Account>>& getAccounts() const;
};

#endif  // CENTRALBANK_HPP