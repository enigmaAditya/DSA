#include<iostream>
using namespace std;
#include<stack>
template <typename T>
class stack{
    struct Node{
        T data;
        Node* next;
        Node(T val):data(val),next(nullptr){}
    };
    Node* topNode;
    int currentSize;
public:
    stack():topNode(nullptr),currentSize(0){}
    ~stack(){
        while(!isEmpty()){
            pop();
        }
    }
    void push(T val){
        Node* newNode=new Node(val);
        newNode->next=topNode;
        topNode=newNode;
        currentSize++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return;
        }
        Node* temp=topNode;
        topNode=topNode->next;
        delete temp;
        currentSize--;
    }
    T top(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return T(); // or throw an exception
        }
        return topNode->data;
    }
    int size(){
        return currentSize;
    }
    bool isEmpty(){
        return currentSize==0;
    }
};