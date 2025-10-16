#include<iostream>
using namespace std;

class AvlTree{
    public:
    int data;
    AvlTree* left;
    AvlTree* right;
    int height;
    AvlTree(int n){
        this->left = NULL;
        this->right = NULL;
        this->data = n;
        this->height = 1;
    }
};
int height(AvlTree* root){
    return root ? root->height : 0;
}
AvlTree* tree_Creation(AvlTree* root, int d){
    if(!root){
        return new AvlTree(d);
    }
    if(root->data<=d){
        root->right = tree_Creation(root->right,d);
    }
    else{
        root->left = tree_Creation(root->left,d);
    }
    root->height = 1+ max(height(root->left),height(root->right));
    return Avl_Balencing(root);
}
int BF(AvlTree* root){
    int bf = height(root->left) - height(root->right);
    return bf;
}
AvlTree* leftRotate(AvlTree* x){
    AvlTree* y = x->right;
    AvlTree* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left),height(x->right));
    y->height = 1+ max(height(y->right),height(y->left));
    return y;
}
AvlTree* rightRotate(AvlTree* x){
    AvlTree* y = x->left;
    AvlTree* T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = 1 + max(height(x->left),height(x->right));
    y->height = 1 + max(height(y->left),height(y->right));

    return y;
}
AvlTree* Avl_Balencing(AvlTree* root){
    int bf = BF(root);
     // Left-Left (LL)
    if(bf > 1 && BF(root->left) >= 0){
        return rightRotate(root);
    }

    // Left-Right (LR)
    if(bf > 1 && BF(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Right (RR)
    if(bf < -1 && BF(root->right) <= 0){
        return leftRotate(root);
    }

    // Right-Left (RL)
    if(bf < -1 && BF(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Already balanced
    return root;
}
int main(){

}

