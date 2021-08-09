#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int data):data(data),left(NULL),right(NULL){}
};

int HeightOfABinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    return max(HeightOfABinaryTree(root->left), HeightOfABinaryTree(root->right))+1;
}
bool BalancedBinaryTree(node* root){ //O(n*n)
    if(root == NULL){
        return true;
    }
    if(BalancedBinaryTree(root->left) == false){
        return false;
    }
    if(BalancedBinaryTree(root->right) == false){
        return false;
    }


    int hl = HeightOfABinaryTree(root->left);
    int hr = HeightOfABinaryTree(root->right);
    if(abs(hl-hr)<=1){
        return true;
    }else{
        return false;
    }
    
}

bool isBalanced(node* root,int* height){
    int lh = 0;
    int rh = 0;
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left,&lh)==false){
        return false;
    }
    if(isBalanced(root->right,&rh)==false){
        return false;
    }

    *height = max(lh,rh) + 1;
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }

}




int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(4);
    


    
    int height = 0;
    cout << BalancedBinaryTree(root);
    cout << isBalanced(root,&height);

}

