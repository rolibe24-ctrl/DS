#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *headDoubly = nullptr;
Node *headCircular = nullptr;

// ======== Doubly Linked List Functions ========

// Insert at end in Doubly Linked List
void insertDoubly(int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};
    if (!headDoubly)
    {
        headDoubly = newNode;
    }
    else
    {
        Node *temp = headDoubly;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Inserted " << data << " into Doubly Linked List.\n";
}

// Delete a node from Doubly Linked List
void deleteDoubly(int key)
{
    if (!headDoubly)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = headDoubly;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp)
    {
        cout << "Node not found.\n";
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        headDoubly = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
    cout << "Deleted " << key << " from Doubly Linked List.\n";
}

// Search in Doubly Linked List
void searchDoubly(int key)
{
    Node *temp = headDoubly;
    int pos = 1;
    while (temp)
    {
        if (temp->data == key)
        {
            cout << "Found " << key << " at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found.\n";
}

// Display Doubly Linked List
void displayDoubly()
{
    Node *temp = headDoubly;
    if (!temp)
    {
        cout << "List is empty.\n";
        return;
    }
    cout << "Doubly Linked List: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// ======== Circular Doubly Linked List Functions ========

// Insert at end in Circular Doubly Linked List
void insertCircular(int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};
    if (!headCircular)
    {
        headCircular = newNode;
        newNode->next = newNode->prev = newNode;
    }
    else
    {
        Node *last = headCircular->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = headCircular;
        headCircular->prev = newNode;
    }
    cout << "Inserted " << data << " into Circular Doubly Linked List.\n";
}

// Delete a node from Circular Doubly Linked List
void deleteCircular(int key)
{
    if (!headCircular)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = headCircular;
    Node *toDelete = nullptr;

    do
    {
        if (temp->data == key)
        {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != headCircular);

    if (!toDelete)
    {
        cout << "Node not found.\n";
        return;
    }

    if (toDelete->next == toDelete)
    {
        headCircular = nullptr;
    }
    else
    {
        Node *prevNode = toDelete->prev;
        Node *nextNode = toDelete->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        if (toDelete == headCircular)
            headCircular = nextNode;
    }

    delete toDelete;
    cout << "Deleted " << key << " from Circular Doubly Linked List.\n";
}

// Search in Circular Doubly Linked List
void searchCircular(int key)
{
    if (!headCircular)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = headCircular;
    int pos = 1;
    do
    {
        if (temp->data == key)
        {
            cout << "Found " << key << " at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != headCircular);

    cout << "Node not found.\n";
}

// Display Circular Doubly Linked List
void displayCircular()
{
    if (!headCircular)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = headCircular;
    cout << "Circular Doubly Linked List: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != headCircular);
    cout << "\n";
}

// ======== Main Menu ========

int main()
{
    int mainChoice, choice, data, key;

    while (true)
    {
        cout << "\n=============================\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Doubly Linked List\n";
        cout << "3. Exit\n";
        cout << "Choose list type: ";
        cin >> mainChoice;

        if (mainChoice == 3)
        {
            cout << "Exiting program...\n";
            break;
        }

        while (true)
        {
            cout << "\n--- Operations Menu ---\n";
            cout << "1. Insert\n";
            cout << "2. Delete\n";
            cout << "3. Search\n";
            cout << "4. Display\n";
            cout << "5. Go Back\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 5)
                break;

            cout << "\n";

            switch (choice)
            {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                if (mainChoice == 1)
                    insertDoubly(data);
                else
                    insertCircular(data);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> key;
                if (mainChoice == 1)
                    deleteDoubly(key);
                else
                    deleteCircular(key);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> key;
                if (mainChoice == 1)
                    searchDoubly(key);
                else
                    searchCircular(key);
                break;

            case 4:
                if (mainChoice == 1)
                    displayDoubly();
                else
                    displayCircular();
                break;

            default:
                cout << "Invalid choice.\n";
            }
        }
    }
    return 0;
}
