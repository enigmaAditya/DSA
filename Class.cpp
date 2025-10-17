// Single-file, clean example for classes, constructors, copy semantics, and friend function.

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() : name("Unnamed"), age(0) { cout << "Default constructor called\n"; }
    Person(const string &n, int a) : name(n), age(a) { cout << "Parameterized constructor called for " << name << "\n"; }
    Person(const Person &o) : name(o.name), age(o.age) { cout << "Copy constructor called (copy of " << o.name << ")\n"; }
    Person& operator=(const Person &o) { if (this!=&o) { cout<<"Copy assignment called ("<<o.name<<" -> "<<name<<")\n"; name=o.name; age=o.age; } else cout<<"Copy assignment self-assignment\n"; return *this; }
    const string& getName() const { return name; }
    int getAge() const { return age; }
    friend void printPrivate(const Person &p);
};

void printPrivate(const Person &p) { cout << "[friend] Name: " << p.name << ", Age: " << p.age << "\n"; }

int main() {
    cout << "--- Creating person A with parameterized constructor ---\n";
    Person a("Alice", 30);
    cout << "--- Creating person B with default constructor ---\n";
    Person b;
    cout << "--- Assigning B = A (copy assignment) ---\n";
    b = a;
    cout << "--- Creating person C as a copy of A (copy constructor) ---\n";
    Person c = a;
    cout << "A: " << a.getName() << ", " << a.getAge() << "\n";
    cout << "B: " << b.getName() << ", " << b.getAge() << "\n";
    cout << "C: " << c.getName() << ", " << c.getAge() << "\n";
    cout << "--- Using friend function to access private members ---\n";
    printPrivate(a); printPrivate(b);
    return 0;
}