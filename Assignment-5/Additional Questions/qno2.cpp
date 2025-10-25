#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse K nodes and return new head
ListNode* reverseKGroup(ListNode* head, int K) {
    ListNode* curr = head;
    int count = 0;

    // Check if there are at least K nodes
    while (curr && count < K) {
        curr = curr->next;
        count++;
    }
    if (count < K) return head; // less than K nodes, do not reverse

    // Reverse K nodes
    ListNode* prev = nullptr;
    curr = head;
    ListNode* next = nullptr;
    count = 0;

    while (curr && count < K) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // head now is the tail of reversed group
    head->next = reverseKGroup(curr, K);

    return prev; // new head of reversed group
}

// Utility to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1->2->3->4->5->6->7->8->9
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= 9; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    int K = 3;
    head = reverseKGroup(head, K);
    printList(head); // Output: 3->2->1->6->5->4->9->8->7

    return 0;
}
