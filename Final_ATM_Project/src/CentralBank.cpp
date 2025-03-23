#include "CentralBank.hpp"
#include <algorithm> // For std::remove_if

// Constructor
CentralBank::CentralBank(std::string bankName, std::string bankCode, double interestRate)
    : bankName(bankName), bankCode(bankCode), interestRate(interestRate) {}

// Add a bank account
void CentralBank::addBankAccount(std::string accNumber, std::string accName, std::string accType, const std::string& pin, double balance) {
    accounts.emplace_back(std::make_shared<Account>(accNumber, accName, accType, balance, pin));
}

// Remove a bank account
void CentralBank::removeBankAccount(std::string accNumber) {
    accounts.erase(std::remove_if(accounts.begin(), accounts.end(),
        [&](const std::shared_ptr<Account>& account) {
            return account->getAccNumber() == accNumber;
        }), accounts.end());
}

// Apply interest to all accounts
void CentralBank::applyInterest() {
    for (const auto& account : accounts) {
        double interest = account->getBalance() * (interestRate / 100);
        account->deposit(interest);
    }
}

// Get total funds in the bank
double CentralBank::getTotalFunds() const {
    double totalFunds = 0;
    for (const auto& account : accounts) {
        totalFunds += account->getBalance();
    }
    return totalFunds;
}

// Get all accounts
const std::vector<std::shared_ptr<Account>>& CentralBank::getAccounts() const {
    return accounts;
}