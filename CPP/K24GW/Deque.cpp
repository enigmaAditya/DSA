#include<bits/stdc++.h>
using namespace std;
//double ended queue through Array
class myDeque {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
public:
    myDeque(int n) {
        capacity = n;
        arr = new int[n];
        front = -1;
        rear  = -1;
        size  = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
    void insertFront(int x) {
        if(isFull()) {
            return;
        }
        if(isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = x;
        size++;
    }
    void insertRear(int x) {
        if(isFull()) {
            return;
        }
        if(isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        size++;
    }
    void deleteFront() {
        if(isEmpty()) {
            return;
        }
        front = (front + 1) % capacity;
        size--;
        if(size == 0)        // Reset when deque becomes empty
            front = rear = -1;
    }
    void deleteRear() {
        if(isEmpty()) {
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
        if(size == 0)        // Reset when deque becomes empty
            front = rear = -1;
    }
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
    int getSize() {
        return size;
    }
};
//double ended queue through linked list
struct DequeNode {
    int data;
    DequeNode* next;
    DequeNode* prev;
    DequeNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DequeLL {
private:
    DequeNode* front;
    DequeNode* rear;
    int size;
public:
    DequeLL() {
        front = rear = nullptr;
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    void insertFront(int x) {
        DequeNode* newNode = new DequeNode(x);
        if(isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }
    void insertRear(int x) {
        DequeNode* newNode = new DequeNode(x);
        if(isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }
    void deleteFront() {
        if(isEmpty()) {
            return;
        }
        DequeNode* temp = front;
        front = front->next;
        if(front) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // deque is now empty
        }
        delete temp;
        size--;
    }
    void deleteRear() {
        if(isEmpty()) {
            return;
        }
        DequeNode* temp = rear;
        rear = rear->prev;
        if(rear) {
            rear->next = nullptr;
        } else {
            front = nullptr; // deque is now empty
        }
        delete temp;
        size--;
    }
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return front->data;
    }
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return rear->data;
    }
    int getSize() {
        return size;
    }
};
int main() {
    // Write C++ code here
    myDeque dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    cout << "Front element: " << dq.getFront() << endl; // 5
    cout << "Rear element: " << dq.getRear() << endl;   // 20
    dq.deleteFront();
    cout << "Front element after deletion: " << dq.getFront() << endl; // 10

    DequeLL dqll;
    dqll.insertRear(30);
    dqll.insertFront(15);
    cout << "Front element (LL): " << dqll.getFront() << endl;
    cout << "Rear element (LL): " << dqll.getRear() << endl;
    dqll.deleteRear();
    cout << "Rear element after deletion (LL): " << dqll.getRear() << endl;
    
    return 0;
}
