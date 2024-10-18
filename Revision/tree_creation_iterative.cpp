#include<iostream>
#include<queue>
using namespace std;
class tree{
    public:
    tree* left;
    tree* right;
    int data;
    tree(int val){
        this->data = val;
        left = right = NULL;
    }
};
int main(){
    int x;
    cout<<"Enter the root node: ";
    cin>>x;
    tree* root = new tree(x);
    queue<tree*> q;
    q.push(root);
    while(!q.empty()){
        tree* temp = q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->data<<": ";
        cin>>x;
        if(x!=-1){
            tree* newnode = new tree(x);
            q.push(newnode);
        }
        cout<<"Enter the right child of "<<temp->data<<": ";
        cin>>x;
        if(x!=-1){
            tree* node = new tree(x);
            q.push(node);
        }
    }
}