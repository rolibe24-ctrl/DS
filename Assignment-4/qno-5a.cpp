// 5) Write a program to implement a stack using
// (a) Two queues


#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues
{
        queue<int> q1, q2;

public:
        void push(int x)
        {
                q1.push(x);
                cout << x << " pushed to stack\n";
        }

        void pop()
        {
                if (q1.empty())
                {
                        cout << "Stack is Empty\n";
                        return;
                }

                while (q1.size() > 1)
                {
                        q2.push(q1.front());
                        q1.pop();
                }
                cout << q1.front() << " popped from stack\n";
                q1.pop();

                swap(q1, q2);
        }

        void top()
        {
                if (q1.empty())
                {
                        cout << "Stack is Empty\n";
                        return;
                }

                while (q1.size() > 1)
                {
                        q2.push(q1.front());
                        q1.pop();
                }
                cout << "Top element: " << q1.front() << endl;

                int last = q1.front();
                q2.push(last);
                q1.pop();

                swap(q1, q2);
        }

        bool isEmpty()
        {
                return q1.empty();
        }
};

int main()
{
        StackTwoQueues st;
        st.push(10);
        st.push(20);
        st.push(30);
        st.top();
        st.pop();
        st.top();
        st.pop();
        st.pop();
        st.pop();
        return 0;
}
