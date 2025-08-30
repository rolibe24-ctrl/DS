// 5. Write a program for the evaluation of a Postfix expression.

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top==MAX - 1) {
        cout<<"Stack Overflow\n";
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top== -1) {
        cout<<"Stack Underflow\n";
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char postfix[]) {
    for (int i = 0; i < strlen(postfix); i++) {
        char character = postfix[i];
        if (character >= '0' && character <= '9') {
            push(character -'0'); 
        }
        else {
            int val1 =pop();
            int val2 =pop();
            switch (character) {
                case '+': push(val2 +val1);
                        break;
                case '-': push(val2 -val1); 
                        break;
                case '*': push(val2* val1); 
                        break;
                case '/': push(val2 /val1); 
                        break;
                case '^': push(pow(val2, val1)); 
                        break;
                default: 
                    cout<< "Invalid operator: "<< character <<endl;
                    return -1;
            }
        }
    }
    return pop();
}


int main() {
    char postfix[MAX];
    cout<<"Enter Postfix Expression: ";
    cin>>postfix;
    int result = evaluatePostfix(postfix);
    cout<<"Result = "<<result<< endl;
    return 0;
}
