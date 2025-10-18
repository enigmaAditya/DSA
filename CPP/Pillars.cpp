// File: Pillars.cpp
// Demonstrates the four OOP pillars in C++:
// 1) Encapsulation  2) Abstraction  3) Inheritance  4) Polymorphism

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <string>

using namespace std; // added per request

// Abstract Account interface (abstraction)
class Account {
public:
    virtual ~Account() = default;
    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual double getBalance() const = 0;
    virtual string name() const = 0;
};

// 1) Encapsulation: hide data and expose behavior via methods.
// BankAccount now implements Account so we can demonstrate inheritance/polymorphism.
class BankAccount : public Account {
private:
    double balance; // hidden internal state

public:
    BankAccount(double initial = 0.0) : balance(initial) {}

    // controlled access to internal state
    void deposit(double amount) override {
        if (amount > 0) balance += amount;
    }

    bool withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const override { return balance; }
    string name() const override { return "BankAccount"; }
};


// Additional example: SavingsAccount shows inheritance + polymorphism + encapsulation.
// It has an interest rate and an operation to apply interest.
class SavingsAccount : public Account {
private:
    double balance;
    double interestRate; // e.g., 0.02 for 2%

public:
    SavingsAccount(double initial = 0.0, double rate = 0.01)
        : balance(initial), interestRate(rate) {}

    void deposit(double amount) override {
        if (amount > 0) balance += amount;
    }

    // SavingsAccount may restrict overdraft (no overdraft allowed here)
    bool withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const override { return balance; }
    string name() const override { return "SavingsAccount"; }

    // Savings-specific behavior
    void applyInterest() {
        if (interestRate > 0) balance += balance * interestRate;
    }
};

// Demo main() to exercise the pillars
int main() {
    cout << "-- OOP Pillars demo --\n";

    // Abstraction & Encapsulation: create accounts via the Account interface
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<BankAccount>(100.0));
    accounts.push_back(make_unique<SavingsAccount>(200.0, 0.05));

    // Polymorphism: treat them uniformly
    for (auto &acc : accounts) {
        cout << acc->name() << " initial balance: " << acc->getBalance() << "\n";
        acc->deposit(50);
        cout << acc->name() << " after deposit: " << acc->getBalance() << "\n";
    }

    // Apply savings-specific behavior by downcasting (safe because we know index 1 is SavingsAccount)
    if (auto s = dynamic_cast<SavingsAccount*>(accounts[1].get())) {
        cout << "Applying interest to savings...\n";
        s->applyInterest();
        cout << s->name() << " after interest: " << s->getBalance() << "\n";
    }

    // Try withdrawals
    cout << "Attempting withdrawals:\n";
    for (auto &acc : accounts) {
        bool ok = acc->withdraw(120);
        cout << acc->name() << " withdraw 120: " << (ok ? "success" : "failed") << ", balance=" << acc->getBalance() << "\n";
    }

    cout << "-- demo complete --\n";
    return 0;
}
