#include<iostream>
#include<queue>
#include<vector>
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
Tree* Binary(){//TC->O(n) //SC for average case->O(h) h-> height of tree For worse case SC->O(n)
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


//All searching techniques have a TC->O(n)



//Way 1
void PreOrder(Tree*temp){
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    PreOrder(temp->left);
    PreOrder(temp->right);
}
//Way 2 
void ProOrder2(Tree* temp){
    
}
void InOrder(Tree* temp){
    if(temp==NULL)
    return;
    InOrder(temp->left);
    cout<<temp->data<<" ";
    InOrder(temp->right);
}
void PostOrder(Tree* temp){
    if(temp==NULL){
        return;
    }
    PostOrder(temp->left);
    PostOrder(temp->right);
    cout<<temp->data<<" ";
}
vector<int> levelWise(Tree* root){
    queue<Tree*> q;
    vector<int> arr;
    q.push(root);
    while(!q.empty()){
        Tree* temp = q.front();
        if(temp!=NULL){
            arr.push_back(temp->data);
        }
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    return arr;
}
int main(){
    cout<<"Enter the root node: "<<endl;
    Tree* root = Binary();
    // cout<<root->left->left->left->data;
    // PreOrder(root);
    // InOrder(root);
    // PostOrder(root);
    vector<int>arr = levelWise(root);
    for(auto i:arr){
        cout<<i<<" ";
    }
}