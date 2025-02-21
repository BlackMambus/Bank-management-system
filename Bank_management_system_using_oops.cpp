#include <iostream>
#include <vector>
#include <string>

using namespace std;

// BankAccount class to handle individual bank accounts
class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor to initialize a new bank account
    BankAccount(int accNumber, string accHolderName, double initialBalance) {
        accountNumber = accNumber;
        accountHolderName = accHolderName;
        balance = initialBalance;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance is " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance is " << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Function to display account details
    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Current Balance: " << balance << endl;
    }

    // Getter for account number
    int getAccountNumber() {
        return accountNumber;
    }
};

// Bank class to manage multiple accounts
class Bank {
private:
    vector<BankAccount> accounts;  // List of bank accounts

public:
    // Function to create a new account
    void createAccount(int accountNumber, string accountHolderName, double initialBalance) {
        BankAccount newAccount(accountNumber, accountHolderName, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully!" << endl;
    }

    // Function to find account by account number
    BankAccount* findAccount(int accountNumber) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        cout << "Account not found!" << endl;
        return nullptr;
    }

    // Function to delete an account
    void deleteAccount(int accountNumber) {
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->getAccountNumber() == accountNumber) {
                accounts.erase(it);
                cout << "Account deleted successfully!" << endl;
                return;
            }
        }
        cout << "Account not found!" << endl;
    }
};

// Menu-driven interface
int main() {
    Bank bank;
    int choice;
    int accountNumber;
    string accountHolderName;
    double amount;

    do {
        cout << "\nBank Management System\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Delete Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Account Holder Name: ";
                cin.ignore();  // To ignore the newline left in the buffer
                getline(cin, accountHolderName);
                cout << "Enter Initial Balance: ";
                cin >> amount;
                bank.createAccount(accountNumber, accountHolderName, amount);
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                {
                    BankAccount* account = bank.findAccount(accountNumber);
                    if (account) {
                        cout << "Enter Deposit Amount: ";
                        cin >> amount;
                        account->deposit(amount);
                    }
                }
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                {
                    BankAccount* account = bank.findAccount(accountNumber);
                    if (account) {
                        cout << "Enter Withdrawal Amount: ";
                        cin >> amount;
                        account->withdraw(amount);
                    }
                }
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                {
                    BankAccount* account = bank.findAccount(accountNumber);
                    if (account) {
                        account->displayAccountDetails();
                    }
                }
                break;

            case 5:
                cout << "Enter Account Number to Delete: ";
                cin >> accountNumber;
                bank.deleteAccount(accountNumber);
                break;

            case 6:
                cout << "Exiting... Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}




