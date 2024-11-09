#include<iostream>
using namespace std;

class llnode {
    public:
    int val;
    llnode* next;  
    
    llnode(int value) {  
        val = value;
        next = nullptr;
    }
};

llnode* makeLinkedList() {
    int value;
    cin >> value;
    
    if (value == -1) {
        return nullptr; 
    }

    llnode* newNode = new llnode(value); 
    newNode->next = makeLinkedList();  
    return newNode;
}

void printLinkedList(llnode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
void len(llnode* head){
    static int count = 0;
    if(head==NULL){
        cout<<count;
    }
    count++;
    len(head->next);
}

int main() {
    llnode* head = makeLinkedList(); 
    
    // cout << "Linked List: ";
    // printLinkedList(head);  
    cout<<"Linked List length: ";
    len(head);
    return 0;
}
