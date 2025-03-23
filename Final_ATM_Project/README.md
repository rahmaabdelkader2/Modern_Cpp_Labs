# **ATM and Central Bank System**

## **Project Description**

This project simulates an **ATM (Automated Teller Machine)** system integrated with a **Central Bank**. The system allows users to:
- Create and manage bank accounts.
- Authenticate users using their account number and PIN.
- Perform transactions such as deposits, withdrawals, and balance inquiries.
- View transaction history.
- Apply interest to all accounts.
- Remove accounts.
- Calculate and display the total funds across all accounts.

The project is implemented in **C++** and follows an object-oriented design. It uses classes to represent the main components of the system, such as `ATM`, `CentralBank`, `Account`, `Transactions`,`FilesLogger`and `Utilities`.

---

## **Class Hierarchy**

The project follows a **class hierarchy** where the `ATM` class inherits from the `CentralBank` class. This allows the `ATM` to reuse functionality from the `CentralBank`, such as managing accounts and applying interest.

---

## **Purpose of Each Class**

### **1. `CentralBank`**
- **Purpose**: Represents the central bank that manages all bank accounts.
- **Key Responsibilities**:
  - Store and manage a list of accounts (`std::vector<std::shared_ptr<Account>> accounts`).
  - Add new accounts (`addBankAccount`).
  - Remove accounts (`removeBankAccount`).
  - Apply interest to all accounts (`applyInterest`).
  - Calculate the total funds across all accounts (`getTotalFunds`).
- **Attributes**:
  - `bankName`: Name of the bank.
  - `bankCode`: Code of the bank.
  - `interestRate`: Interest rate applied to accounts.
  - `accounts`: List of accounts managed by the central bank.

---

### **2. `ATM` (Inherits from `CentralBank`)**
- **Purpose**: Represents the ATM machine that interacts with users and performs transactions.
- **Key Responsibilities**:
  - Authenticate users using their account number and PIN (`authenticate`).
  - Perform transactions (deposit, withdraw, check balance, view history).
  - Log transactions using the `FilesLogger` class.
- **Inherited Functionality**:
  - All functionality from `CentralBank` (e.g., managing accounts, applying interest).

---

### **3. `Account`**
- **Purpose**: Represents a bank account.
- **Key Responsibilities**:
  - Store account details (account number, account name, account type, balance, hashed PIN).
  - Perform transactions (deposit, withdraw).
  - Track transaction history (`std::vector<Transactions> transactions`).
  - Handle authentication (check if the provided PIN matches the stored hashed PIN).
- **Attributes**:
  - `accNumber`: Account number.
  - `accName`: Account holder's name.
  - `accType`: Type of account (e.g., Savings, Checking).
  - `balance`: Current balance.
  - `hashedPin`: Hashed version of the account PIN.
  - `transactions`: List of transactions associated with the account.
  - `failedAttempts`: Number of failed authentication attempts.
  - `isLocked`: Whether the account is locked due to too many failed attempts.

---

### **4. `Transactions`**
- **Purpose**: Represents a single transaction (e.g., deposit, withdrawal).
- **Key Responsibilities**:
  - Store transaction details (type, amount, timestamp, status).
- **Attributes**:
  - `type`: Type of transaction (e.g., Deposit, Withdraw).
  - `amount`: Amount involved in the transaction.
  - `timeStamp`: Timestamp of the transaction.
  - `status`: Status of the transaction (e.g., Success, Failed).

---

### **5. `Utilities`**
- **Purpose**: Provides utility functions used across the project.
- **Key Responsibilities**:
  - Hash the PIN using a secure hashing algorithm (`hashPIN`).
  - Get the current timestamp (`getCurrentTime`).

---

### **6. `FilesLogger`**
- **Purpose**: Logs transactions and other events to a file.
- **Key Responsibilities**:
  - Log successful and failed transactions.
  - Log authentication attempts.
  - Log account-related events (e.g., account creation, removal).

---

## **How to Use the Project**

- mkdir build && cd buid
- cmake ..
- make 
- ./atm_program

---

## **Example Workflow**

1. **Add Accounts**:
   - The program adds three accounts:
     - Account 1: rahma, Savings, PIN: 123, Balance: 1000.0
     - Account 2: abdelkader, Checking, PIN: 321, Balance: 2000.0
     - Account 3: mohmed, Savings, PIN: 111, Balance: 3000.0

2. **Authenticate User**:
   - The user enters their account number and PIN.
   - If authentication is successful, the user can perform transactions.
   - If authentication fails, the program displays an error message.

3. **Perform Transactions**:
   - The user can:
     - Deposit money.
     - Withdraw money.
     - Check their balance.
     - View their transaction history.

4. **Apply Interest**:
   - The program applies interest to all accounts.

5. **Remove Account**:
   - The program removes an account (e.g., rahma's account).

6. **View Total Funds**:
   - The program calculates and displays the total funds across all accounts.

---

## **Class UML Diagram **
![Uml]()


## **Dependencies**

- **C++ Standard Library**: The project uses the C++ Standard Library for data structures (e.g., `std::vector`, `std::string`) and utilities (e.g., `std::shared_ptr`).
- **OpenSSL**: The `Utilities` class uses OpenSSL for hashing the PIN (optional, if hashing is implemented).


