#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data):data(data){}
}n;


int main(){
    n* root = new n(5);
    root->left = new n(4);
    cout << root->left->data;
}
