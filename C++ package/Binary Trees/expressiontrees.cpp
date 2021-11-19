#include<bits/stdc++.h>

using namespace std;


typedef struct TreeNode{
	char data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(char data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

}TreeNode;

//we create a function to check if a character is an operator or an operand
bool isOperator(char c){
	if(c=='+' || c=='-' || c=='/' || c=='*' ){
		return true;
	}
	return false;
}
//we need to first create an expression tree
TreeNode* create(string expression){
	
	stack<TreeNode*> st;

	//1. we loop through the expression
	TreeNode* parent = NULL;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	for(int i = 0; i< expression.size();i++){
		//2. if a char i.e expression[i] == operand then we push that on to a stack.
		if(!isOperator(expression[i])){
			//create a new node and push it onto the stack
			TreeNode* parent = new TreeNode(expression[i]);
			st.push(parent);
		}
		//3. if a char is an operator then:
		// 	pop two values from stack and make them its child and push the current node again.
		if(isOperator(expression[i])){
			//pop two values
			parent  = new TreeNode(expression[i]); // operator will be the parent
			TreeNode* left = st.top(); st.pop(); //left child is one element.
			TreeNode* right = st.top(); st.pop(); //right child is second elemet.
			
			// we made the popped nodes left and right child of the operator.
			parent->left = left;
			parent->right = right;
			
			st.push(parent); 
		}
	}
	
	TreeNode* root = st.top(); st.pop(); //because we pushed the parent every time we perform popping, thats why at last we have the root, left in the stack.
	return root;

}
int calculate(int a,int b,char c){
	switch (c){
		case '+':
			return a+b;		
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		default: 
			return 0;
	}	
}

//then we need to evaluate this expression tree.
int evaluate(TreeNode* root){
	if(root == NULL){
		return 0;
	}

	if(!isOperator(root->data)){
		return '0' - (root->data);
	}

	int a =  evaluate(root->left);
	int b = evaluate(root->right);

	return calculate(a,b,root->data);

}
void inorder(TreeNode* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int main(){
	//this expressiion has to be a postfix expression
	string expression = "32+5*";
	TreeNode* root = NULL;
	root=create(expression);
	inorder(root);
	cout << endl;
	cout << evaluate(root) << endl ;
}
