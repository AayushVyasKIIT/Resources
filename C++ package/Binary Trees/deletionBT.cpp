#include<bits/stdc++.h>

using namespace std;


typedef struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

}TreeNode;


//delete  a node and return the root node.
TreeNode* deleteBT(TreeNode* root,int data){
	//if the current node is empty, we create a new node and return it back.
	if(root==NULL){	
		return NULL;
	}
	if(root->left == NULL and root->right == NULL){

		if(root->data == data){
			return NULL;
		}else{
			return root;
		}

	}
	queue<TreeNode*> q;
	q.push(root);


	TreeNode* node = NULL;
	TreeNode* last = NULL;
	TreeNode* target = NULL;
	while(!q.empty()){
		node = q.front();q.pop();
		if(node!=NULL){
			if(node->data == data){
				target = node;
			}
			if(node->left){
				last = node;
				q.push(node->left);
			}
	
			if(node->right){
				last = node;
				q.push(node->right);

			}
		}
	}
	if(target!=NULL){
		target->data = node->data; // node will be the deepest node that is explored in the binary tree.
		if(last->right == node){
			last->right = NULL;
		}else{
			last->left = NULL;
		}
		delete(node);
	}

	return root;
}

void inorder(TreeNode* root){
	if(root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);

}


int main(){

	int n; cin >> n;
	
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	inorder(root);
	cout << endl;
	root = 	deleteBT(root,2);
	inorder(root);
}
