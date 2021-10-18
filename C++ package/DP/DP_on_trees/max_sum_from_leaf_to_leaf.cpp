#include <bits/stdc++.h>

using namespace std;

typedef struct node{
	int data;
	node* left;
	node* right;

	node(int data):data(data){}
}node;

int diameter(node* root, int &res){
	//base condition
	if(root == nullptr){
		return 0;
	}
	//hypothesis
	int left = diameter(root->left,res);
	int right = diameter(root->right,res);
	//induction
	int tempans = max(left,right) + root->data;
	if(root->left == nullptr and root->right == nullptr){
		tempans = max(tempans,root->data);
	}
	int ans = max(tempans,left+right+root->data);

	res = max(res,ans);
	
	return tempans;
}


void preorder(node* root){
	if(root == nullptr){
		return;
	}
	cout << root->data;
	preorder(root->left);
	preorder(root->right);

}

int main(){

	node *t = new node(0);
	t->left = new node(2);
	t->left->left = new node(3);
	t->right = new node(-1);
	t->right->right = new node(4);
	
	preorder(t);
	cout << endl;
	int res = 0;
	diameter(t,res);
	cout << res << endl;
}
