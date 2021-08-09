#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left,*right;
    node(int data):data(data),left(NULL),right(NULL){}
};

node* BBSTfromSortedArray(vector<int> sortedArray,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    node* root = new node(sortedArray[mid]);
    root->left = BBSTfromSortedArray(sortedArray,start,mid-1);
    root->right = BBSTfromSortedArray(sortedArray,mid+1,end);

    return root;
}
void InOrder(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << "  ";
    InOrder(root->left);
    InOrder(root->right);
}
void PreOrder(node* root){
    if(root==NULL){
        return;
    }
    PreOrder(root->left);
    cout << root->data << "  ";
    PreOrder(root->right);
}


int main(){
    vector<int> arr = {5,2,1,3,4,0};
    sort(arr.begin(),arr.end());
    node* root = BBSTfromSortedArray(arr,0,arr.size()-1);    
    PreOrder(root);
}