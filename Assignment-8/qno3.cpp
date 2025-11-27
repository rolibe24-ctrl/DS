// 3. Write a program for binary search tree (BST) having functions for the following
// operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of

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

Node *minNode(Node *root)
{
        while (root->left)
                root = root->left;
        return root;
}

Node *deleteNode(Node *root, int key)
{
        if (!root)
                return root;

        if (key < root->key)
                root->left = deleteNode(root->left, key);
        else if (key > root->key)
                root->right = deleteNode(root->right, key);
        else
        {
                if (!root->left)
                {
                        Node *temp = root->right;
                        delete root;
                        return temp;
                }
                else if (!root->right)
                {
                        Node *temp = root->left;
                        delete root;
                        return temp;
                }

                Node *temp = minNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
        }
        return root;
}

int maxDepth(Node *root)
{
        if (!root)
                return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int minDepth(Node *root)
{
        if (!root)
                return 0;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main()
{
        Node *root = NULL;
        int arr[] = {30, 20, 40, 10, 25, 35, 50};
        for (int x : arr)
                root = insert(root, x);

        root = deleteNode(root, 20);

        cout << "Max Depth: " << maxDepth(root) << endl;
        cout << "Min Depth: " << minDepth(root) << endl;
}
