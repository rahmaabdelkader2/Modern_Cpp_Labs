#include "Transactions.hpp"

// Constructor implementation
Transactions::Transactions(std::string type, double amount, std::string timeStamp, std::string status)
    : type(type), amount(amount), timeStamp(timeStamp), status(status) {
 
}

// Getter implementations
std::string Transactions::getType() const {
    return type;
}

double Transactions::getAmount() const {
    return amount;
}

std::string Transactions::getTimeStamp() const {
    return timeStamp;
}

std::string Transactions::getStatus() const {
    return status;
}