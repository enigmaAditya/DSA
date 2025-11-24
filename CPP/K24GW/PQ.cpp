#include<bits/stdc++.h>
using namespace std;
// priority queue through Array
class myPQ {
private:
    int *arr;
    int size;
    int capacity;
public:
    myPQ(int n) {
        capacity = n;
        arr = new int[n];
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void insert(int x) {
        if(isFull()) {
            return;
        }
        arr[size] = x;
        size++;
        // Bubble up the newly added element to maintain heap property
        int i = size - 1;
        while(i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void removeMax() {
        if(isEmpty()) {
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        // Bubble down the root element to maintain heap property
        int i = 0;
        while(true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < size && arr[left] > arr[largest]) {
                largest = left;
            }
            if(right < size && arr[right] > arr[largest]) {
                largest = right;
            }
            if(largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    int getMax() {
        if(isEmpty()) {
            return -1;
        }
        return arr[0];
    }
    int getSize() {
        return size;
        }

    
};
// priority queue through Linked List
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class MyPQLL {
private:
    Node* head;
    int size;
public:
    MyPQLL() {
        head = nullptr;
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    void insert(int x) {
        Node* newNode = new Node(x);
        if(!head || head->data < x) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            while(curr->next && curr->next->data >= x) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        size++;
    }
    void removeMax() {
        if(isEmpty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    int getMax() {
        if(isEmpty()) {
            return -1;
        }
        return head->data;
    }

    int getSize() {
        return size;
    }
};

int main() {
    // Write C++ code here
    myPQ pq(10);
    pq.insert(5);
    pq.insert(10);
    pq.insert(3);
    cout << "Max element in array-based PQ: " << pq.getMax() << endl; // 10
    pq.removeMax();
    cout << "Max element after removal: " << pq.getMax() << endl; // 5

    MyPQLL pql;
    pql.insert(7);
    pql.insert(2);
    pql.insert(9);
    cout << "Max element in linked list-based PQ: " << pql.getMax() << endl; // 9
    pql.removeMax();
    cout << "Max element after removal: " << pql.getMax() << endl; // 7

    return 0;
}