// Develop a menu driven program demonstrating the following operations on simple
// Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

#define SIZE 10

class Queue
{
        int arr[SIZE];
        int front, rear;

public:
        Queue()
        {
                front = -1;
                rear = -1;
        }

        bool isEmpty()
        {
                return (front == -1 && rear == -1);
        }

        bool isFull()
        {
                return (rear == SIZE - 1);
        }

        void enqueue(int x)
        {
                if (isFull())
                {
                        cout << "Queue is Full \n";
                        return;
                }
                if (isEmpty())
                {
                        front = 0;
                        rear = 0;
                }
                else
                {
                        rear++;
                }
                arr[rear] = x;
                cout << x << " is enqueued \n";
        }

        void dequeue()
        {
                if (isEmpty())
                {
                        cout << "Queue is Empty \n";
                        return;
                }
                cout << arr[front] << "dequeued \n";
                if (front == rear)
                {
                        front = rear = -1;
                }
                else
                {
                        front += 1;
                }
        }

        void peek()
        {
                if (isEmpty())
                {
                        cout << "Queue is Empty.\n";
                }
                else
                {
                        cout << "Front element is: " << arr[front] << endl;
                }
        }

        void display()
        {
                if (isEmpty())
                {
                        cout << "Queue is Empty.\n";
                        return;
                }
                cout << "Queue elements: ";
                for (int i = front; i <= rear; i++)
                {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
};

int main()
{
        Queue q;
        int choice, value;

        do
        {
                cout << "\n=== Menu ===\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Peek\n";
                cout << "4. Check if Empty\n";
                cout << "5. Check if Full\n";
                cout << "6. Display Queue\n";
                cout << "0. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        q.enqueue(value);
                        break;

                case 2:
                        q.dequeue();
                        break;

                case 3:
                        q.peek();
                        break;

                case 4:
                        if (q.isEmpty())
                        {
                                cout << "Queue is Empty.\n";
                        }
                        else
                        {
                                cout << "Queue is not Empty.\n";
                        }
                        break;

                case 5:
                        if (q.isFull())
                        {
                                cout << "Queue is Full.\n";
                        }
                        else
                        {
                                cout << "Queue is not Full.\n";
                        }
                        break;

                case 6:
                        q.display();
                        break;

                case 0:
                        cout << "Exiting program \n";
                        break;

                default:
                        cout << "Invalid choice \n";
                }
        } while (choice != 0);

        return 0;
}
