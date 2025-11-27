// 6. You are given a binary tree (not a binary search tree). Write a program to check if
// the tree contains any duplicate node values using hash set.
// Your task is to:
// 1. Return true (or print "Duplicates Found") if there exists at least one duplicate value.
// 2. Otherwise, return false (or print "No Duplicates").


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkDuplicates(TreeNode* root, unordered_set<int>& st) {
    if (!root) return false;

    if (st.count(root->val)) return true;
    st.insert(root->val);

    return checkDuplicates(root->left, st) ||
           checkDuplicates(root->right, st);
}

bool hasDuplicate(TreeNode* root) {
    unordered_set<int> st;
    return checkDuplicates(root, st);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(10); 

    cout << (hasDuplicate(root) ? "Duplicates Found" : "No Duplicates");
}
