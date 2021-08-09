#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int data):data(data),left(NULL),right(NULL){}
};

bool SearchBST(node* root,int key){
    if(root==NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }
    if(root->data > key){
        return SearchBST(root->left,key);
    }else{
        return SearchBST(root->right,key);
    }
    return false;
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
}
void InOrder(node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
    
}
int main(){
    vector<int> arr = {5,2,1,3,4,0};
    node* n = new node(arr[0]);
    for(int i=1;i<arr.size();i++){
        BuildBST(n,arr[i]);
    }
    InOrder(n);
    SearchBST(n,0)?cout<<"True":cout<<"false";
    
}