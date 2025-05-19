#include<iostream>
#include<queue>
using namespace std;
class Tree{
    public:
    Tree* left;
    Tree* right;
    int data;
    Tree(int val) {
        this->left = nullptr;
        this->right = nullptr;
        this->data = val;
    }
};
void Iterative_Approach(Tree* &root)
{
    queue <Tree*> q;
    cout<<"Enter root node of tree: ";
    int x;
    cin>>x;
    root = new Tree(x);
    q.push(root);
    while(!q.empty())
    {
        Tree* current = q.front();
        q.pop();
        cout<<"Enter the left child of tree: ";
        cin>>x;
        if(x!=-1)
        {
            current->left = new Tree(x);
            q.push(current->left);
        }
        cout<<"Enter the right child of tree: ";
        cin>>x;
        if(x!=-1)
        {
            current->right = new Tree(x);
            q.push(current->right);
        }
    }
}
void level_order(Tree* root)
{
    queue<Tree*> q;
    q.push(root);
    while(!q.empty())
    {
        Tree* current = q.front();
        if(current!=NULL)
        {
            cout<<current->data<<" ";
        }
        q.pop();
        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
    }
}
int main()
{
    Tree* root = NULL;
    Iterative_Approach(root);
    level_order(root);
}