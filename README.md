# ATM Machine Simulator in C++

## Project Title

**ATM Machine Simulator using C++ and Data Structures**

---

## Brief One Line Summary

A console-based ATM simulation system developed in C++ that demonstrates object-oriented programming and core data structure concepts such as stacks, queues, hashing, and searching algorithms to perform basic banking operations.

---

## Overview

This project implements a simplified Automated Teller Machine (ATM) system using C++. The program simulates common banking operations such as account authentication, balance inquiry, deposits, withdrawals, PIN change, and transaction history.

The primary objective of the project is to apply fundamental **Data Structures and Algorithms (DSA)** concepts together with **Object-Oriented Programming (OOP)** principles. The system is designed in a modular manner using classes, efficient searching techniques, and structured data storage.

The project also highlights how choosing efficient algorithms and data structures reduces computational overhead, improving performance and energy efficiency in software systems.

---

## Problem Statement

Traditional banking systems rely heavily on secure, efficient transaction management. The challenge is to design a simplified ATM system that:

* Authenticates users securely using account number and PIN
* Allows users to perform banking operations
* Stores and retrieves account information efficiently
* Uses appropriate data structures and algorithms to optimize performance
* Demonstrates object-oriented programming principles

The system should simulate a real ATM environment while maintaining structured code and efficient computational behavior.

---

## Dataset

The project uses a **simulated dataset of bank accounts**, which may include:

* Account Number
* Account Holder Name
* PIN
* Account Balance
* Transaction History

Data may be stored using:

* Arrays or vectors (in-memory storage), or
* File handling using text files to simulate a persistent database.

Example structure of an account record:

```
Account Number
Name
PIN
Balance
```

---

## Tools and Technologies

### Programming Language

* C++

### Concepts Used

* Object-Oriented Programming
* Data Structures
* Algorithm Analysis
* Exception Handling

### Libraries

* `<iostream>`
* `<vector>`
* `<stack>`
* `<queue>`
* `<map>` or `<unordered_map>`
* `<fstream>` (optional for file storage)

### Development Environment

* CodeBlocks / Dev-C++ / Visual Studio / g++

---

## Methods

The system is developed using multiple programming and algorithmic techniques:

### 1. Object-Oriented Design

Classes such as:

* `Account`
* `ATM`
* `Transaction`

These classes implement encapsulation and abstraction.

### 2. Data Structures

Different structures are used for different purposes:

* **Vector / Array** – storing account information
* **Stack** – undo last transaction
* **Queue** – manage transaction requests
* **Hash Map** – fast account lookup
* **Linked List** – dynamic transaction history

### 3. Searching Algorithms

* Linear Search for small datasets
* Binary Search for sorted account records

### 4. Sorting Algorithms

Transaction records can be sorted using:

* Bubble Sort
* Merge Sort
* Quick Sort

### 5. Exception Handling

Errors such as incorrect PIN, insufficient balance, or invalid input are handled using try-catch mechanisms.

---

## Key Insights

* Efficient data structures significantly improve system performance.
* Hash tables provide faster account lookup compared to sequential search.
* Object-oriented design improves code modularity and maintainability.
* Algorithm efficiency affects computational overhead and energy consumption.
* Structured programming improves reliability in financial applications.

---

## Dashboard / Model / Output

Since the project is a **console-based application**, the interface consists of a menu-driven system.

Example menu:

```
===== ATM MAIN MENU =====

1. Login
2. Check Balance
3. Deposit Money
4. Withdraw Money
5. Mini Statement
6. Change PIN
7. Exit
```

Example output:

```
Enter Account Number: 1021
Enter PIN: ****

Login Successful

Current Balance: ₹15,000
```

The system displays transaction details and updates account balances dynamically.

---

## How to Run This Project

### Step 1

Install a C++ compiler such as:

* g++
* CodeBlocks
* Dev-C++

### Step 2

Download or clone the project files.

### Step 3

Compile the program:

```
g++ atm_simulator.cpp -o atm
```

### Step 4

Run the program:

```
./atm
```

### Step 5

Follow the menu prompts to perform ATM operations.

---

## Results & Conclusion

The ATM Machine Simulator successfully demonstrates the integration of **Data Structures, Algorithms, and Object-Oriented Programming in C++**.

The system efficiently performs essential banking operations such as authentication, deposits, withdrawals, and transaction tracking. Through the use of appropriate data structures like hash maps, stacks, and queues, the project highlights the importance of selecting optimal algorithms for better performance.

This project also reinforces the practical relevance of algorithm efficiency in reducing computational cost and energy consumption, contributing to more sustainable software systems.

Future improvements may include:

* GUI-based interface
* Database integration
* Multi-user banking system
* Enhanced security mechanisms.

---

