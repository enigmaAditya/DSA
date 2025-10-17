// Simple C++ class example demonstrating:
// - class definition and private members
// - default constructor, parameterized constructor
// - copy constructor
// - copy assignment operator
// - friend function that accesses private members
// Build (PowerShell): g++ -std=c++17 -O2 -Wall Class.cpp -o Class.exe

#include <iostream>
#include <string>

class Person {
private:
	std::string name;
	int age;

public:
	// Default constructor
	Person() : name("Unnamed"), age(0) {
		std::cout << "Default constructor called\n";
	}

	// Parameterized constructor
	Person(const std::string &n, int a) : name(n), age(a) {
		std::cout << "Parameterized constructor called for " << name << "\n";
	}

	// Copy constructor
	Person(const Person &other) : name(other.name), age(other.age) {
		std::cout << "Copy constructor called (copy of " << other.name << ")\n";
	}

	// Copy assignment operator
	Person& operator=(const Person &other) {
		std::cout << "Copy assignment called (" << other.name << " -> " << name << ")\n";
		if (this != &other) {
			name = other.name;
			age = other.age;
		}
		return *this;
	}

	// Accessors
	const std::string& getName() const { return name; }
	int getAge() const { return age; }

	// Declare a friend function that can access private members
	friend void printPrivate(const Person &p);
};

// Friend function definition
void printPrivate(const Person &p) {
	std::cout << "[friend] Name: " << p.name << ", Age: " << p.age << "\n";
}

int main() {
	std::cout << "--- Creating person A with parameterized constructor ---\n";
	Person a("Alice", 30);

	std::cout << "--- Creating person B with default constructor ---\n";
	Person b;

	std::cout << "--- Assigning B = A (copy assignment) ---\n";
	b = a; // copy assignment

	std::cout << "--- Creating person C as a copy of A (copy constructor) ---\n";
	Person c = a; // copy constructor

	std::cout << "--- Accessing via public getters ---\n";
	std::cout << "A: " << a.getName() << ", " << a.getAge() << "\n";
	std::cout << "B: " << b.getName() << ", " << b.getAge() << "\n";
	std::cout << "C: " << c.getName() << ", " << c.getAge() << "\n";

	std::cout << "--- Using friend function to access private members ---\n";
	printPrivate(a);
	printPrivate(b);

	return 0;
}

