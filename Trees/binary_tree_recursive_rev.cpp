#include<iostream>
using namespace std;
class tree{
    public:
    tree* left;
    tree* right;
    int data;
    tree(int v) : left(NULL),right(NULL),data(v) {}
};
tree* Binary(tree* root){
    int x;
    cin>>x;
    if(x==-1) return NULL;
    tree* temp = new tree(x);
    cout<<"Enter the value of left child of "<<temp->data<<endl;
    root->left = Binary(root->left);
    cout<<"Enter the value of right child of "<<temp->data<<endl;
    root->right = Binary(root->right);
    return temp;
}
int main(){
  tree* root = NULL;
  root = Binary(root);  
}