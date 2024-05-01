#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int d) {
            data = d;
            next = NULL;
            prev = NULL;
        }
};

class DoublySentinelLinkedList {
    int size;
    Node *header, *tailer;

    public:
        DoublySentinelLinkedList() {
            size = 0;
            header = new Node(-1);
            tailer = new Node(-1);

            header->next = tailer;
            tailer->prev = header;
        }

        void add(int data) {
            Node *newNode = new Node(data);
            if (size == 0) {
                header->next = newNode;
                newNode->next = tailer;
                newNode->prev = header;
                tailer->prev = newNode;
            }
            else {
                Node *currentNode = header;
                while (currentNode->next != tailer) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
                tailer->prev = newNode;
                newNode->prev = currentNode;
                newNode->next = tailer;
                
            }
            size++;
        }

        void printForward() {
            Node *currentNode = header;
            if (header->next == tailer) {
                cout << "No data" << endl;
                return;
            }
            while (currentNode != tailer) 
            {
                
                cout << currentNode->data << " -> ";
                currentNode = currentNode->next;
                
            }
            cout << currentNode->data << endl;
            
        }

        void printReverse() {
            Node *currentNode = tailer;
            if (tailer->prev == header) {
                cout << "No data" << endl;
                return;
            }

            while (currentNode != header) 
            {
                
                cout << currentNode->data << " -> ";
                currentNode = currentNode->prev;
                
            }
            cout << currentNode->data << endl;
        }
};

int main() {
    DoublySentinelLinkedList linkedlist = DoublySentinelLinkedList();
    
    for (int i = 1; i < 20; i+=2)
    {
        linkedlist.add(i);
    }
    
    linkedlist.printForward();
    linkedlist.printReverse();


    return 0;
}