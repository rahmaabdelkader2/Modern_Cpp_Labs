#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>

// Function to get the current time in a formatted string
std::string getCurrentTime();

// Function to hash the PIN using SHA-256
std::string hashPIN(const std::string& pin);

#endif  // UTILITIES_HPP