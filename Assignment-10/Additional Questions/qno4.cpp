#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

Node* insert(Node* head, int x) {
    Node* n = new Node(x);
    n->next = head;
    return n;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node* getUnion(Node* head1, Node* head2) {
    unordered_set<int> s;
    Node* res = NULL;

    for (Node* t = head1; t; t = t->next)
        s.insert(t->data);

    for (Node* t = head2; t; t = t->next)
        s.insert(t->data);

    for (int x : s)
        res = insert(res, x);

    return res;
}

Node* getIntersection(Node* head1, Node* head2) {
    unordered_set<int> s;
    Node* res = NULL;

    for (Node* t = head1; t; t = t->next)
        s.insert(t->data);

    for (Node* t = head2; t; t = t->next)
        if (s.count(t->data))
            res = insert(res, t->data);

    return res;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    head1 = insert(head1, 20);
    head1 = insert(head1, 4);
    head1 = insert(head1, 15);
    head1 = insert(head1, 10);

    head2 = insert(head2, 10);
    head2 = insert(head2, 2);
    head2 = insert(head2, 4);
    head2 = insert(head2, 8);

    cout << "Intersection List: ";
    printList(getIntersection(head1, head2));

    cout << "Union List: ";
    printList(getUnion(head1, head2));
}
