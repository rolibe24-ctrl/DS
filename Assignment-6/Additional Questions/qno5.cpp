// C++ program to construct a Doubly
// linked linked list from 2D Matrix

#include <iostream>
using namespace std;

// define dimension of matrix
#define dim 3


struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
};

// function to create a new node
Node* createNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    temp->up = NULL;
    temp->down = NULL;
    return temp;
}

// function to construct the
// doubly linked list
Node* constructDoublyListUtil(
    int mtrx[][dim],
    int i, int j,
    Node* curr)
{

    if (i >= dim || j >= dim) {
        return NULL;
    }

    Node* temp = createNode(mtrx[i][j]);


    temp->prev = curr;

    temp->up = curr;

    // Recursive call for next pointer
    temp->next
        = constructDoublyListUtil(
            mtrx, i, j + 1, temp);

    // Recursive call for down pointer
    temp->down
        = constructDoublyListUtil(
            mtrx, i + 1, j, temp);

    return temp;
}

// Function to construct the doubly linked list
Node* constructDoublyList(int mtrx[][dim])
{
    return constructDoublyListUtil(
        mtrx, 0, 0, NULL);
}

// function for displaying
// doubly linked list data
void display(Node* head)
{

    Node* rPtr;


    Node* dPtr = head;

    // loop till node->down is not NULL
    while (dPtr) {

        rPtr = dPtr;

        // loop till node->right is not NULL
        while (rPtr) {
            cout << rPtr->data << " ";
            rPtr = rPtr->next;
        }

        cout << "\n";
        dPtr = dPtr->down;
    }
}

// driver code
int main()
{

    // initialise matrix
    int mtrx[dim][dim] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    Node* list = constructDoublyList(mtrx);

    display(list);

    return 0;
}