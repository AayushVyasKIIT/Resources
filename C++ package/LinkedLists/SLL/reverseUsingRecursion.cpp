#include <bits/stdc++.h>
#include "stdLL.cpp"

using namespace std;

node* reverseRecurr(node* &head){
    if(head==NULL || head->next ==NULL){
        return head;
    }
    node* newHead = reverseRecurr(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
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
    node* newHead = reverseRecurr(head);
    cout << "  " << endl;

    printLL(newHead);

}