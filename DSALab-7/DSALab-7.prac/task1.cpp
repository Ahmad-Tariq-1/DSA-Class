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
void printForward(Node* node){
    cout<<"Name:Ahmed Tariq"<<endl;
    cout<<"Sap Id:56274"<<endl;
    cout<<"Forward Traversal: ";
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"Null"<<endl;
}

void printReverse(Node* temp){
    if (temp == NULL)
    {
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    cout<<"Reverse Traversal: ";
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
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
    printForward(head);
    printReverse(head);

    return 0;
}