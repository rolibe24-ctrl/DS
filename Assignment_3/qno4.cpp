#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        cout<<"Stack is full\n";
        return;
    }
    stack[++top] =c;
}

char pop() {
    if (top==-1) return '\0'; 
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

int associativity(char c) {
    if (c == '^') 
        return 2;
    return 1;            
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int j = 0;

    for (int i=0; i< strlen(infix); i++) {
        char c =infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[j++]= c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(c) &&
                  !(precedence(stack[top]) == precedence(c) && associativity(c) == 2)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    char infix[MAX];
    cout << "Enter Infix Expression: ";
    cin.getline(infix, MAX);
    infixToPostfix(infix);
    return 0;
}
