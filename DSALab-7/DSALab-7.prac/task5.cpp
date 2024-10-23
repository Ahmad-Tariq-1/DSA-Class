#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};

void insertAtEnd(Node*& head, int val){
    Node* newNode = new Node();
    newNode->data = val;  
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteAtEnd(Node*& head){
    if (head == NULL)
    {
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    delete temp;
}

void printForward(Node* temp){
    
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    cout<<"Before deleting at end"<<endl;
    printForward(head);

    deleteAtEnd(head);
     printForward(head);
    deleteAtEnd(head);
     printForward(head);
    deleteAtEnd(head);
     printForward(head);
    deleteAtEnd(head);
     printForward(head);
    deleteAtEnd(head);
     printForward(head);
    deleteAtEnd(head);
     printForward(head);
    cout<<"After deleting at end"<<endl;
    printForward(head);

    return 0;
}