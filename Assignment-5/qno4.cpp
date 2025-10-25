#include <iostream>
using namespace std;

struct Node
{
        int data;
        Node *next;
};

Node *head = nullptr;

void insertAtEnd(int value)
{
        Node *newNode = new Node{value, nullptr};
        if (head == nullptr)
        {
                head = newNode;
        }
        else
        {
                Node *temp = head;
                while (temp->next != nullptr)
                        temp = temp->next;
                temp->next = newNode;
        }
}

void displayList(Node *node)
{
        while (node != nullptr)
        {
                cout << node->data;
                if (node->next != nullptr)
                        cout << "->";
                node = node->next;
        }
        cout << "->NULL" << endl;
}

void reverseList()
{
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
        }
        head = prev;
}

int main()
{
        insertAtEnd(1);
        insertAtEnd(2);
        insertAtEnd(3);
        insertAtEnd(4);

        cout << "Original List: ";
        displayList(head);
        reverseList();
        cout << "Reversed List: ";
        displayList(head);

        return 0;
}
