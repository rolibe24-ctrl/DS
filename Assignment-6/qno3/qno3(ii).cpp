#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to insert at end
void insertEnd(Node *&head, int data)
{
    Node *newNode = new Node{data, nullptr};
    if (!head)
    {
        head = newNode;
        head->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Function to find size of circular linked list
int getSize(Node *head)
{
    if (!head)
        return 0;

    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Main function
int main()
{
    Node *head = nullptr;

    // Sample input
    insertEnd(head, 5);
    insertEnd(head, 15);
    insertEnd(head, 25);
    insertEnd(head, 35);
    insertEnd(head, 45);

    cout << "Size of Circular Linked List = " << getSize(head) << endl;

    return 0;
}
