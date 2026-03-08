# ATM-Banking-Interface
## 🔗 Project Context
This ATM System is a specialized module of my (https://github.com/abdelr7man26/Bank-Management-System.git). While the Core System handles administrative tasks and database management, this repository focuses on the customer-facing interface, simulating real-world ATM operations with high security and data integrity.
 
 ---

## ✨ Features

The system provides several core ATM functionalities:

### 🔐 Authentication

Secure login using credentials (such as card number / PIN if implemented).

Prevents unauthorized access.

### 💰 Banking Operations

Users can perform common ATM transactions:

Check account balance

Deposit money

Withdraw money

Display transaction results

### 🧾 Transaction Handling

Updates account balance after each transaction.

Ensures valid operations (e.g., prevents withdrawing more than the available balance).

### 🖥 User Interface

Interactive interface for easy navigation.

Menu-driven system for selecting operations.

---

## 🛠 Technologies Used

The project was developed using the following technologies:

Programming Language: c++

Concepts Used:

Object-Oriented Programming (OOP)

Classes and Objects

Conditional Statements

Loops

User Input Handling

File handling

---

## 📂 Project Structure

Example structure of the project:

ATM-Banking-Interface
│
├── ATM.CPP
├── Core
|     ├── Client.h
|     ├── global.h
├── File handler
|     ├── FileHandler.h
├── UI
|     ├── Loginscreen
|     ├── MainMenuscreen
|     ├── FastWithdrawSreen
|     ├── WithdrawScreen
|     ├── DepositeScreen
|     ├── Cheack balance screen
|     ├── SCreen
│
└── README.md

---
##⚙️ How to Run the Project
1️⃣ Clone the Repository
   
  ```bash
git clone https://github.com/abdelr7man26/ATM-Banking-Interface.git
 ```
2️⃣ Navigate to the Project Folder
  ```bash

cd ATM-Banking-Interface
```
3️⃣ Compile the Program
  ```bash
g++ main.cpp -o BankSystem
```
4️⃣ Run the Application
  ```bash
./ATM
```

---
## 📖 Example Usage

Start the program.

Login to the ATM system.

Choose an operation from the menu:

  Check Balance

  Deposit Money

  Withdraw Money

The system updates and displays the result.


---
## 🎯 Learning Objectives

This project helps developers understand:

ATM system logic

Banking transaction flow

Object-oriented programming

Handling user input and validation

Writing clean and structured code

--- 
## 🚀 Future Improvements

Possible enhancements for the project:

Add database integration

Implement transaction history

Add GUI interface

Improve security and authentication

Support multiple accounts

---
## 👨‍💻 Author

Abdelrhman Mohamed

GitHub:
https://github.com/abdelr7man26




















