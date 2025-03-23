#pragma once
#include <fstream>
#include <string>
#include "Transactions.hpp"

class FilesLogger {
public:
    static void logTransaction(const std::string& status, const std::string& type, const std::string& accNumber, const std::string& timeStamp) {
        std::ofstream logFile("transactions.log", std::ios::app);
        if (logFile.is_open()) {

            logFile << "Account:"<< accNumber << " | " <<"Trnsaction Types:"<< type << " | " <<"Transaction Status"<< status << " | " <<"Transaction Time"<< timeStamp << std::endl;
            logFile.close();
        }
    }
};