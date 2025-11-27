#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                          vector<int> &inorder, int inStart, int inEnd,
                          unordered_map<int, int> &inMap)
{

        if (preStart > preEnd || inStart > inEnd)
                return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int leftTreeSize = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize,
                                     inorder, inStart, inRoot - 1, inMap);

        root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd,
                                      inorder, inRoot + 1, inEnd, inMap);

        return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
                inMap[inorder[i]] = i;

        return buildTreeHelper(preorder, 0, preorder.size() - 1,
                               inorder, 0, inorder.size() - 1, inMap);
}

void printInorder(TreeNode *root)
{
        if (!root)
                return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
}

int main()
{
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;

        vector<int> preorder(n), inorder(n);

        cout << "Enter preorder traversal: ";
        for (int i = 0; i < n; i++)
                cin >> preorder[i];

        cout << "Enter inorder traversal: ";
        for (int i = 0; i < n; i++)
                cin >> inorder[i];

        TreeNode *root = buildTree(preorder, inorder);

        cout << "Constructed tree inorder (should match input inorder): ";
        printInorder(root);
}
