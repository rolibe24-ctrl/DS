#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
        vector<TreeNode *> generateTrees(int n)
        {
                if (n == 0)
                        return {};
                return build(1, n);
        }

private:
        vector<TreeNode *> build(int start, int end)
        {
                vector<TreeNode *> trees;

                // Base case: empty tree
                if (start > end)
                {
                        trees.push_back(NULL);
                        return trees;
                }

                // Pick each number as root
                for (int i = start; i <= end; i++)
                {

                        // Generate all left & right subtree combinations
                        vector<TreeNode *> leftTrees = build(start, i - 1);
                        vector<TreeNode *> rightTrees = build(i + 1, end);

                        // Combine left and right trees with root i
                        for (TreeNode *left : leftTrees)
                        {
                                for (TreeNode *right : rightTrees)
                                {
                                        TreeNode *root = new TreeNode(i);
                                        root->left = left;
                                        root->right = right;
                                        trees.push_back(root);
                                }
                        }
                }
                return trees;
        }
};
