#include <bits/stdc++.h>

using namespace std;

struct node{ 
	int data;
	node* left;
	node* right;

	node(int data):data(data),left(NULL),right(NULL){}
};

//insert
node* buildBST(node* root,int key){
	if(root==NULL){
		return  new node(key);
	}
	if(root->data < key){
		 root->right = buildBST(root->right,key);
	}else{
		root->left = buildBST(root->left,key);
	}
	return root;
}



//Maximum and Minumum in O(H),O(logn)
node* Maximum(node* root){
	if(root == NULL){
		return NULL;
	}
	while(root->right!=NULL){
		root = root->right;
	}
	cout << "\n Max: "<<   root->data << endl;
	return root;
}
node* Minimum(node* root){
	if(root == NULL){
		return NULL;
	}
	while(root->left!=NULL){
		root = root->left;
	}
	cout << "\n Min: " << root->data << endl;
	return root;

}

inorder successor
node* inorderSuccessor(node* root){
	if(root->right == NULL){
		return Minimum(root->right);;
	}
	node* curr = root->right;
	while(curr && curr->left!=NULL){
		curr = curr->left;
	}
	return curr;
}
void inOrder(node* root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}
int main(){
	int n = 15;
	node* root = new node(0);
	for(int i = 1; i < n;i++){
		buildBST(root,i);
	}
	inOrder(root);
	Maximum(root);
	Minimum(root);
	cout << inorderSuccessor(root->left)->data << " ";
}
                                     
