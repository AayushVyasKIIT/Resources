#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int data):data(data),left(NULL),right(NULL){}
};
node* BuildBST(node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(root->data>val){
        root->left = BuildBST(root->left,val);
    }else{
        root->right = BuildBST(root->right,val);
    }
    return root;
}
node* BSTfromPreOrder(vector<int> preorder,int* preorderidx,int min,int max,int key,int n){
    if(*preorderidx >=n){
        return NULL;
    }
    node* root = NULL;
    if(key>min and key<max){
        root = new node(key);
        *preorderidx = *preorderidx + 1;
        if(*preorderidx<n){
            root->left = BSTfromPreOrder(preorder,preorderidx,min,key,preorder[*preorderidx],n);
        }
        if(*preorderidx<n){
            root->right = BSTfromPreOrder(preorder,preorderidx,key,max,preorder[*preorderidx],n);
        }
    }
    return root;
}
void PreOrder(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data <<  " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main(){
    vector<int> preorder = {10,2,1,13,11};
    int predorderidx = 0;
    node* root  = BSTfromPreOrder(preorder,&predorderidx,INT_MIN,INT_MAX,preorder[0],preorder.size());
    PreOrder(root);
    
    
}