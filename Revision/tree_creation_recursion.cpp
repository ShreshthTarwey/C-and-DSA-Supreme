#include<iostream>
using namespace std;
class tree{
    public:
    tree* left;
    tree* right;
    int data;
    tree(int val){
        this->data = val;
        left=right=NULL;
    }
};
tree* Binary(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    tree* temp = new tree(x);
    cout<<"Enter left child for node "<<temp->data<<": ";
    temp->left = Binary();
    cout<<"Enter right child for node "<<temp->data<<": ";
    temp->right = Binary();
    return temp;
}
int main(){
    cout<<"Enter root node for tree: ";
    tree* root = Binary();
}