#ifndef TRANSACTIONS_HPP
#define TRANSACTIONS_HPP

#include <string>

class Transactions {
private:
    std::string type;
    double amount;
    std::string timeStamp;
    std::string status;

public:
    // Constructor with validation
    Transactions(std::string type, double amount, std::string timeStamp, std::string status);

    // Getters
    std::string getType() const;
    double getAmount() const;
    std::string getTimeStamp() const;
    std::string getStatus() const;
};

#endif  // TRANSACTIONS_HPP