#ifndef ATM_HPP
#define ATM_HPP

#include "CentralBank.hpp"

class ATM : public CentralBank {
public:
    // Constructor
    ATM(std::string bankName, std::string bankCode, double interestRate);

    // Authenticate a user
    std::shared_ptr<Account> authenticate(std::string_view accountNumber, const std::string& pin) const;
};

#endif  // ATM_HPP