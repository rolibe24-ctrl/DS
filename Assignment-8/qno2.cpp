// 2. Implement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST

#include <iostream>
using namespace std;

struct Node
{
        int key;
        Node *left, *right;
        Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int key)
{
        if (!root)
                return new Node(key);
        if (key < root->key)
                root->left = insert(root->left, key);
        else if (key > root->key)
                root->right = insert(root->right, key);
        return root;
}

/* Recursive Search */
Node *searchRec(Node *root, int key)
{
        if (!root || root->key == key)
                return root;
        if (key < root->key)
                return searchRec(root->left, key);
        return searchRec(root->right, key);
}

/* Non-Recursive Search */
Node *searchNonRec(Node *root, int key)
{
        while (root && root->key != key)
        {
                if (key < root->key)
                        root = root->left;
                else
                        root = root->right;
        }
        return root;
}

/* Minimum element */
Node *minNode(Node *root)
{
        while (root->left)
                root = root->left;
        return root;
}

/* Maximum element */
Node *maxNode(Node *root)
{
        while (root->right)
                root = root->right;
        return root;
}

/* Inorder Successor */
Node *inorderSuccessor(Node *root, Node *node)
{
        if (node->right)
                return minNode(node->right);

        Node *succ = NULL;
        while (root)
        {
                if (node->key < root->key)
                {
                        succ = root;
                        root = root->left;
                }
                else
                        root = root->right;
        }
        return succ;
}

/* Inorder Predecessor */
Node *inorderPredecessor(Node *root, Node *node)
{
        if (node->left)
                return maxNode(node->left);

        Node *pred = NULL;
        while (root)
        {
                if (node->key > root->key)
                {
                        pred = root;
                        root = root->right;
                }
                else
                        root = root->left;
        }
        return pred;
}

int main()
{
        Node *root = NULL;
        int arr[] = {20, 10, 5, 15, 30, 25, 40};
        for (int x : arr)
                root = insert(root, x);

        Node *temp = searchRec(root, 15);

        cout << "Min: " << minNode(root)->key << endl;
        cout << "Max: " << maxNode(root)->key << endl;
        cout << "Successor of 15: " << inorderSuccessor(root, temp)->key << endl;
        cout << "Predecessor of 15: " << inorderPredecessor(root, temp)->key << endl;
}
