// 3. Write a program that checks if an expression has balanced parentheses.

#include <iostream>
using namespace std;
#define MAX 100

bool balanced(string expression) {
    char stack[MAX];
    int top= -1;

    for (int i=0; i <expression.length(); i++) {
        char c= expression[i];
        if (c =='(' || c =='{' || c =='[') {
            if (top == MAX - 1) return false;
            stack[++top] = c;
        }
        else if (c ==')' || c== '}' || c==']') {
            if (top == -1) 
                return false;
            char topchar = stack[top--];
            if ((c == ')' && topchar != '(') ||
                (c == '}' && topchar != '{') ||
                (c == ']' && topchar != '[')) {
                return false;
            }
        }
    }
    return (top == -1);
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    if (balanced(expression))
        cout<<"Balanced" <<endl;
    else
        cout<<"Not Balanced"<<endl;
    return 0;
}
