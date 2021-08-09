#include <bits/stdc++.h>
#include "stdLL.cpp"
using namespace std;

void Delete_at_i(int i,node* &head){
    i=i-1;
    if(head==NULL){
        return;
    }

    if(i<0){
        head = head->next;
        return;
    }
    node* temp = head;
    while(i>0){
        temp = temp->next;
        i --;
    }
    temp->next = temp->next->next;
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
    Delete_at_i(1,head);
    cout << "  " << endl;

    printLL(head);


}