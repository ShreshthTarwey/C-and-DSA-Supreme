#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    
    BST() : root(nullptr) {}
    
    void insert(int val) {
        root = insertRec(root, val);
    }
    
    int sumOfLeafNodes() {
        return sumLeafRec(root);
    }

private:
    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else {
            node->right = insertRec(node->right, val);
        }
        return node;
    }
    
    int sumLeafRec(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return node->data;
        }
        return sumLeafRec(node->left) + sumLeafRec(node->right);
    }
};

int main() {
    BST tree;
    int value;
    
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        tree.insert(value);
    }
    
    cout << "Sum of all leaf nodes are " << tree.sumOfLeafNodes() << endl;
    return 0;
}
