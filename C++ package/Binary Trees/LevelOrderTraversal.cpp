#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data):data(data){}
};

void LevelOrderTraversal(node* root){
    if(root==NULL){
        return;
    }
    int L=0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    L++;

    while(!q.empty()){
        node* node = q.front();
        q.pop();
        if(node!=NULL){
            cout << node->data;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
            L++;
        }
    }
    cout << "\nNumber of levels are:" << L ;
    
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left->left = NULL;
    root->right->right->left = NULL;
    root->right->left->right = NULL;
    root->right->right->right = NULL;
    LevelOrderTraversal(root);
    
}