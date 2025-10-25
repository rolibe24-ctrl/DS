#include <bits/stdc++.h>

using namespace std;

struct Node
{
        int data;
        Node *prev, *next;
};

// Function to insert a node at the beginning

void push(Node **head_ref, int new_data)
{

        Node *new_node = (Node *)malloc(sizeof(struct Node));

        new_node->data = new_data;

        new_node->prev = NULL;

        // Link the old list of the new node
        new_node->next = (*head_ref);

        if ((*head_ref) != NULL)
                (*head_ref)->prev = new_node;

        (*head_ref) = new_node;
}

// Function that returns true if count
// of set bits in x is even
bool isEvenParity(int x)
{
        // parity will store the
        // count of set bits
        int parity = 0;
        while (x != 0)
        {
                if (x & 1)
                        parity++;
                x = x >> 1;
        }

        if (parity % 2 == 0)
                return true;
        else
                return false;
}


void deleteNode(Node **head_ref, Node *del)
{
        // Base case
        if (*head_ref == NULL || del == NULL)
                return;

        // If the node to be
        // deleted is head node
        if (*head_ref == del)
                *head_ref = del->next;

        // Change next only if node to be
        // deleted is not the last node
        if (del->next != NULL)
                del->next->prev = del->prev;

        // Change prev only if node to be
        // deleted is not the first node
        if (del->prev != NULL)
                del->prev->next = del->next;
        free(del);

        return;
}

void deleteEvenParityNodes(
    Node **head_ref)
{
        Node *ptr = *head_ref;
        Node *next;

        while (ptr != NULL)
        {
                next = ptr->next;
                if (isEvenParity(ptr->data))
                        deleteNode(head_ref, ptr);

                ptr = next;
        }
}

void printList(Node *head)
{
        if (head == NULL)
        {
                cout << "Empty list\n";
                return;
        }

        while (head != NULL)
        {
                cout << head->data << " ";
                head = head->next;
        }
}

// Driver Code
int main()
{

        Node *head = NULL;


        push(&head, 14);
        push(&head, 9);
        push(&head, 8);
        push(&head, 15);
        push(&head, 18);

        // cout << "Original List: ";
        // printList(head);

        deleteEvenParityNodes(&head);

        // Modified List
        printList(head);
}