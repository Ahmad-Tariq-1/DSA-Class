#include<iostream>
using namespace std;
 struct node{
    int data;
    node* next;
 };
 void insertAtEnd(node** head, int newdata){
    node* newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;
    if(*head == NULL) {
        *head = newnode;
        return;
    } 
    node* last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newnode; 
    }
    void deletenode(node** head, int key){
        node* temp = *head;
        node* prev = NULL;
        if(temp != NULL && temp->data == key){
            *head = temp->next;
            delete temp;
            return;
        }
        while(temp != NULL && temp->data != key){
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL){
            cout<<"value not found in the list"<<endl;
            return;
        }
        delete temp;
    }

    void printlist(node* node){
    while(node!= nullptr){
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"null"<<endl;
    }

    int main()
{
    cout<<"\n\n**********Lab 5 Linkedlist implementation**********\n\n"<<endl;
     node* head = nullptr;
    int n, value, deletevalue;
    cout<<"How many values do you want to insert at begining of the list? "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter value"<<i+1<<":"<<endl;
        cin>>value;
        insertAtEnd(&head, value);
    }
    cout<<"Linked List: "<<endl;
    printlist(head);
    cout<<"Enter the value of node to be deleted: "<<endl;
    cin>>deletevalue;
    deletenode(&head, deletevalue);
    cout<<"Linked List after deletion is: ";
    printlist(head);
    return 0;
}