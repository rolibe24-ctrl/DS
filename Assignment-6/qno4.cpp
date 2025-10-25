#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node
{
        char data;
        Node *next;
        Node *prev;
};

// Function to create a new node
Node *createNode(char data)
{
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
}

// Function to insert node at the end
void insertEnd(Node **head, char data)
{
        Node *newNode = createNode(data);
        if (*head == NULL)
        {
                *head = newNode;
                return;
        }
        Node *temp = *head;
        while (temp->next != NULL)
                temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
}

// Function to check if DLL is palindrome
bool isPalindrome(Node *head)
{
        if (head == NULL)
                return true;

        Node *left = head;
        Node *right = head;

        // Move right to the end of list
        while (right->next != NULL)
                right = right->next;

        // Compare from both ends
        while (left != right && right->next != left)
        {
                if (left->data != right->data)
                        return false;
                left = left->next;
                right = right->prev;
        }
        return true;
}

int main()
{
        Node *head = NULL;
        string str;
        cout << "Enter characters (no spaces): ";
        cin >> str;

        for (char c : str)
                insertEnd(&head, c);

        if (isPalindrome(head))
                cout << "The doubly linked list is a palindrome.";
        else
                cout << "The doubly linked list is not a palindrome.";

        return 0;
}
