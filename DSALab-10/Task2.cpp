#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node* insert(Node* root, int value) {
    if(root==nullptr) {
        return createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}
bool search(Node* root, int value){
    if(root==nullptr) return false;
    if(root->data == value) return true;

    if(value< root->data){
        return search(root->left, value);
    }
    else{
        return search(root->right, value);
    }
}
void inOrderTraversal(Node* root){
    if(root==nullptr) return;
    inOrderTraversal(root->left);
    cout<<root->data <<" ";
    inOrderTraversal(root->right);
}

int main(){
    Node* root = nullptr;
    cout<<"how many value do yo want to enter";
    int n;
    cin>>n;
    int val; 
for (int i = 0; i < n; i++)
{
    cout<<"Enter the value"<<endl;
    cin>>val;
    root = insert(root, val);
    
}
    cout<<"In- Order Traversal of the BST: ";
    inOrderTraversal(root);

    return 0;
}
