#include <iostream>
using namespace std;

class Queue {
    public:
        int *queue;
        int capacity, front, rear;

        Queue(int c) {
            capacity = c;
            queue = new int[c];
            front = 0;
            rear = 0;
        }

        void enqueue(int data) {
            if (rear == capacity) {
                cout << "Queue is full." << endl;
                return;
            }
            queue[rear] = data;
            rear++;
           
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }
            for (int i = 0; i < rear-1; i++)
            {
                queue[i] = queue[i+1]; // shift right index
            }
            rear--;
        }
        
        bool isEmpty() {
            return front == rear;
        }

        void print() {
            for (int i = 0; i < rear; i++)
            {
                cout << queue[i] << " <- ";
            }
            cout << "_" << endl;
            
        }

};

int main() {
    Queue queue(5);

    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(24);
    queue.enqueue(25);
    queue.enqueue(26);
    queue.enqueue(200);
    
    queue.print();

    queue.dequeue();
    queue.print();

    queue.enqueue(200);
    queue.print();


    return 0;
}