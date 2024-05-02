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
class Queue {
    public:
        Node *front, *rear;

        Queue() {
            front = NULL;
            rear = NULL;
        }

        void enqueue(int data) {
            Node *newNode = new Node(data);
            if (isEmpty()) {
                front = newNode;
                rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }
            Node *deleteNode = front;
            front = deleteNode->next;

            deleteNode->next = NULL;
            
            free(deleteNode); // deallocate memory
        }
        
        bool isEmpty() {
            return front == NULL;
        }

        void print() {
            Node *currentNode = front;
            while(currentNode != NULL) {
                cout << currentNode->data << " <- ";
                currentNode = currentNode->next;
            }
            cout << "_" << endl;
            
        }

};

int main() {
    Queue queue;

    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(24);
    queue.enqueue(25);
    queue.enqueue(26);
    queue.enqueue(200);
    
    queue.print();

    queue.dequeue();
    queue.print();

    queue.enqueue(999);
    queue.print();


    return 0;
}