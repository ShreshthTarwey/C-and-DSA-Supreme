#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int val){
        this->left = NULL;
        this->right = NULL;
        this->data = val;
    }
};

int main(){
    int val;
    cin>>val;
    Node* root = new Node(val);
    queue<Node*>q;
    q.push(root);
}