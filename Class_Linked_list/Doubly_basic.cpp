#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        this->data = d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
        }
        cout<<"Memory free for data: "<<val<<endl;
    }
};
void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int getLength(Node *head){
    int count = 0;
    Node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}
void insertAtHead(Node *&head,Node* &tail,int d){
    if(head==NULL){
        Node* newnode = new Node(d);
        head = newnode;
        tail = newnode;
    }
    else{
    Node *newnode = new Node(d);
    newnode->next = head;
    if(head!=NULL){
    head->prev = newnode;
    }
    head = newnode;
    }
}
void insertAtTail(Node* &head,Node *&tail,int d){
   if(tail==NULL){
    Node* newnode = new Node(d);
    tail = newnode;
    head = newnode;
   }
   else{
    Node* newnode = new Node(d);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
   }
}
void insertAtPos(Node* &head,Node* &tail,int pos,int d){
    if(pos==1){
        insertAtHead(head,tail,d);
        return;
    }
    int count = 1;
    Node *current = head;
    while(count<pos-1 && current!=NULL){
        current=current->next;
        count++;
    }
    if(current->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }
    Node* newnode = new Node(d);
    Node* next = current->next;
    current->next = newnode;
    newnode->next = next;
    newnode->prev = current;
    next->prev = newnode;
}
void deleteAtPos(Node *&head,Node* &tail,int pos){
    if(pos==1){
        Node *temp = head;
        // temp->next = head;
        head = head->next;
        if(temp->next!=NULL){
        temp->next->prev = NULL;
        temp->next = NULL;}
        else{
            head = NULL;
            tail = NULL;
        }
        delete temp;
    }
    else{
        int count = 1;
        Node* current = head;
        while(count<pos && current!=NULL){
            current = current->next;
            count++;
        }
        if(current->next==NULL){
            tail = current->prev;
            current->prev->next=NULL;
            current->prev=NULL;
            delete current;
        }
        else{
            current->prev->next = current->next;
            current->next->prev=current->prev;
            current->next=NULL;
            current->prev = NULL;
            delete current;
        }
    }
}
int main(){
    // Node *list = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    // print(head);
    insertAtHead(head,tail,20);
    // print(head);
    insertAtHead(head,tail,30);
    // print(head);
    insertAtHead(head,tail,40);
    // print(head);
    insertAtTail(head,tail,5);
    // print(head);
    insertAtPos(head,tail,4,15);
    // print(head);
    insertAtPos(head,tail,1,50);
    // print(head);
    insertAtPos(head,tail,7,1);
    // print(head);
    insertAtPos(head,tail,8,0);
    print(head);
    deleteAtPos(head,tail,1);
    deleteAtPos(head,tail,7);
    deleteAtPos(head,tail,3);
    print(head);
    cout<<"The tail\'s data is: "<<tail->data<<endl;
    cout<<"The head\'s data is: "<<head->data<<endl;
    cout<<"The length of the list is: "<<getLength(head)<<endl;
}