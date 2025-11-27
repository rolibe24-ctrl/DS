#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeHelper(vector<int> &inorder, int inStart, int inEnd,
                          vector<int> &postorder, int postStart, int postEnd,
                          unordered_map<int, int> &inMap)
{

        if (inStart > inEnd || postStart > postEnd)
                return NULL;

        // Last element in postorder is root
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);

        // Find root index in inorder
        int inRoot = inMap[rootVal];
        int numsLeft = inRoot - inStart;

        // Build left and right subtrees
        root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                     postorder, postStart, postStart + numsLeft - 1,
                                     inMap);

        root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                      postorder, postStart + numsLeft, postEnd - 1,
                                      inMap);

        return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
                inMap[inorder[i]] = i;

        return buildTreeHelper(inorder, 0, inorder.size() - 1,
                               postorder, 0, postorder.size() - 1,
                               inMap);
}

void printPreorder(TreeNode *root)
{
        if (!root)
                return;
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
}

int main()
{
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;

        vector<int> inorder(n), postorder(n);

        cout << "Enter inorder traversal: ";
        for (int i = 0; i < n; i++)
                cin >> inorder[i];

        cout << "Enter postorder traversal: ";
        for (int i = 0; i < n; i++)
                cin >> postorder[i];

        TreeNode *root = buildTree(inorder, postorder);

        cout << "Preorder of constructed tree: ";
        printPreorder(root);
}
