#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data):data(data),left(NULL),right(NULL){}
};

void flatten(node* &root){
    if(root==NULL){
        return;
    }
    //if(root->left == NULL this means that our bt is already flattened)
    if(root->left!=NULL){
        flatten(root->left);

        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node* tail = root->right;
        while(tail->right!=NULL){
            tail = tail->right;
        }
        tail->right = temp;
    }
    flatten(root->right);
}
void inOrder(node* root){
    if(root== NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    inOrder(root);
    flatten(root);
    cout << " ";
    inOrder(root);
}