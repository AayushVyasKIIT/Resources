#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int data):data(data){
        left = NULL;
        right = NULL;
    }
};

bool getPath(vector<int> &path,node* root,int key){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getPath(path,root->left,key) || getPath(path,root->right,key)){
        return true;
    }
    path.pop_back();
    return false;
}
int LCA1(node* node,int n1,int n2){
    if(node==NULL){
        return -1;
    }
    vector<int> path1,path2;
    if(!getPath(path1,node,n1) || !getPath(path2,node,n2)){
        return -1;
    }
    int pc;
    for(pc=0;pc< path1.size() && path2.size(); pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }

    }

    return path1[pc-1];

    

}

node* LCA2(node* root,int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data ==n2){
        return root;
    }

    node* leftLCA = LCA2(root->left,n1,n2);
    node* rightLCA = LCA2(root->right,n1,n2);

    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA!=NULL){
        return leftLCA;
    }
    return rightLCA;
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << LCA1(root,5,4);
    cout << LCA2(root,5,4)->data;

    

}
