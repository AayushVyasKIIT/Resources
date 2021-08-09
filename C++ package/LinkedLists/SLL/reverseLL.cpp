#include <bits/stdc++.h>
#include "stdLL.cpp"

using namespace std;

void reverse(node* &head){

    node *prev = NULL;
    node *curr = head;
    node *next;

    while(curr != NULL){
        next = curr->next;
        //point nextptr to current's next.
        curr->next= prev;
        //reverse the link
        prev = curr;
        curr = next;

    }
    head = prev;

}


int main(){
    node* head = new node(0);
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLL(head);
    reverse(head);
    cout << "  " << endl;

    printLL(head);

}