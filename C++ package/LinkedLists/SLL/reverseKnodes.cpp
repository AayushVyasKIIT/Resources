#include <bits/stdc++.h>
#include "stdLL.cpp"

using namespace std;

node *reverseKnode(int k,node* &head){
   node* prev =NULL;
   node* curr = head;
   node* next;

   int count = 0;

   while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
        head->next = reverseKnode(k,next); //this will return the new head 
        //of the reversed linked list.
   return prev; //because prevPTR is pointing will be pointing to the nextptr(new head)
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
    node* newHead = reverseKnode(3,head);
    cout << "  " << endl;

    printLL(newHead);

}