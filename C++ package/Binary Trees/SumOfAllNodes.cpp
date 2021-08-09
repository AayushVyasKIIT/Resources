#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data):data(data),left(NULL),right(NULL){}
};

int CountOfNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return CountOfNodes(root->left) + CountOfNodes(root->right)+root->data;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
   
    cout << CountOfNodes(root);

}