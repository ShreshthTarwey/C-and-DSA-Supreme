#include<iostream>
#include<queue>
using namespace std;
class Tree{
    public:
    Tree* left;
    Tree* right;
    int data;
    Tree(int val){
        this->data = val;
        left=right=NULL;
    }
};
void in(Tree* root){
    if(!root){
        return;
    }
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}
int main(){
    queue<Tree*> q;
    int x;
    cin>>x;
    Tree* root = new Tree(x);
    q.push(root);
    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();
        cout<<"Enter left child for: "<<temp->data<<endl;
        cin>>x;
        if(x!=-1){
            temp->left = new Tree(x);
            q.push(temp->left);
        }
        cout<<"Enter right child for: "<<temp->data<<endl;
        cin>>x;
        if(x!=-1){
            temp->right = new Tree(x);
            q.push(temp->right);
        }
    }
    in(root);
}