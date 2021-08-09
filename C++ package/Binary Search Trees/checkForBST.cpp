#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int data):data(data),left(NULL),right(NULL){}
};

bool check4BST(node* root,node* min = NULL,node* max = NULL){
    if(root==NULL){
        return true; //if no node then already in BST
    }
    if(min!=NULL and root->data <= min->data){
        return false;
    }
    if(max!=NULL and root->data >= max->data){
        return false;
    }
    return check4BST(root->left,min,root) and check4BST(root->right,root,max);
}
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
}int main(){
    vector<int> arr = {5,2,1,3,4,0};
    node* n = new node(arr[0]);
    for(int i=1;i<arr.size();i++){
        BuildBST(n,arr[i]);
    }
    check4BST(n)?cout<<"True":cout<<"false";
    
}