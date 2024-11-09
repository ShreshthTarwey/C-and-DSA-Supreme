#include<iostream>
#include<queue>
using namespace std;
class tree{
    public:
    tree* left;
    tree* right;
    int data;
    tree(int v) : left(NULL),right(NULL),data(v) {}
};

void Binary(tree*& root){
    queue<tree*> q;
    cout<<"Enter the root node: "<<endl;
    int x;
    cin>>x;
    root = new tree(x);
    q.push(root);
    while(!q.empty()){
        tree* temp = q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->data<<endl;
        cin>>x;
        if(x!=-1){
            temp->left = new tree(x);
            q.push(temp->left);
        }
        cout<<"Enter the right child of "<<temp->data<<endl;
        cin>>x;
        if(x!=-1){
            temp->right = new tree(x);
            q.push(temp->right);
        }
    }
}
void inorder(tree* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int search(tree* root,int x){
    if(!root) return -1;
    if(root->data==x){
        return 1;
    }
    int left = search(root->left,x);
    if(left!=-1){
        return left;
    }
    int right = search(root->right,x);
    return right;

}
int main(){
    tree* root = NULL;
    Binary(root);
    inorder(root);
}