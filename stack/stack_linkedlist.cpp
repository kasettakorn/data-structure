#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int d) {
            data = d;
            next = NULL;
        }
};

class Stack {
    public:
        Node *top;

        Stack() {
            top = NULL;
        }

        void push(int data) {
            Node *newNode = new Node(data);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (top == NULL) {
                cout << "Stack is empty." << endl;
                return;
            }
            Node *temp = top;
            top = top->next;

            free(temp);
        }

        int peek() {
            if (top == NULL) {
                return -1;
            }
            return top->data;
        }

        void print() {
            Node *currentNode = top;
            while(currentNode != NULL) {
                cout << currentNode->data << " -> ";
                currentNode = currentNode->next;
            }
            cout << "_" << endl;
        }
};


int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(55);
    stack.push(555);
    stack.push(5555);

    stack.print();

    stack.pop();
    stack.pop();
    stack.print();



    cout << "Top of stack is " << stack.peek() << endl;
}
