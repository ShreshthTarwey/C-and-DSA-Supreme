#include <iostream>
#include <queue>
using namespace std;

class tree {
public:
    tree* left;
    tree* right;
    char data;

    tree(char val) {
        this->left = NULL;
        this->right = NULL;
        this->data = val;
    }
};

void pre_order(tree* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void Iterative_Creation(tree*& root) {
    char x;
    cout << "Enter root data: ";
    cin >> x;

    if (x == '$') return;  

    queue<tree*> q;
    root = new tree(x);
    q.push(root);

    while (!q.empty()) {
        tree* current = q.front();
        q.pop();

        cout << "Enter left data of " << current->data << ": ";
        cin >> x;
        if (x != '$') {
            current->left = new tree(x);
            q.push(current->left);
        }

        cout << "Enter right data of " << current->data << ": ";
        cin >> x;
        if (x != '$') {
            current->right = new tree(x);
            q.push(current->right);
        }
    }
}

int main() {
    tree* root = NULL;
    Iterative_Creation(root);

    cout << "Preorder Traversal: ";
    pre_order(root);
    cout << endl;
    return 0;
}
