#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
    this -> data = data;
    this -> next = NULL;}
    ~Node(){
        int val = this->data;
        this->next = NULL;
        cout<<"The node with data: "<<val<<" is deleted."<<endl;
    }
};
void insertAtHead(Node *&head,int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp; 
}
void print(Node *&head) {
    Node *temp = head;  // Start from the head of the list
    while (temp != NULL) {  // Traverse until the end of the list
        cout << temp->data << " ";  // Print the data of each node
        temp = temp->next;  // Move to the next node
    }
    cout << endl;  // To print a newline after the entire list
}
void insertAttail(Node *&tail,int d){
    Node *temp = new Node(d);
    // while()
    tail -> next = temp;
    tail = temp;
}
void insertinPosition(Node* &tail,Node *&head,int pos,int d){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
    int count = 1;
    Node *temp = head;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAttail(tail,d);
        return;
    }
    Node *newnode = new Node(d);
    newnode->next = temp->next;
    temp->next = newnode;

}
void deletenodepos(Node *&head,Node *&tail,int pos){
    int count = 1;
    Node* current = head;
    Node* previous = nullptr;

    if(pos==1){
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;

    }
    // Node *temp = head;
   
    while(count<pos){
        previous = current;
        current=current->next;
        count++;
    }
    if (current->next == NULL) {
        tail = previous;
    }
    previous->next = current->next;
    current->next = NULL;
    delete current;
    
}
int main(){
    Node *list = new Node(10);
    Node* head = list;
    Node* tail = list;
    insertAttail(tail,20);
    insertAttail(tail,30);
    insertAttail(tail,40);
    print(head);
    // cout<<"Tail->data: "<<tail->data;
    deletenodepos(head,tail,4);
    print(head);
    cout<<"Tail data: "<<tail->data<<endl;
}