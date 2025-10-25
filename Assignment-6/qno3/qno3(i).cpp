#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Function to insert at end
void insertEnd(Node *&head, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to find size of doubly linked list
int getSize(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function
int main()
{
    Node *head = nullptr;

    // Sample input
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Size of Doubly Linked List = " << getSize(head) << endl;

    return 0;
}
