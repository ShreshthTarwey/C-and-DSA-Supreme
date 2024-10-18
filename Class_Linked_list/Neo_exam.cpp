#include<iostream>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node(int val){
        this->val=val;
        this->next = nullptr;
    }
};
void insertAtEnd(Node *&head, int val){
    Node *newnode = new Node(val);
    Node *temp = head;
    while(temp!=nullptr && temp->next!=nullptr){
        temp = temp->next;
    }
    if(temp==nullptr){
        head = newnode;
    }
    else{
        temp->next = nullptr;
    }
}
void print(Node *&head){
    Node *temp = head;
    while(temp->next!=nullptr){
        cout<<temp->val<<"->";
    }
}
int main(){
    Node *head = nullptr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        insertAtEnd(head,val);
    }
    cout<<"-----------------------------------------------"<<endl;
    print(head);
}    
