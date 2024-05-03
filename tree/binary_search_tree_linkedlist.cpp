#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;

        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree();
    ~BinarySearchTree();

    void add(int);
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
};

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::inorder(Node *node) 
{
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BinarySearchTree::preorder(Node *node) 
{
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    inorder(node->left);
    inorder(node->right);

}

void BinarySearchTree::postorder(Node *node) 
{
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    inorder(node->right);
    cout << node->data << " ";
}

void BinarySearchTree::add(int data) {
    if (root == NULL) {
        root = new Node(data);
        return;
    }
    Node *currentNode = NULL;
    Node *tempNode = root;

    Node *newNode = new Node(data);

    while (tempNode != NULL)
    {
        currentNode = tempNode;
        if (data < tempNode->data) {           
            tempNode = tempNode->left;
        }
        else {
            tempNode = tempNode->right;
        }
    }
    
    if (data < currentNode->data) {
        currentNode->left = newNode;
    }
    else {
        currentNode->right = newNode;
    }
    
    
}


int main() {
    BinarySearchTree tree;

    tree.add(15);
    tree.add(20);
    tree.add(10);
    tree.add(40);
    tree.add(60);

    tree.inorder(tree.root);
    cout << endl;

    tree.preorder(tree.root);
    cout << endl;
    
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}