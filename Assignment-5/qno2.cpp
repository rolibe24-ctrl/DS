<<<<<<< HEAD
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
                {
                        temp = temp->next;
                }
                temp->next = newNode;
        }
}

void displayList()
{
        if (head == nullptr)
        {
                cout << "List is empty\n";
                return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
                cout << temp->data;
                if (temp->next != nullptr)
                        cout << "->";
                temp = temp->next;
        }
        cout << endl;
}

int countAndDelete(int key)
{
        int count = 0;

        while (head != nullptr && head->data == key)
        {
                Node *temp = head;
                head = head->next;
                delete temp;
                count++;
        }

        Node *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
                if (curr->next->data == key)
                {
                        Node *temp = curr->next;
                        curr->next = curr->next->next;
                        delete temp;
                        count++;
                }
                else
                {
                        curr = curr->next;
                }
        }

        return count;
}

int main()
{
        insertAtEnd(1);
        insertAtEnd(2);
        insertAtEnd(1);
        insertAtEnd(2);
        insertAtEnd(1);
        insertAtEnd(3);
        insertAtEnd(1);

        cout << "Original List: ";
        displayList();

        int key = 1;
        int cnt = countAndDelete(key);

        cout << "Count: " << cnt << endl;
        cout << "Updated List: ";
        displayList();

        return 0;
}
=======
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
                {
                        temp = temp->next;
                }
                temp->next = newNode;
        }
}

void displayList()
{
        if (head == nullptr)
        {
                cout << "List is empty\n";
                return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
                cout << temp->data;
                if (temp->next != nullptr)
                        cout << "->";
                temp = temp->next;
        }
        cout << endl;
}

int countAndDelete(int key)
{
        int count = 0;

        while (head != nullptr && head->data == key)
        {
                Node *temp = head;
                head = head->next;
                delete temp;
                count++;
        }

        Node *curr = head;
        while (curr != nullptr && curr->next != nullptr)
        {
                if (curr->next->data == key)
                {
                        Node *temp = curr->next;
                        curr->next = curr->next->next;
                        delete temp;
                        count++;
                }
                else
                {
                        curr = curr->next;
                }
        }

        return count;
}

int main()
{
        insertAtEnd(1);
        insertAtEnd(2);
        insertAtEnd(1);
        insertAtEnd(2);
        insertAtEnd(1);
        insertAtEnd(3);
        insertAtEnd(1);

        cout << "Original List: ";
        displayList();

        int key = 1;
        int cnt = countAndDelete(key);

        cout << "Count: " << cnt << endl;
        cout << "Updated List: ";
        displayList();

        return 0;
}
>>>>>>> 03988a83e72c6b53a1eb9a39bb73184765a62d09
