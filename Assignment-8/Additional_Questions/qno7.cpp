#include <bits/stdc++.h>
using namespace std;

struct Node
{
        int val;
        Node *left, *right;
        Node(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(Node *root, vector<int> &arr)
{
        if (!root)
                return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size())
        {
                if (a[i] < b[j])
                        res.push_back(a[i++]);
                else
                        res.push_back(b[j++]);
        }
        while (i < a.size())
                res.push_back(a[i++]);
        while (j < b.size())
                res.push_back(b[j++]);

        return res;
}

struct DLLNode
{
        int val;
        DLLNode *prev, *next;
        DLLNode(int x) : val(x), prev(NULL), next(NULL) {}
};

DLLNode *arrayToDLL(vector<int> &arr)
{
        if (arr.empty())
                return NULL;

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *curr = head;

        for (int i = 1; i < arr.size(); i++)
        {
                DLLNode *node = new DLLNode(arr[i]);
                curr->next = node;
                node->prev = curr;
                curr = node;
        }

        return head;
}

void printDLL(DLLNode *head)
{
        while (head)
        {
                cout << head->val;
                if (head->next)
                        cout << " <—> ";
                else
                        cout << " <—> null";
                head = head->next;
        }
        cout << endl;
}

DLLNode *mergeBSTs(Node *root1, Node *root2)
{
        vector<int> a, b;

        inorder(root1, a);
        inorder(root2, b);

        vector<int> merged = mergeArrays(a, b);

        return arrayToDLL(merged);
}

int main()
{

        Node *T1 = new Node(20);
        T1->left = new Node(10);
        T1->right = new Node(30);
        T1->left->left = new Node(25);
        T1->left->right = new Node(100);
        T1->right->right = new Node(50);

        Node *T2 = new Node(5);
        T2->right = new Node(70);

        DLLNode *head = mergeBSTs(T1, T2);

        printDLL(head);

        return 0;
}
