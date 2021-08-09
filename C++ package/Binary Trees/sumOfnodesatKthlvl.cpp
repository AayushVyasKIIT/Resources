#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;

    node(int data):data(data){}
};


int SumAtKthLevel(node* root,int k){
    if(root==NULL){
        return 0;
    }
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    int L=0;
    int sum =0;
    if(k==0){
        return root->data;
    }
    while(!q.empty() and L<=k){
        node* node = q.front();
        q.pop();
        if(node!=NULL){
            sum+=node->data;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            L++;
            q.push(NULL);
        }
    }
    return sum;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << SumAtKthLevel(root,2);

}

