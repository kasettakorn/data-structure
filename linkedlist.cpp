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

class SingularlyLinkedList {
    int size;
    Node *head;

    public:
        SingularlyLinkedList() {
            size = 0;
            head = NULL;
        }

        void add(int data) {
            Node *newNode = new Node(data);
            if (size == 0) {
                head = newNode;
            }
            else {
                Node *currentNode = head;
                while (currentNode->next != NULL) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            size++;
        }

        void print() {
            Node *currentNode = head;
            while (currentNode != NULL) 
            {
                cout << currentNode->data << " -> ";
                currentNode = currentNode->next;
            }
            cout << "NULL" << endl;
            
        }
};

int main() {
    SingularlyLinkedList linkedlist = SingularlyLinkedList();
    
    for (int i = 1; i < 20; i+=2)
    {
        linkedlist.add(i);
    }
    
    linkedlist.print();


    return 0;
}