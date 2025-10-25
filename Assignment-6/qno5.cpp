#include <iostream>
using namespace std;

struct Node
{
        int data;
        Node *next;
};

// Function to create a new node
Node *createNode(int data)
{
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
}

// Function to check if linked list is circular
bool isCircular(Node *head)
{
        if (head == NULL)
                return false;

        Node *temp = head->next;

        // Traverse the list
        while (temp != NULL && temp != head)
                temp = temp->next;

        return (temp == head);
}

// Driver code
int main()
{
        // Create nodes
        Node *head = createNode(1);
        Node *second = createNode(2);
        Node *third = createNode(3);
        Node *fourth = createNode(4);

        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = head;

        // Check if circular
        if (isCircular(head))
                cout << "The linked list is circular.";
        else
                cout << "The linked list is not circular.";

        return 0;
}
