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


//insert a node and return the root node.
TreeNode* insert(TreeNode* root,int data){
	//if the current node is empty, we create a new node and return it back.
	if(root==NULL){
		TreeNode* root = new TreeNode(data);
		return root;
	}

	queue<TreeNode*> q;
	q.push(root);


	TreeNode* node = NULL;
	while(!q.empty()){
		node = q.front();q.pop();
		if(node!=NULL){
			if(node->left == NULL){
				node->left = new TreeNode(data);
				return root;
			}else{
				q.push(node->left);
			}
			if(node->right == NULL){
				node->right = new TreeNode(data);
				return root;
			}else{
				q.push(node->left);
			}
		}
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
	
	TreeNode* root = NULL;
	for(int i = 0 ; i <  n; i++){
		root = 	insert(root,i);
	}
	inorder(root);
}
