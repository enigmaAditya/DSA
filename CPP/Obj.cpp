// Obj.cpp
// Demonstrates objects in C++: classes, constructors, copy/move, stack vs heap, arrays and vectors.

#include <iostream>
#include <string>
#include <vector>

class Person {
    std::string name;
    int age;
    static int live_count;
public:
    // Default
    Person() : name("<empty>"), age(0) { ++live_count; std::cout << "Default ctor: " << name << "\n"; }

    // Parameterized
    Person(std::string n, int a) : name(std::move(n)), age(a) { ++live_count; std::cout << "Param ctor: " << name << "\n"; }

    // Copy
    Person(const Person& o) : name(o.name), age(o.age) { ++live_count; std::cout << "Copy ctor: " << name << "\n"; }

    // Move
    Person(Person&& o) noexcept : name(std::move(o.name)), age(o.age) { ++live_count; o.age = 0; std::cout << "Move ctor: " << name << "\n"; }

    // Destructor
    ~Person() { std::cout << "Dtor: " << name << "\n"; --live_count; }

    void greet() const { std::cout << "Hi, I'm " << name << " (" << age << ")\n"; }

    static int live() { return live_count; }
};

int Person::live_count = 0;

int main() {
    // Stack object
    Person a("Alice", 30);
    a.greet();

    // Copying
    Person b = a;   // copy ctor
    b.greet();

    // Moving
    Person c = std::move(a); // move ctor
    c.greet();

    // Heap object
    Person* p = new Person("Bob", 25);
    p->greet();

    // Array of objects (stack)
    Person arr[2] = { Person("X", 1), Person("Y", 2) };
    arr[0].greet();
    arr[1].greet();

    // Vector (dynamic container) demonstrating emplace_back (construct in-place)
    std::vector<Person> v;
    v.emplace_back("Carol", 22);
    v.emplace_back("Dave", 28);
    for (const auto& person : v) person.greet();

    std::cout << "Live Person objects: " << Person::live() << "\n";

    delete p; // free heap object

    std::cout << "Exiting main\n";
    return 0;
}