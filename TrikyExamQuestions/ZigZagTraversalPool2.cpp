#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    Tree *left;
    Tree *right;
    int val;
    Tree(int val)
    {
        (*this).val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
bool flag = false;
void zigzagPrint(Tree *root)
{
    vector<int> ans;
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree *front = q.front();
        int levelSize = q.size();
        vector<int> temp;
        int count = 0;
        while (count < levelSize)
        {
            temp.push_back(q.front()->val);
            Tree *temp2 = q.front();
            if (temp2->left)
                q.push(temp2->left);
            if (temp2->right)
                q.push(temp2->right);
            q.pop();
            count++;
        }
        // Defult -> Right left
        if (flag)
        {
            ans.insert(ans.end(),temp.rbegin(), temp.rend());
        }
        else
        {
            ans.insert(ans.end(),temp.begin(), temp.end());
        }
        flag = !flag;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    int c;
    cin >> c;
    Tree *root = new Tree(c);
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree *front = q.front();
        q.pop();
        cin >> c;
        if (c != -1)
        {
            Tree *leftNode = new Tree(c);
            front->left = leftNode;
            q.push(leftNode);
        }
        cin >> c;
        if (c != -1)
        {
            Tree *rightNode = new Tree(c);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    zigzagPrint(root);
}