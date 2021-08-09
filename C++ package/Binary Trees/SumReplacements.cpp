#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data):data(data),left(NULL),right(NULL){}
};

int sumReplacement(node* &root){
    if(root==NULL){
        return 0;
    }
    
    root->data = sumReplacement(root->left) + sumReplacement(root->right) +root->data;
    
    return root->data;
}
void InOrder(node* root){
    if(root==NULL)
        return;
    
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    InOrder(root);
    sumReplacement(root);
    InOrder(root);


}