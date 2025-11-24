#include <bits/stdc++.h>
using namespace std;
// queue through Array
class myQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    myQueue(int n) {
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

    void enqueue(int x) {
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

    void dequeue() {
        if(isEmpty()) {
            return;
        }

        front = (front + 1) % capacity;
        size--;

        if(size == 0)        // Reset when queue becomes empty
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
};

// queue through linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class MyQueueLL {
private:
    Node* front;
    Node* rear;
    int s;

public:
    MyQueueLL() {
        front = rear = nullptr;
        s=0;
    }

    ~MyQueueLL() {
        // free all nodes
        while (!isEmpty()) dequeue();
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* node = new Node(x);
        if (isEmpty()) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        s++;
    }

    void dequeue() {
        if (isEmpty()) return;

        Node* temp = front;
        front = front->next;
        if (front == nullptr) // queue became empty
            rear = nullptr;
        delete temp;
        s--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int getRear() {
        if (isEmpty()) return -1;
        return rear->data;
    }

    int size(){
        return s;
    }

    // optional debug helper
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* cur = front;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << '\n';
    }
};

int main(){
    // array-based queue demo
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"Array Queue - Front element: "<<q.getFront()<<endl; // 10
    cout<<"Array Queue - Rear element: "<<q.getRear()<<endl;   // 30
    q.dequeue();
    cout<<"Array Queue - Front after dequeue: "<<q.getFront()<<endl; // 20

    // linked-list queue demo
    MyQueueLL qll;
    qll.enqueue(10);
    qll.enqueue(20);
    qll.enqueue(30);
    cout<<"LinkedList Queue - Front element: "<<qll.getFront()<<endl; // 10
    cout<<"LinkedList Queue - Rear element: "<<qll.getRear()<<endl;   // 30
    qll.dequeue();
    cout<<"LinkedList Queue - Front after dequeue: "<<qll.getFront()<<endl; // 20
    cout<<qll.size()<<endl;

    return 0 ;
}
