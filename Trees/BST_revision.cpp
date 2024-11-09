#include<iostream>
using namespace std;
class tree{
    public:
    tree* left;
    tree* right;
    int data;
    tree(int v) : left(NULL),right(NULL),data(v) {}
};
tree* insert(tree* root,int v){
    if(!root){
        return new tree(v);
    }
    if(root->data>=v){
        root->left = insert(root->left,v);
        return root;
    }
    else{
        root->right  = insert(root->right,v);
        return root;
    }
}
void in(tree* root){
    if(!root) return;
    in(root->left);
    cout<<root->data<<" ";
    in(root->right);
}
bool search(tree* root,int x){
    if(!root) return false;
    if(root->data==x) return true;
    if(x>root->data){
        return search(root->right,x);
    }
    else{
        return search(root->left,x);
    }
}
tree* deletion(tree* root,int x){
    if(!root) return NULL;
    if(root->data==x){
        //Leaf node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //One child
        else if(!root->right){ //Left child exist
            tree* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left){ //Right child exist
            tree* temp = root->right;
            delete root;
            return temp;
        }
        //Both child exist
        else{
            tree* child = root->left;
            tree* parent = root;
            while(child->right){
                parent = child;
                child = child->right;
            }
            if(parent!=root){
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
        root->left = deletion(root->left,x);
        return root;
    }
    else{
        root->right = deletion(root->right,x);
        return root;
    }
}
int main(){
    int arr[]= {2,3,5,66,7,3,44,-9,76};
    int i = 8;
    tree* root = NULL;
    while(i--){
        root = insert(root,arr[i]);
    }
    in(root);
    cout<<endl;
    cout<<search(root,43);
}