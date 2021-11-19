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
//inorder successor solution starts here
//inorder to find inorder successors of any ith node need to keep 3 cases in our mind
	//1.if node->right!=NULL : successor is left most node, in the left subtree.
	//2. if node->right == NULL: then we find the rightmost node. 
		// if the rightmost node != node:
			// so we recursively look for its parent(inorder successor) such that:
				// parent->left == current node.(p->left = x) 
	//3. if the rightmost node == node:
		// this means that current node is the last node of the inorder traversal:
			//last node of the inorder has no inorder succesor, so we return NULL.


//utility function to find the leftmost and rightmost node of a node.
TreeNode* leftMost(TreeNode* node){
	if(node == NULL){
		return NULL;
	}

	while(node!=NULL and node->left!=NULL){
		node = node->left;
	}
}
TreeNode* rightMost(TreeNode* node){
	
	while(node!=NULL and node->right!=NULL){
		node = node->right;
	}
	return node;
}
TreeNode* InorderRecursive(TreeNode* node,TreeNode* x){
	if(node == NULL){
		return NULL;
	}
	TreeNode* temp = NULL;
	if(node == x ||  (temp = InorderRecursive(node->left,x)) || (temp =  InorderRecursive(node->right,x))){
		if(temp!=NULL){
			if(node->left == temp){
				return node;
			}
		}
		return node;
	}
	return NULL;
}

void InOrderSuccessor(TreeNode* root, TreeNode* node){
	if(node == NULL){
		cout << "NULL" << endl;
		return;
	}
	//case 1 : if the right of the node is NULL, then surely the leftmost element in its left subtree is its inorder successor.
	if(node->right==NULL){
		return leftMost(node);
	}else{
		TreeNode* rightMost = rightMost(node);
		//case 3: if the node is the rightmost and lastnode then it won't be having a inorder successor.
		if(rightMost == node){
			return NULL;
		}
		//case 2: if not
		else {
			return InorderRecursive(root,rightMost);
		}
	}
}



int main(){

	int n; cin >> n;
	
	TreeNode* root = NULL;
	for(int i = 0 ; i <  n; i++){
		root = 	insert(root,i);
	}
	inorder(root);
}
