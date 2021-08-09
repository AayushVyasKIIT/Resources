#include <iostream>

using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;

    node(int data):data(data){}
};
void PreOrder(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data;
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout << root->data;
    InOrder(root->right);

}
void PostOrder(node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << " PreOrder:";
    PreOrder(root);
    cout << " InOrder:";
    InOrder(root);
    cout << " PostOrder:";
    PostOrder(root);



}