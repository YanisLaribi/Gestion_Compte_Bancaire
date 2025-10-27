# Bank Account Management

Object-oriented C++ project for managing clients and bank accounts with validation, exception handling, and interest calculation. (Project developed for educational purposes)

## Main Features

- Creation, management, and deletion of clients and bank accounts.
- Support for different account types: **Savings** and **Checking**.
- Automatic interest calculation based on account type.
- Strict validation of user inputs and files.
- Custom exception system for enhanced robustness.

## Qt Graphical Interface

A modern and intuitive graphical interface has been developed with **Qt** to facilitate program usage:

- Manage clients and accounts through interactive windows and forms.
- Dynamic display of information and statements.
- Simplified manipulation (add, delete, modify) through buttons and menus.

## Project Architecture

- `Client`: Manages personal details and the list of accounts of a client.
- `Account`: Abstract base class allowing extension to:
    - `Savings`: Standard interest calculation, balance management.
    - `Checking`: Management of transaction counts, minimum interest rate, and specialized checking account rules.
- `Date`: Utilities for date management, validation, and formatting.
- `validationFormat`: Functions to validate formats (name, date, phone number, file).
- `AccountException`: Centralized management of domain-specific error handling.
