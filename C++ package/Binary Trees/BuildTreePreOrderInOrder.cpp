#include<iostream>

using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;

    node(int data):data(data){}
};
int searchInOrder(int InOrder[],int start,int end,int curr){
    for(int j=start;j<=end;j++){
        if(InOrder[j]==curr){
            return j;
        }
    }
    return -1; //which is not possible.

}
node* BuildTree(int InOrder[],int PreOrder[],int start,int end){
    if(start>end){
        return NULL;
    }
    static int i = 0;
    int curr = PreOrder[i];
    node* root = new node(curr);
    i++;
    if(start == end){
        return root; //means only 1 node in our inorder.
    }
    int pos = searchInOrder(InOrder,start,end,curr);
    root->left = BuildTree(InOrder,PreOrder,start,pos-1);
    root->right = BuildTree(InOrder,PreOrder,pos+1,end);

    return root;
}
void InOrderPrint(node* root){
    if(root==NULL){
        return;
    }
    InOrderPrint(root->left);
    cout << root->data;
    InOrderPrint(root->right);

}
int main(){
    int InOrder[] = {4,2,5,1,6,3,7};
    int PreOrder[] = {1,2,4,5,3,6,7};
    node* root = BuildTree(InOrder,PreOrder,0,6);
    InOrderPrint(root);


}