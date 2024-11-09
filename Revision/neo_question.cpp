// Single File Programming Question
// Problem Statement



// Sara is organizing a fun game for her friends where they have to rotate a sequence of characters in a specific way. She wants to use a two-way linked list to perform this rotation efficiently. 



// Write a program to help Sara by implementing the following operations:

// Insert characters at the end of a two-way linked list.
// Rotate the linked list by a given number of positions to the left.
// Display the rotated linked list.


// Company Tags: Infosys

// Input format :
// The first line of input contains an integer n, representing the number of characters to be added to the list.

// The second line consists of n characters, representing the data to be added to the list.

// The third line contains an integer k, representing the number of positions by which the list should be rotated.

// Output format :
// The output prints the characters in the two-way linked list after rotating it by k positions.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15
#include<iostream>
using namespace std;
class node{
     public:
    node* next;
    int data;
    node* prev;
   
    node(int v) : next(NULL),data(v),prev(NULL) {}
};
void  insertAtHead(node*&head,node*&tail,int v){
    if(head==NULL){
        head = new node(v);
        tail = head;        // return 
    }
    node* temp = new node(v);
    temp->next = head;
    head->prev = temp;
    head = temp;
    // return head;
}
void delete_first(node*&head,node*&tail){
    if(head==NULL) return;
    node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void atEnd(node*&head,node*&tail,int v){
    if(tail==NULL){
        tail = head = new node(v);
        return;
    }
    node* temp = new node(v);
    node* p = tail;
    tail->next = temp;
    tail = tail->next;
    tail->prev = p;
}
void rotate(node*& head,node*& tail,int r){
    while(r--){
        atEnd(head,tail,head->data);
        node* temp = head;
        head=head->next;
        head->prev = NULL;
        delete temp;
    }
}
void print(node* head){
    node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}
int main(){
    node * head = NULL;
    node* tail = NULL;
    atEnd(head,tail,10);
    atEnd(head,tail,20);
    atEnd(head,tail,30);
    atEnd(head,tail,40);
    atEnd(head,tail,50);
    print(head);
    cout<<endl;
    rotate(head,tail,2);
    print(head);


}