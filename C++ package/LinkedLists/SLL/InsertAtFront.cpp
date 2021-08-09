#include <bits/stdc++.h>
#include "stdLL.cpp"

using namespace std;

void Prepend(int data,node* &head){
    node* newNode = new node(data);

    if(head==NULL){
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

int main(){
    node* head = new node(0);
    node* n1 = new node(1);
    node* n2 = new node(2);
    head->next = n1;
    n1->next = n2;
    Prepend(3,head);
    printLL(head);



}
