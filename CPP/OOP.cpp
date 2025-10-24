#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

class BankAccount {
private:
	double balance;
};
int main() {
    Dog dog;
    dog.speak();  // Inherited function
    dog.bark();   // Dog's own function
    return 0;
}