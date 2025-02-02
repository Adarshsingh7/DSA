#include <bits/stdc++.h>

using namespace std;

// Structure to represent a node in the binary tree
struct Node {
    Node* left;
    Node* right;
    int data;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int size;

    // Function to find the size of the binary tree
    int findSize(struct Node* root) {
        if(root == nullptr) return 0;
        int leftSize = findSize(root->left);
        int rightSize = findSize(root->right);
        return (1 + leftSize + rightSize);
    }

    // Function to check if the binary tree is complete
    bool check(struct Node* root, int i) {
        if(root == nullptr) return true;
        if(i >= size) return false;

        int leftAns = check(root->left, i*2+1);
        int rightAns = check(root->right, i*2+2);

        return leftAns && rightAns;
    }

    // Function to determine if the binary tree is a complete tree
    bool isCompleteTree(struct Node* root) {
        this->size = findSize(root);
        return check(root, 0);
    }

    // Function to check if the binary tree satisfies the heap property
    bool checkHeap(struct Node* root) {
        if(root == nullptr) return true;
        if(root->left && root->left->data > root->data) return false;
        if(root->right && root->right->data > root->data) return false;

        bool left = checkHeap(root->left);
        bool right = checkHeap(root->right);

        return left && right;
    }

    // Function to determine if the binary tree is a heap
    bool isHeap(struct Node* tree) {
        // we have to check if the tree follows the heap property and if the heap is complete or not
        return isCompleteTree(tree) && checkHeap(tree);
    }
};
