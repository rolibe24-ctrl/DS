// 1. Develop a menu driven program demonstrating the following operations on a Stack using array: (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include<iostream>
using namespace std;

struct Stack{
    int array[10];
    int toppointer;
};


void push(Stack &stack, int element){
    if(stack.toppointer==9){
        cout<<"the stack is full"<<endl;
    }
    else{
        stack.toppointer++;
        stack.array[stack.toppointer]=element;
        cout<<"element has been pushed"<<endl;
    }
    
}

void pop(Stack &stack){
    int removed;
    if(stack.toppointer==-1){
        cout<<"the stack is empty"<<endl;
    }
    else{
        removed=stack.array[stack.toppointer];
        stack.toppointer--;
        cout<<"Removed element is: "<<removed<<endl;
    }
}

void isEmpty(Stack &stack){
    if(stack.toppointer<0){
        cout<<"the stack is empty"<<endl;
    }
    else{
        cout<<"the stack is not empty"<<endl;
    }
}

void isfull(Stack &stack){
    if(stack.toppointer==9){
        cout<<"the stack is full"<<endl;
    }
    else{
        cout<<"stack is not full"<<endl;
    }
}


void display(Stack &stack){
   if(stack.toppointer<0){
       cout<<"the are no elements in the stack"<<endl;
   }
    cout<<"Stack elements: ";
    for (int i = stack.toppointer; i >= 0; i--) {
        cout<<stack.array[i]<<"";
    }
        cout<<endl;
}

void peek(Stack &stack){
    if(stack.toppointer<0){
        cout<<"cannot perform peek operation "<<endl;
    }
    cout<<"top element is: "<<stack.array[stack.toppointer]<<endl;
}

int main() {
    Stack stack;
    stack.toppointer = -1;
    int choice, element;

    do {
        cout<<"MENU" << endl;
        cout<<"1) push" << endl;
        cout<<"2) pop" << endl;
        cout<<"3) check if Empty" << endl;
        cout<<"4) check if Full" << endl;
        cout<<"5) display" << endl;
        cout<<"6) peek" << endl;
        cout<<"7) exit" << endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter element to push:";
                cin>>element;
                push(stack, element);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                isEmpty(stack);
                break;
            case 4:
                isfull(stack);
                break;
            case 5:
                display(stack);
                break;
            case 6:
                peek(stack);
                break;
            case 7:
                cout<<"Exiting program"<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    } while(choice != 7);

    return 0;
}


