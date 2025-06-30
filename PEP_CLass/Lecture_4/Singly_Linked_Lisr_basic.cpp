#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        this->next = NULL;
    }
};
void insertAtTail(Node*&tail,int d){
    if(tail==NULL){
        tail = new Node(d);
        return;
    }
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtHead(Node*&head,int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    return;
}
void deleteAtTail(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    if(prev==NULL){
        delete head;
        return;
    }
    prev->next = NULL;
    delete temp;
}
void deleteAtHead(Node* head){
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
}
void deleteAtPos(Node* head,int pos){
    // Node* prev = NULL;
    // Node* curr = head;
    // Node* next = curr->next;
    int count = 1;
    Node* temp = head;
    while(count!=pos-1 && temp!=NULL){
        count++;
        temp = temp->next;
    }
    Node* prev = temp;
    if(temp->next==NULL){
        deleteAtTail(head);
        return;
    }
    if(prev==NULL){
        deleteAtHead(head);
        return;
    }
    Node* curr = prev->next;
    Node* next = curr->next;
    prev->next = next;
    delete curr;
}
void insertAtPosition(Node*&head,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = new Node(d);
    Node* temp2 = head;
    int count = 0;
    while(count!=pos-2 && temp2!=NULL){
        count++;
        temp2 = temp2->next;
    }
    if(temp2->next==NULL){
        insertAtTail(temp2,d);
        return;
    }
    Node* temp3 = temp2->next;
    temp2->next = temp;
    temp->next = temp3;
    return;

}
void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* tail = NULL;
    Node* head = NULL;
    Node* first = new Node(1);
    head = tail = first;
    insertAtTail(tail,10);
    insertAtTail(tail,20);
    insertAtTail(tail,30);
    insertAtTail(tail,40);
    insertAtTail(tail,50);
    insertAtHead(head,5);
    deleteAtPos(head,4);
    insertAtPosition(head,4,25);
    printLL(head);

}