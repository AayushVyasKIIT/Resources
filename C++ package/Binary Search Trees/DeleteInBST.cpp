#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int data):data(data),left(NULL),right(NULL){}
};


node* InOrderSuccessor(node* rootRight,int key){
    node* curr = rootRight;
    // we will be looking in the left of the current node because
    // our current node is root->right which means if we look for the values in the curr->right, the values will be greater than
    // root->right->data
    // but we want to replace the parent with value < root->right->data in order to preserve the binary tree property,
    // this can be done by looking in the left subtree for smaller value that fits just correctly. and its value will be < root->right
    //thus curr->left->data will always be < root->right->data.
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}
node* deleteInBST(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data > key){
        root->left = deleteInBST(root->left,key);
    }
    else if(root->data < key){
        root->right = deleteInBST(root->right,key);
    }else{
        //case 2
        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        //case 3
        node* temp = InOrderSuccessor(root->right,key);
        //we find the inOrderSuccessor and returns it
        root->data = temp->data;
        //we replace our current roots data with the inOrderSuccessor's data
        root->right = deleteInBST(root->right,temp->data);
        //we delete our inOrderSuccessor as it is now present at our root node.
    }
    return root;

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
    deleteInBST(n,1);
    cout<< endl;
    InOrder(n);
    
}