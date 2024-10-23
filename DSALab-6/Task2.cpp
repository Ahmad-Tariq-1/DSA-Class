#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *nextNode;
    Node *prevNode;
};


void addAtEnd(Node *&headNode, int value)
{
    Node *newNode = new Node();  
    newNode->data = value;       
    newNode->nextNode = nullptr; 

    if (headNode == nullptr)
    {
        newNode->prevNode = nullptr; 
        headNode = newNode;
    }
    else
    {
        Node *tempNode = headNode;
        while (tempNode->nextNode != nullptr)
        {
            tempNode = tempNode->nextNode; 
        }
        tempNode->nextNode = newNode; 
        newNode->prevNode = tempNode; 
    }
}

void traverseForward(Node *headNode)
{
    if (headNode == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    Node *tempNode = headNode;
    cout << "Forward Traversal: ";
    while (tempNode != nullptr)
    {
        cout << tempNode->data << "-> ";
        tempNode = tempNode->nextNode;
    }
    cout << "NULL\n";
}

void traverseBackward(Node *headNode)
{
    if (headNode == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    Node *tempNode = headNode;
    while (tempNode->nextNode != nullptr)
    {
        tempNode = tempNode->nextNode;
    }

    cout << "Backward Traversal: ";
    while (tempNode != nullptr)
    {
        cout << tempNode->data << "-> ";
        tempNode = tempNode->prevNode;
    }
    cout << "NULL\n";
}

int main()
{
    Node *headNode = nullptr;
    int nodeValue;

    cout << "Enter 5 values to insert into the list:\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> nodeValue;
        addAtEnd(headNode, nodeValue);
    }

    cout << "\nForward Traversal:\n";
    traverseForward(headNode);

    cout << "\nBackward Traversal:\n";
    traverseBackward(headNode);

    return 0;
}