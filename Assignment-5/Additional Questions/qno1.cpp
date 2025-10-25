#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;

    // If either is null
    if (!a || !b) return nullptr;

    // Traverse both lists; if pointer reaches end, switch to the other list
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }

    return a; // either intersection node or nullptr
}

int main() {
    // Example setup
    ListNode* intersect = new ListNode(8);

    ListNode* listA = new ListNode(4);
    listA->next = new ListNode(1);
    listA->next->next = intersect;
    intersect->next = new ListNode(5);

    ListNode* listB = new ListNode(5);
    listB->next = new ListNode(6);
    listB->next->next = intersect;

    ListNode* ans = getIntersectionNode(listA, listB);
    if (ans)
        cout << "Intersected at " << ans->val << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
