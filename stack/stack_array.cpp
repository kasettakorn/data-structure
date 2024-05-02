#include <iostream>
using namespace std;

class Stack {
    public:
        int capacity;
        int *stack;
        int top;

        Stack(int c) {
            capacity = c;
            stack = new int[c];
            top = 0;
        }

        void push(int data) {
            if (top == capacity) {
                cout << "Stack is full." << endl;
                return;
            }
            stack[top] = data;
            top++;
        }

        void pop() {
            if (top == 0) {
                cout << "Stack is empty." << endl;
                return;
            }
            int temp = top;
            top--;
        }

        int peek() {
            return stack[top-1];
        }

        void print() {
            for (int i = 0; i < top; i++)
            {
                cout << stack[i] << " -> ";
            }
            cout << "_" << endl;
        }
};


int main() {
    Stack stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();
    stack.pop();
    stack.pop();

    stack.push(4);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    
    stack.print();

    cout << "Top of stack is " << stack.peek() << endl;
}
