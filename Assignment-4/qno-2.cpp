<<<<<<< HEAD
// 2) Develop a menu driven program demonstrating the following operations on Circular Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
        int arr[SIZE];
        int front, rear;

public:
        CircularQueue()
        {
                front = -1;
                rear = -1;
        }

        bool isEmpty()
        {
                return (front == -1);
        }

        bool isFull()
        {
                return ((rear + 1) % SIZE == front);
        }

        void enqueue(int x)
        {
                if (isFull())
                {
                        cout << "Circular Queue is Full " << x << endl;
                        return;
                }
                if (isEmpty())
                {
                        front = rear = 0;
                }
                else
                {
                        rear = (rear + 1) % SIZE;
                }
                arr[rear] = x;
                cout << x << " is enqueued.\n";
        }

        void dequeue()
        {
                if (isEmpty())
                {
                        cout << "Circular Queue is Empty. Cannot dequeue.\n";
                        return;
                }
                cout << arr[front] << " dequeued from queue.\n";
                if (front == rear)
                {
                        front = rear = -1;
                }
                else
                {
                        front = (front + 1) % SIZE;
                }
        }

        void peek()
        {
                if (isEmpty())
                {
                        cout << "Circular Queue is Empty.\n";
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
                        cout << "Circular Queue is Empty.\n";
                        return;
                }
                cout << "Circular Queue elements: ";
                int i = front;
                while (true)
                {
                        cout << arr[i] << " ";
                        if (i == rear)
                                break;
                        i = (i + 1) % SIZE;
                }
                cout << endl;
        }
};

int main()
{
        CircularQueue cq;
        int choice, value;

        do
        {
                cout << "\n=== Circular Queue Menu ===\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Peek\n";
                cout << "4. Check if Empty\n";
                cout << "5. Check if Full\n";
                cout << "6. Display Queue\n";
                cout << "0. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1)
                {
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        cq.enqueue(value);
                }
                else if (choice == 2)
                {
                        cq.dequeue();
                }
                else if (choice == 3)
                {
                        cq.peek();
                }
                else if (choice == 4)
                {
                        if (cq.isEmpty())
                        {
                                cout << "Queue is Empty.\n";
                        }
                        else
                        {
                                cout << "Queue is NOT Empty.\n";
                        }
                }
                else if (choice == 5)
                {
                        if (cq.isFull())
                        {
                                cout << "Queue is Full.\n";
                        }
                        else
                        {
                                cout << "Queue is NOT Full.\n";
                        }
                }
                else if (choice == 6)
                {
                        cq.display();
                }
                else if (choice == 0)
                {
                        cout << "Exiting program...\n";
                }
                else
                {
                        cout << "Invalid choice!\n";
                }

        } while (choice != 0);

        return 0;
}
=======
// 2) Develop a menu driven program demonstrating the following operations on Circular Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
        int arr[SIZE];
        int front, rear;

public:
        CircularQueue()
        {
                front = -1;
                rear = -1;
        }

        bool isEmpty()
        {
                return (front == -1);
        }

        bool isFull()
        {
                return ((rear + 1) % SIZE == front);
        }

        void enqueue(int x)
        {
                if (isFull())
                {
                        cout << "Circular Queue is Full " << x << endl;
                        return;
                }
                if (isEmpty())
                {
                        front = rear = 0;
                }
                else
                {
                        rear = (rear + 1) % SIZE;
                }
                arr[rear] = x;
                cout << x << " is enqueued.\n";
        }

        void dequeue()
        {
                if (isEmpty())
                {
                        cout << "Circular Queue is Empty. Cannot dequeue.\n";
                        return;
                }
                cout << arr[front] << " dequeued from queue.\n";
                if (front == rear)
                {
                        front = rear = -1;
                }
                else
                {
                        front = (front + 1) % SIZE;
                }
        }

        void peek()
        {
                if (isEmpty())
                {
                        cout << "Circular Queue is Empty.\n";
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
                        cout << "Circular Queue is Empty.\n";
                        return;
                }
                cout << "Circular Queue elements: ";
                int i = front;
                while (true)
                {
                        cout << arr[i] << " ";
                        if (i == rear)
                                break;
                        i = (i + 1) % SIZE;
                }
                cout << endl;
        }
};

int main()
{
        CircularQueue cq;
        int choice, value;

        do
        {
                cout << "\n=== Circular Queue Menu ===\n";
                cout << "1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Peek\n";
                cout << "4. Check if Empty\n";
                cout << "5. Check if Full\n";
                cout << "6. Display Queue\n";
                cout << "0. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1)
                {
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        cq.enqueue(value);
                }
                else if (choice == 2)
                {
                        cq.dequeue();
                }
                else if (choice == 3)
                {
                        cq.peek();
                }
                else if (choice == 4)
                {
                        if (cq.isEmpty())
                        {
                                cout << "Queue is Empty.\n";
                        }
                        else
                        {
                                cout << "Queue is NOT Empty.\n";
                        }
                }
                else if (choice == 5)
                {
                        if (cq.isFull())
                        {
                                cout << "Queue is Full.\n";
                        }
                        else
                        {
                                cout << "Queue is NOT Full.\n";
                        }
                }
                else if (choice == 6)
                {
                        cq.display();
                }
                else if (choice == 0)
                {
                        cout << "Exiting program...\n";
                }
                else
                {
                        cout << "Invalid choice!\n";
                }

        } while (choice != 0);

        return 0;
}
>>>>>>> 03988a83e72c6b53a1eb9a39bb73184765a62d09
