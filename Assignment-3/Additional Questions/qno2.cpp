#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> st; 
    stack<int> minStack; 

public:
    void push(int x) {
        st.push(x);
        
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            minStack.push(minStack.top());
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (st.empty()) {
            return;
        }
        
        // Pop from both stacks
        st.pop();
        minStack.pop();
    }

    // Return the top element of the stack without removing it
    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top();
    }

    // Get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top();
    }
};

int main() {
    SpecialStack st;
    
    st.push(18);
    st.push(19);
    st.push(29);
    st.push(15);
    st.push(16);

    cout << st.getMin() << endl;

    return 0;
}