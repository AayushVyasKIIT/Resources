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
    return max(HeightOfABinaryTree(root->left),HeightOfABinaryTree(root->right))+1;
}
int diameterOfBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight = HeightOfABinaryTree(root->left);
    int rheight = HeightOfABinaryTree(root->right);
    int currDiameter = lheight + rheight + 1; // passsing through root node

    int lDiameter= diameterOfBinaryTree(root->left); //not passing through root node
    int rDiameter = diameterOfBinaryTree(root->left);

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->left->left = new node(6);
    root->left->left->left->left = new node(7);
    root->left->right = new node(5);
   
    cout << diameterOfBinaryTree(root);

}