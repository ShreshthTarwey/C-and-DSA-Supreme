#include<iostream>
#include<vector>
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
tree* create(tree* root,int data){//T.C-> creation O(n^2), T.C(searching)->O(h),S.C(creation)->O(h);
    if(!root){
        return new tree(data);
    }
    if(data<root->data){
        root->left = create(root->left,data);
    }
    else{
        root->right = create(root->right,data);
    }
    return root;
}
void Inorder(tree* root){
    if(!root){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
bool searching(tree* root,int target){
    if(!root){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(target<root->data){
        return searching(root->left,target);
    }
    else{
        return searching(root->right,target);
    }
}
tree* deleteNode(tree* root,int x){ //TC->O(n)
    //If data is not present
    if(!root){
        return NULL;
    }
    if(root->data==x){
        //Checking for leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        //1 Child exist only
        else if(!root->right){   //For left child
            tree* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left){    //For right child
            tree* temp = root->right;
            delete root;
            return temp;
        }
        else{
            //Find the greatest element form left 
            tree* child = root->left;
            tree* parent = root;
            //left ke rightmost node tak pauchna hai
            while(child->right){
                parent = child;
                child = child->right;
            }
            if(root!=parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else{
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
    else if(root->data>x){
        root->left = deleteNode(root->left,x);
        return root;
    }
    else{
        root->right = deleteNode(root->right,x);
        return root;
    }
}
int h(tree* root){
    int h=0;
    while(1){
        
    }
}
int main(){
    vector<int>arr = {6,3,7,5,11,18,1,14,20,17,2};
    tree* root = NULL;
    for(auto i:arr){
        root = create(root,i);
    }
    // Inorder(root);
    // cout<<searching(root,20);

}