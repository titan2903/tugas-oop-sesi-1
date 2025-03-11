#include <iostream>
#include <string>
using namespace std;

// BankAccount class definition
class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    // Constructor to initialize a bank account
    BankAccount(string accNumber, string name, double initialBalance) {
        accountNumber = accNumber;
        holderName = name;
        if (initialBalance < 0) {
            balance = 0;
            cout << "Initial balance cannot be negative. Setting balance to 0." << endl;
        } else {
            balance = initialBalance;
        }
    }

    // Method to deposit an amount into the bank account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Method to withdraw an amount from the bank account
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrew: " << amount << ". New balance: " << balance << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    // Method to transfer an amount to another bank account
    void transfer(BankAccount &toAccount, double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                toAccount.deposit(amount);
                cout << "Transferred: " << amount << " to " << toAccount.holderName << ". New balance: " << balance << endl;
            } else {
                cout << "Insufficient balance for transfer." << endl;
            }
        } else {
            cout << "Transfer amount must be positive." << endl;
        }
    }

    // Method to get the current balance of the bank account
    double getBalance() const {
        return balance;
    }

    // Method to get the account number of the bank account
    string getAccountNumber() const {
        return accountNumber;
    }

    // Method to get the holder name of the bank account
    string getHolderName() const {
        return holderName;
    }
};

int main() {
    // Creating and initializing two bank accounts using the constructor
    BankAccount account1("123456", "John Doe", 500.0);
    BankAccount account2("654321", "Jane Smith", 300.0);

    // Performing some operations on the first account
    account1.deposit(200.0);   // Deposit 200.0 into account1
    account1.withdraw(100.0);  // Withdraw 100.0 from account1
    account1.transfer(account2, 150.0); // Transfer 150.0 from account1 to account2

    // Displaying the final balances of both accounts
    cout << "Account 1 balance: " << account1.getBalance() << endl;
    cout << "Account 2 balance: " << account2.getBalance() << endl;

    return 0;
}
