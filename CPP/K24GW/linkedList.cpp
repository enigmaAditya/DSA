#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }

    //take two parameter, node *head and int val
    void insertAtEnd(Node* &head, int val){//explain: This function inserts a new node with the given value at the end of the linked list.  
        Node* newNode = new Node(val);//explain: Create a new node with the provided value.
        if(head == nullptr){//explain all: If the list is empty, set the new node as the head.
            head = newNode;//explain: Update the head pointer to point to the new node.
            return;//explain: Exit the function as the insertion is complete.
        }
        Node* temp = head;//explain: Start from the head of the list.
        while(temp->next != nullptr){//explain: Traverse to the last node of the list.
            temp = temp->next;//explain: Move to the next node.
        }
        temp->next = newNode;//explain: Link the last node to the new node, completing the insertion.
    }//time complexity of above function is O(n)

    
    void insertAtEnd(Node* &head, int val){//better complexity version of insertAtEnd
        //explain Node* &head: This parameter is a reference to a pointer to the head of the linked list. why both starn and  & ? because we want to modify the head pointer itself if the list is empty.
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        static Node* tail = head; //static keyword is used to retain the value of tail between function calls
        tail->next = newNode;
        tail = newNode;
        //now newnode will point to null and tail will point to newnode
        //how it will point to null? because when we create a new node, its next pointer is initialized to nullptr in the Node constructor
    }//time complexity of above function is O(1)

    void insertAtEnd(int val){//explain: This function inserts a new node with the given value at the end of the linked list.
        Node* newNode = new Node(val);//explain: Create a new node with the provided value.
        if(head == nullptr){//explain all: If the list is empty, set the new node as the head.
            head = newNode;//explain: Update the head pointer to point to the new node.
            return;//explain: Exit the function as the insertion is complete.
        }
        Node* temp = head;//explain: Start from the head of the list.
        while(temp->next != nullptr){//explain: Traverse to the last node of the list.
            temp = temp->next;//explain: Move to the next node.
        }
        temp->next = newNode;//explain: Link the last node to the new node, completing the insertion.
    }

    void insertAtBeginning(int val){//explain: This function inserts a new node with the given value at the beginning of the linked list.
        Node* newNode = new Node(val);//explain: Create a new node with the provided value.
        newNode->next = head;//explain: Point the new node's next to the current head of the list.
        head = newNode;//explain: Update the head pointer to point to the new node, making it the first node in the list.
    }

    void insertAtPosition(int pos, int val){//explain: This function inserts a new node with the given value at the specified position in the linked list.
        if(pos == 0){//explain: If the position is 0, we need to insert at the beginning.
            insertAtBeginning(val);//explain: Call the function to insert at the beginning.
            return;//explain: Exit the function as the insertion is complete.
        }
        Node* newNode = new Node(val);//explain: Create a new node with the provided value.
        Node* temp = head;//explain: Start from the head of the list.
        for(int i = 0; i < pos - 1 && temp != nullptr; i++){//explain: Traverse to the node just before the desired position.
            temp = temp->next;//explain: Move to the next node.
        }
        if(temp == nullptr){//explain: If we reached the end of the list before reaching the desired position.
            return;//explain: Exit the function as we cannot insert at this position.
        }
        newNode->next = temp->next;//explain: Point the new node's next to the current node's next.
        temp->next = newNode;//explain: Link the current node to the new node, completing the insertion.
    }

    //any shorter version: Yes, we can combine the insertion logic into a single function
    void insertAtPosition(int val,int pos,Node* &head){
        Node* newNode = new Node(val);//explanation: Create a new node with the provided value.
        if (pos == 0) {//explanation: If the position is 0, we need to insert at the beginning.
            newNode->next = head;//explanation: Point the new node's next to the current head of the list.
            head = newNode;//explanation: Update the head pointer to point to the new node, making it the first node in the list.
            return;//explanation: Exit the function as the insertion is complete.
        }
        Node* temp = head;//explanation: Start from the head of the list.
        for (int i = 0; i < pos - 1 && temp != nullptr; i++) {//explanation: Traverse to the node just before the desired position.
            temp = temp->next;//explanation: Move to the next node.
        }
        if (temp == nullptr) {//explanation: If we reached the end of the list before reaching the desired position.
            return;//explanation: Exit the function as we cannot insert at this position.
        }
        newNode->next = temp->next;//explanation: Point the new node's next to the current node's next.
        temp->next = newNode;//explanation: Link the current node to the new node, completing the insertion.
    }
    //any other functions of linked list which is left foe us to implement?: Yes, there are several other common linked list operations that can be implemented, such as deleting a node, searching for a value, reversing the list, and finding the length of the list. Here's an implementation of the delete function:
    void deleteValue(int val){//explain: This function deletes the first occurrence of a node with the specified value from the linked list.
        if(head == nullptr){//explain : If the list is empty, there's nothing to delete.
            return;//explain: Exit the function as no deletion can be performed.
        }//explain: Check if the head node contains the value to be deleted.
        if(head->data == val){//explain: If the head node contains the value to be deleted.
            Node* temp = head;//explain: Store the current head in a temporary pointer.
            head = head->next;//explain: Update the head to point to the next node.
            delete temp;//explain: Free the memory of the old head node.
            return;//explain: Exit the function as the deletion is complete.
        }//explain: If the value is not at the head, we need to search for it in the rest of the list.
        Node* curr = head;//explain: Start from the head of the list.
        Node* prev = nullptr;//explain: Initialize a previous pointer to keep track of the node before the current one.
        while(curr != nullptr && curr->data != val){//explain: Traverse the list until we find the value or reach the end.
            prev = curr;//explain: Move the previous pointer to the current node.
            curr = curr->next;//explain: Move to the next node.
        }
        if(curr == nullptr){//explain: If we reached the end of the list without finding the value.
            return;//explain: Exit the function as there's nothing to delete.
        }
        prev->next = curr->next;//explain: Bypass the current node to remove it from the list.
        delete curr;//explain: Free the memory of the node to be deleted.
    }//time complexity of above function is O(n)

    void deleteAtPosition(int pos){//explain: This function deletes the node at the specified position in the linked list.
        if(head == nullptr){//explain: If the list is empty, there's nothing to delete.
            return;//explain: Exit the function as no deletion can be performed.
        }
        if(pos == 0){//explain: If the position is 0, we need to delete the head node.
            Node* temp = head;//explain: Store the current head in a temporary pointer.
            head = head->next;//explain: Update the head to point to the next node.
            delete temp;//explain: Free the memory of the old head node.
            return;//explain: Exit the function as the deletion is complete.
        }
        Node* curr = head;//explain: Start from the head of the list.
        Node* prev = nullptr;//explain: Initialize a previous pointer to keep track of the node before the current one.
        for(int i = 0; i < pos && curr != nullptr; i++){//explain: Traverse to the node at the specified position.
            prev = curr;//explain: Move the previous pointer to the current node.
            curr = curr->next;//explain: Move to the next node.
        }
        if(curr == nullptr){//explain: If we reached the end of the list before reaching the desired position.
            return;//explain: Exit the function as there's nothing to delete.
        }
        prev->next = curr->next;//explain: Bypass the current node to remove it from the list.
        delete curr;//explain: Free the memory of the node to be deleted.
    }//time complexity of above function is O(n)

    //function to search a value in linked list
    bool search(int val){
        //also return the position of the value if found
        Node* temp = head;//explain: Start from the head of the list.
        int pos = 0;
        while(temp != nullptr){
            if(temp->data == val){
                cout << "Value found at position: " << pos << endl;
                return true;
            }
            temp = temp->next;
            pos++;
        }
        return false;
    }

    //reverse a linked list:
    //leetcode 206:
    void reverse(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        // return head; (if function was non void)
    }

    //delete a node without access of head:
    //leetcode 237:
    void deleteNode(Node* nodeToDelete){
        if(nodeToDelete == nullptr || nodeToDelete->next == nullptr){
            return; //cannot delete the node
        }
        Node* temp = nodeToDelete->next;
        nodeToDelete->data = temp->data;
        nodeToDelete->next = temp->next;
        delete temp;
    }
    
    //leetcode 876:
    Node* findMiddle(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //function to get length of linked list
    int length(){
        int len = 0;
        Node* temp = head;
        while(temp != nullptr){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    int getvalueatindex(int index){
        Node* temp = head;
        int pos = 0;
        while(temp != nullptr){
            if(pos == index){
                return temp->data;
            }
            temp = temp->next;
            pos++;
        }
        //if index is out of bounds
        throw out_of_range("Index out of bounds");
    }
    //function to display the linked list
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    
};

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        if (arr.empty()){
            return nullptr;
        }
        Node* head = new Node(arr[0]);
        Node* tail = head;

        for (int i = 1; i<arr.size();i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        return head;
    }
};