#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cctype>


using namespace std;

class Stack {
    //use this and arrow operator to implement stack operations
    //change the code with this and arrow operator to implement stack operations
private:
    int *arr;
    int capacity;
    int top;
public:
    Stack(int size = 10) {
        this->arr = new int[size];
        this->capacity = size;
        this->top = -1;
    }

    bool isEmpty() {
        return this->top == -1;
    }

    bool isFull() {
        return this->top == this->capacity - 1;
    }

    void push(int x) {
        if (this->isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        this->arr[++this->top] = x;
    }

    int pop() {
        if (this->isEmpty()) {
            cout << "Stack Underflow\n";
            return -1; // or throw an exception
        }
        this->top--;
        return this->arr[this->top + 1];
    }
    int size() {
        return this->top + 1;
    }
    int peek() {
        if (this->isEmpty()) {
            cout << "Stack is empty\n";
            return -1; // or throw an exception
        }
        return this->arr[this->top];
    }
};
class Stack2{//stack using linkedlist
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* top;
public:
    Stack2() : top(nullptr) {}
    ~Stack2() {
        while (!isEmpty()) {
            pop();
        }
    }
    //all operations of stack
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    bool isFull() {
        return false; //linked list based stack is never full unless memory is exhausted
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1; // or throw an exception
        }
        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1; // or throw an exception
        }
        return top->data;
    }


};

//leetcode 150: Evaluate Reverse Polish Notation
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

//geeksforgeeks : infix to postfix using stack
class Solution {
  public:
    string infixToPostfix(string& s) {
        auto precedence = [](char op) {
            if (op == '+' || op == '-') return 1;
            if (op == '*' || op == '/') return 2;
            return 0;
        };
        
        stack<char> st;
        string result;
        for (char c : s) {
            if (isalnum(c)) {
                result += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop(); // pop '('
            } else {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
        
    }
};


int main() {
	// simple usage to ensure the translation unit compiles
	stack<int> s;
	s.push(1);
	cout << s.top() << endl;
    //all the possible operations on stack:
    // push, pop, top, size, empty, emplace, swap
    //more functions
    // pushing elements onto the stack
    s.push(5);
    //emplacing elements
    s.emplace(4);//explanation: constructs the element in place at the top of the stack
    //difference between push and emplace is that push copies or moves an existing object onto the stack, whereas emplace constructs the object directly in the memory allocated for the stack, potentially improving performance by eliminating unnecessary copy or move operations.
    s.push(3);
    s.push(2);
    // displaying the top element
    cout << "Top element: " << s.top() << endl; // Outputs 2
    // removing the top element
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Outputs 3
    // checking the size of the stack
    cout << "Size of stack: " << s.size() << endl;
	return 0;
}
