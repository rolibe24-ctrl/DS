#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(const vector<int> &arr)
{
        if (arr.empty() || arr[0] == -1)
                return NULL;

        TreeNode *root = new TreeNode(arr[0]);
        queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (i < arr.size())
        {
                TreeNode *curr = q.front();
                q.pop();

                if (i < arr.size() && arr[i] != -1)
                {
                        curr->left = new TreeNode(arr[i]);
                        q.push(curr->left);
                }
                i++;

                if (i < arr.size() && arr[i] != -1)
                {
                        curr->right = new TreeNode(arr[i]);
                        q.push(curr->right);
                }
                i++;
        }

        return root;
}

vector<int> rightView(TreeNode *root)
{
        vector<int> result;
        if (!root)
                return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
                int size = q.size();
                TreeNode *node = NULL;

                for (int i = 0; i < size; i++)
                {
                        node = q.front();
                        q.pop();

                        if (node->left)
                                q.push(node->left);
                        if (node->right)
                                q.push(node->right);
                }

                result.push_back(node->val);
        }

        return result;
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin >> T;

        while (T--)
        {
                int n;
                cin >> n;

                vector<int> arr(n);
                for (int i = 0; i < n; i++)
                        cin >> arr[i];

                TreeNode *root = buildTree(arr);
                vector<int> view = rightView(root);

                for (int x : view)
                        cout << x << " ";
                cout << "\n";
        }

        return 0;
}
