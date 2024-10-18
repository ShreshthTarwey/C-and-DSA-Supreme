#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
class Queue{
    Node* head;
    Node* tail;
    public:
    Queue(){
        head=nullptr;
        tail=nullptr;
    }
    void push(int val){
        if(head==nullptr && tail==nullptr){
            Node* newnode = new Node(val);
            head=newnode;
            tail=newnode;
        }
        else{
            Node* newnode = new Node(val);
            newnode->next = tail;
            tail = newnode;
        }
    }
    void pop(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    bool isEmpty(){
        if(head==NULL && tail==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    int front(){
       return head->data; 
    }
    int size(){
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
};