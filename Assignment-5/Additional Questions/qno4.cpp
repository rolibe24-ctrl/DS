#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

Node *rotate(Node *head, int k) {

    if (k == 0 || head == nullptr)
        return head;

    Node *curr = head;
    int len = 1;
  
  	// find the length of linked list
    while (curr->next != nullptr) {
        curr = curr->next;
        len += 1;
    }

  	// modulo k with length of linked list to handle
  	// large values of k
    k %= len;
  
    if (k == 0)
        return head;
  
  	// make the linked list circular
    curr->next = head;

  	// traverse the linked list to find the kth node
    curr = head;
    for (int i = 1; i < k; i++)
        curr = curr->next;

  	// update the (k + 1)th node as the new head
    head = curr->next;
  
  	// break the loop by updating next pointer of kth node
    curr->next = nullptr;
    return head;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        if(node->next != NULL){
            cout << "-> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main() {

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
  
    head = rotate(head, 6);
    printList(head);
    return 0;
}