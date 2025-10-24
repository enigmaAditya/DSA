#include <iostream>
using namespace std;


class BankAccount {
private:
    string name;
    float amount;

public:
    BankAccount(string name, float amount) {
        this->name = name;
        this->amount = amount;
    }


    string get_name() {
        return this->name;
    }

    float get_amount() {
        return this->amount;
    }


    void set_name(string name) {
        this->name = name;
    }

    void set_amount(float amount) {
        this->amount = amount;
    }

    // Common behaviors
    void deposit(float x) {
        this->amount += x;
        cout << x << " deposited successfully. New balance: " << this->amount << endl;
    }

    virtual void withdraw(float x) {
        if (x > this->amount) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        this->amount -= x;
        cout << x << " withdrawn successfully. Remaining balance: " << this->amount << endl;
    }

    // Display account info
    virtual void display() {
        cout << "Account Holder: " << name << " | Balance: " << amount << endl;
    }
};


class SavingsAccount : public BankAccount {
private:
    float interestRate; // %

public:
    SavingsAccount(string name, float amount, float rate)
        : BankAccount(name, amount) {
        this->interestRate = rate;
    }

    void addInterest() {
        float interest = (get_amount() * interestRate) / 100;
        set_amount(get_amount() + interest);
        cout << "Interest of " << interest << " added. New balance: " << get_amount() << endl;
    }

    void display() override {
        cout << "Savings Account - Holder: " << get_name()
             << " | Balance: " << get_amount()
             << " | Interest Rate: " << interestRate << "%" << endl;
    }
};


class CurrentAccount : public BankAccount {
private:
    float transactionFee = 20.0;

public:
    CurrentAccount(string name, float amount)
        : BankAccount(name, amount) {}

    void withdraw(float x) override {
        float total = x + transactionFee;
        if (total > get_amount()) {
            cout << " Insufficient balance (including fee)!" << endl;
            return;
        }
        set_amount(get_amount() - total);
        cout << " Withdrawn: " << x << " + Fee: " << transactionFee
             << " | Remaining: " << get_amount() << endl;
    }

    void display() override {
        cout << " Current Account - Holder: " << get_name()
             << " | Balance: " << get_amount()
             << " | Fee: ₹" << transactionFee << " per withdrawal" << endl;
    }
};


int main() {
    cout << "=== Encapsulation + Inheritance Example ===\n\n";

    BankAccount base("John Doe", 5000);
    base.deposit(1000);
    base.withdraw(2000);
    base.display();

    cout << "\n-------------------------\n";


    SavingsAccount s("Alice", 8000, 5.0);
    s.display();
    s.addInterest();  // custom feature
    s.withdraw(1000); // uses base withdraw
    s.display();

    cout << "\n-------------------------\n";


    CurrentAccount c("Bob", 6000);
    c.display();
    c.withdraw(2000);
    c.display();

    cout << "\n=========================\n";
    return 0;
}