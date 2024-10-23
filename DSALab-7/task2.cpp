#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};

void insertAtBeginning(Node*& head, int val){
    Node* newNode = new Node();
    newNode->data = val;  
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

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

void printForward(Node* temp){
    cout<<"Name:Ahmed Tariq"<<endl;
    cout<<"Sap Id:56274"<<endl;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtBeginning(head, 50);
    insertAtBeginning(head, 40);
    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);
    cout<<"insertAtBeginning:";
    printForward(head);

    insertAtEnd(head, 60);
    insertAtEnd(head, 70);
    insertAtEnd(head, 80);
    cout<<"insertAtEnd: "<<endl;
    printForward(head);

    return 0;
}