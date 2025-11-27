// 5. Given a linked list, determine whether it contains a loop (cycle) using a hash set.
// A loop exists if some node’s next pointer points to a previous node in the list.
// Input:
// 1 → 2 → 3 → 4 → 2 (back to node 2)
// Output:
// true


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> st;

    while (head) {
        if (st.count(head)) return true;
        st.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    cout << (hasCycle(n1) ? "true" : "false");
}
