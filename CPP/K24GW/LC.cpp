#include<bits/stdc++.h>
using namespace std ;
//leetcode 232. Implement Queue using Stacks:
class MyQueue {
    stack<int> s1 ;
    stack<int> s2 ;
public:

    /** Initialize your data structure here. */
    MyQueue() {
        //what to write here:
        

        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x) ;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top()) ;
                s1.pop() ;
            }
        }
        int front = s2.top() ;
        s2.pop() ;
        return front ;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top()) ;
                s1.pop() ;
            }
        }
        return s2.top() ;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty() ;
    } 
};

//leetcode 225. Implement Stack using Queues:
class MyStack {
    queue<int> q1 ;
    queue<int> q2 ;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x) ;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (q1.size() > 1){
            int front = q1.front() ;
            q1.pop() ;
            q2.push(front) ;
        }
        int top = q1.front() ;
        q1.pop() ;
        swap(q1, q2) ;
        return top ;
    }
    
    /** Get the top element. */
    int top() {
        while (q1.size() > 1){
            int front = q1.front() ;
            q1.pop() ;
            q2.push(front) ;
        }
        int top = q1.front() ;
        q2.push(top) ;
        q1.pop() ;
        swap(q1, q2) ;
        return top ;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() ;
    }