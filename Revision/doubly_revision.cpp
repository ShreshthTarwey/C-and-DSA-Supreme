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

}
int main(){
    node * head = NULL;
    node* tail = NULL;

}