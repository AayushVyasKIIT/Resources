#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data):data(data),left(NULL),right(NULL){}
};

node* LCA(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    if(LCA(root->left,n1,n2)&&(LCA(root->right,n1,n2))){
        return root;
    }
    if(LCA(root->left,n1,n2)!=NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}
int findDist(node* root,int k,int distance){
    if(root==NULL){
        return -1;
    }
    if(root->data == k){
        return distance;
    }
    if(findDist(root->left,k,distance+1)!=-1){
        return findDist(root->left,k,distance+1);
    }
    return findDist(root->right,k,distance+1);
}

int DistanceBtwn2(node* root,int n1,int n2){
    node* lca = LCA(root,n1,n2);

    int d1 = findDist(root,n1,0);
    int d2 = findDist(root,n2,0);

    return d1 + d2;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << DistanceBtwn2(root,4,7);

}