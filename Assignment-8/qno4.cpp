// 4. Write a program to determine whether a given binary tree is a BST or not

#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node *root, int minV, int maxV)
{
    if (!root)
        return true;
    if (root->key <= minV || root->key >= maxV)
        return false;
    return isBSTUtil(root->left, minV, root->key) &&
           isBSTUtil(root->right, root->key, maxV);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
