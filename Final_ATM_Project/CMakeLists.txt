cmake_minimum_required(VERSION 3.10)
project(Final_ATM_Project)


set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(inc)
find_package(OpenSSL REQUIRED)

# Add source files
add_executable(atm_program
    src/Account.cpp
    src/Atm.cpp
    src/CentralBank.cpp
    src/main.cpp
    src/Utilities.cpp
    src/Transactions.cpp
)

# Link OpenSSL
target_link_libraries(atm_program PRIVATE OpenSSL::Crypto)
