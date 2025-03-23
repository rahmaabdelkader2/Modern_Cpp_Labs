#include "Utilities.hpp"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <openssl/sha.h> // For SHA-256 hashing

// Function to get the current time in a formatted string
std::string getCurrentTime() {
    std::ostringstream oss;
    std::time_t now = std::time(nullptr); // Get current system time
    oss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S"); // Format: YYYY-MM-DD HH:MM:SS
    return oss.str();
}

// Function to hash the PIN using SHA-256
std::string hashPIN(const std::string& pin) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    // Initialize SHA-256 context
    if (!SHA256_Init(&sha256)) {
        throw std::runtime_error("Failed to initialize SHA-256 context.");
    }

    // Add the PIN data to the context
    if (!SHA256_Update(&sha256, pin.c_str(), pin.size())) {
        throw std::runtime_error("Failed to update SHA-256 context.");
    }

    // Finalize the hash and store it in the buffer
    if (!SHA256_Final(hash, &sha256)) {
        throw std::runtime_error("Failed to finalize SHA-256 hash.");
    }

    // Convert the binary hash to a hexadecimal string
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}