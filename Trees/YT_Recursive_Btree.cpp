#include<iostream>
using namespace std;
class Tree{
    public:
    Tree* left;
    Tree* right;
    int data;
    Tree(int val){
        this->left = NULL;
        this->right = NULL;
        this->data = val;
    }
};
Tree* Binary(){//TC->O(n) //SC for average case->O(h) h-> height of tree For worse case SC->O(h)
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Tree* temp = new Tree(x);
    cout<<"Enter the left for "<<temp->data<<endl;
    temp->left = Binary();
    cout<<"Enter the right for "<<temp->data<<endl;
    temp->right = Binary();
    return temp;
}
int main(){
    cout<<"Enter the root node: "<<endl;
    Tree* root = Binary();
    cout<<root->left->left->left->data;
}