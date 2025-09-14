// 5) Write a program to implement a stack using (a) One queue

#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue
{
        queue<int> q;

public:
        void push(int x)
        {
                q.push(x);
                int size = q.size();
                for (int i = 0; i < size - 1; i++)
                {
                        q.push(q.front());
                        q.pop();
                }
                cout << x << " pushed to stack\n";
        }

        void pop()
        {
                if (q.empty())
                {
                        cout << "Stack is Empty\n";
                        return;
                }
                cout << q.front() << " popped from stack\n";
                q.pop();
        }

        void top()
        {
                if (q.empty())
                {
                        cout << "Stack is Empty\n";
                        return;
                }
                cout << "Top element: " << q.front() << endl;
        }

        bool isEmpty()
        {
                return q.empty();
        }
};

int main()
{
        StackOneQueue st;
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
