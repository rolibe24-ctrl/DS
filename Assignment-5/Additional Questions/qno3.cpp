#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to remove loop in linked list
void removeLoop(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect loop using Floyd’s cycle detection
    bool loopExists = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (!loopExists) return;

    // Step 2: Find the start of the loop
    slow = head;
    if (slow == fast) {
        // Loop starts at head
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Break the loop
    fast->next = nullptr;
}

// Utility function to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list with a loop
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating a loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    cout << "Loop created in linked list." << endl;

    // Remove loop
    removeLoop(head);

    cout << "Linked list after removing loop:" << endl;
    printList(head); // Output: 1 2 3 4 5

    return 0;
}
