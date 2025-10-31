// Charles Edge
// CS310-T301
// M8: Assignment
// Source CH10, Programming Exercise 21

#include <iostream>
#include <string>
using namespace std;

class bankAccount {
private:
    string ActholderName;
    int accountNo;
    string ActType; 
    double balance;
    double interestRate; 

    static int nextAccountNo;

public:
 // Constructor
    bankAccount(string name = "", string type = "Checking", double initialBalance = 0.0, double rate = 0.01) {
        ActholderName = name;
        ActType = type;
        balance = initialBalance;
        interestRate = rate;
        accountNo = ++nextAccountNo;
    }

 // Display account details
    void displayAccount() const {
        cout << "***********************************" << endl;
        cout << "Account # " << accountNo << endl;
        cout << "Account Holder Name: " << ActholderName << endl;
        cout << "Account Type: " << ActType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "***********************************" << endl;
    }

 // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully!!\n";
        }
        else {
            cout << "Invalid deposit amount, please try again!!\n";
        }
    }

 // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully!!\n";
        }
        else {
            cout << "Insufficient funds or invalid amount, please try again!!\n";
        }
    }

 // Apply interest specified 
    void applyInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Applied interest: $" << interest << endl;
    }
};

// Act number will start after 35000
int bankAccount::nextAccountNo = 35000;

int main() {
// Array with 10 bank accounts
    bankAccount customers[10] = {
        bankAccount("Darth Vader", "Savings", 21500.0, 0.10),
        bankAccount("Harry Potter", "Checking", 10000.0, 0.02),
        bankAccount("Frodo Baggins", "Savings", 1000.0, 0.15),
        bankAccount("Tony Stark", "Checking", 55000.0, 0.03),
        bankAccount("William Riker", "Savings", 500.0, 0.04),
        bankAccount("Katniss Everdeen", "Checking", 50.0, 0.007),
        bankAccount("Dracula", "Savings", 2000.0, 0.001),
        bankAccount("Winifred Sanderson", "Checking", 2500.0, 0.19),
        bankAccount("Mike Myers", "Savings", 3350.0, 0.050),
        bankAccount("Beetlejuice", "Checking", 10.0, 0.015)
    };

// Display all accounts
    cout << "Account Details Below:\n";
    for (int i = 0; i < 10; ++i) {
        customers[i].displayAccount();
    }

// Example operation
    cout << "\nPerforming Transactions... Please Wait... \n";
// Darth Vader deposits $100
    customers[0].deposit(100);    
// Dracula withdraws $50
    customers[1].withdraw(50);     
// Winifred earns interest
    customers[2].applyInterest();    

// Displays updated account information
    cout << "\nBelow are the updated account details:\n";
    customers[0].displayAccount();
    customers[1].displayAccount();
    customers[2].displayAccount();

    return 0;
}