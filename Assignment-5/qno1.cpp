#include <iostream>
using namespace std;

struct Node
{
        int data;
        Node *next;
};

Node *head = nullptr;

void insertAtBeginning(int value)
{
        Node *newNode = new Node{value, head};
        head = newNode;
        cout << value << " inserted at beginning.\n";
}

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
        cout << value << " inserted at end.\n";
}

void insertBefore(int target, int value)
{
        if (head == nullptr)
        {
                cout << "List is empty.\n";
                return;
        }
        if (head->data == target)
        {
                insertAtBeginning(value);
                return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != target)
        {
                temp = temp->next;
        }
        if (temp->next == nullptr)
        {
                cout << "Node " << target << " not found.\n";
                return;
        }
        Node *newNode = new Node{value, temp->next};
        temp->next = newNode;
        cout << value << " inserted before " << target << ".\n";
}

void insertAfter(int target, int value)
{
        Node *temp = head;
        while (temp != nullptr && temp->data != target)
        {
                temp = temp->next;
        }
        if (temp == nullptr)
        {
                cout << "Node " << target << " not found.\n";
                return;
        }
        Node *newNode = new Node{value, temp->next};
        temp->next = newNode;
        cout << value << " inserted after " << target << ".\n";
}

void deleteFromBeginning()
{
        if (head == nullptr)
        {
                cout << "List is empty.\n";
                return;
        }
        Node *temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
}

void deleteFromEnd()
{
        if (head == nullptr)
        {
                cout << "List is empty.\n";
                return;
        }
        if (head->next == nullptr)
        {
                cout << head->data << " deleted from end.\n";
                delete head;
                head = nullptr;
                return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
                temp = temp->next;
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
}

void deleteNode(int target)
{
        if (head == nullptr)
        {
                cout << "List is empty.\n";
                return;
        }
        if (head->data == target)
        {
                Node *temp = head;
                head = head->next;
                delete temp;
                cout << "Node " << target << " deleted.\n";
                return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != target)
        {
                temp = temp->next;
        }
        if (temp->next == nullptr)
        {
                cout << "Node " << target << " not found.\n";
                return;
        }
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Node " << target << " deleted.\n";
        delete toDelete;
}

void searchNode(int target)
{
        Node *temp = head;
        int pos = 1;
        while (temp != nullptr)
        {
                if (temp->data == target)
                {
                        cout << "Node " << target << " found at position " << pos << ".\n";
                        return;
                }
                temp = temp->next;
                pos++;
        }
        cout << "Node " << target << " not found.\n";
}

void displayList()
{
        if (head == nullptr)
        {
                cout << "List is empty.\n";
                return;
        }
        Node *temp = head;
        cout << "List: ";
        while (temp != nullptr)
        {
                cout << temp->data;
                if (temp->next != nullptr)
                        cout << "->";
                temp = temp->next;
        }
        cout << endl;
}

int main()
{
        int choice, value, target;

        do
        {
                cout << "\n=== Singly Linked List Menu ===\n";
                cout << "1. Insert at Beginning\n";
                cout << "2. Insert at End\n";
                cout << "3. Insert Before a Node\n";
                cout << "4. Insert After a Node\n";
                cout << "5. Delete from Beginning\n";
                cout << "6. Delete from End\n";
                cout << "7. Delete Specific Node\n";
                cout << "8. Search Node\n";
                cout << "9. Display List\n";
                cout << "0. Exit\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1)
                {
                        cout << "Enter value: ";
                        cin >> value;
                        insertAtBeginning(value);
                }
                else if (choice == 2)
                {
                        cout << "Enter value: ";
                        cin >> value;
                        insertAtEnd(value);
                }
                else if (choice == 3)
                {
                        cout << "Enter target node value: ";
                        cin >> target;
                        cout << "Enter new value: ";
                        cin >> value;
                        insertBefore(target, value);
                }
                else if (choice == 4)
                {
                        cout << "Enter target node value: ";
                        cin >> target;
                        cout << "Enter new value: ";
                        cin >> value;
                        insertAfter(target, value);
                }
                else if (choice == 5)
                {
                        deleteFromBeginning();
                }
                else if (choice == 6)
                {
                        deleteFromEnd();
                }
                else if (choice == 7)
                {
                        cout << "Enter node value to delete: ";
                        cin >> target;
                        deleteNode(target);
                }
                else if (choice == 8)
                {
                        cout << "Enter value to search: ";
                        cin >> target;
                        searchNode(target);
                }
                else if (choice == 9)
                {
                        displayList();
                }
                else if (choice == 0)
                {
                        cout << "Exiting program...\n";
                }
                else
                {
                        cout << "Invalid choice! Try again.\n";
                }

        } while (choice != 0);

        return 0;
}
