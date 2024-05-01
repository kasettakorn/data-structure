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

class CircularlyLinkedList {
    int size;
    Node *head;

    public:
        CircularlyLinkedList() {
            size = 0;
            head = NULL;
        }

        void add(int data) {
            Node *newNode = new Node(data);
            if (size == 0) {
                head = newNode;
                head->next = head;
            }
            else {
                Node *currentNode = head->next;
                while (currentNode->next != head) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
                newNode->next = head;
            }
            size++;
        }

        void print() {
            Node *currentNode = head;
            do
            {
                cout << currentNode->data << " -> ";
                currentNode = currentNode->next;
            } while (currentNode != head);
            cout << currentNode->data << endl;
            
        }
};

int main() {
    CircularlyLinkedList linkedlist = CircularlyLinkedList();
    linkedlist.add(99999);
    for (int i = 1; i < 20; i+=2)
    {
        linkedlist.add(i);
    }
    
    linkedlist.print();


    return 0;
}