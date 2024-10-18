#include<iostream>
#include<vector>
using namespace std;
class Tree{
    public:
    Tree *left;
    // Tree *right;
    int data;
    vector<Tree> children;
    Tree(int val){
        left=NULL;
        // right=NULL;
        this->data = val;
    }
};