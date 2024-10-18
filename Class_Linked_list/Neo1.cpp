#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to append a node at the end of the linked list
void appendAtEnd(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;
    
    Node* head = nullptr;
    
    // Insert nodes at the beginning
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        insertAtBeginning(head, val);
    }
    
    cout << "Created Linked list: ";
    printList(head);
    
    // Append a new node at the end
    cin >> m;
    appendAtEnd(head, m);
    
    cout << "Final list: ";
    printList(head);
    
    return 0;
}
