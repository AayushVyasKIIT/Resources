#include <iostream>

using namespace std;

struct node{
    int data;
    node* left = NULL;
    node* right = NULL;

    node(int data):data(data){};
};
int searchInOrder(int InOrder[],int start,int end,int curr){
    for(int j=start;j<=end;j++){
        if(InOrder[j]==curr){
            return j;
        }
    }
    return -1; //which is not possible.

}
node* BuildTree(int InOrder[],int PostOrder[],int start,int end){
    static int i = end;
    if(start>end){
        return NULL;
    }
    int curr = PostOrder[i];
    i--;
    node* root = new node(curr);
    if(start==end){
        return root;
    }
    int pos = searchInOrder(InOrder,start,end,curr);
    root->right = BuildTree(InOrder,PostOrder,pos+1,end);
    root->left = BuildTree(InOrder,PostOrder,start,pos-1);

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
    int PostOrder[] = {4,5,2,6,7,3,1};
    node* root = BuildTree(InOrder,PostOrder,0,6);
    InOrderPrint(root);


}