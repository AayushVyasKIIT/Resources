#include <bits/stdc++.h>
#include "stdLL.cpp"

using namespace std;

node* add2num(node* &head1,node* &head2){
    node* t1 = head1;
    node* t2 = head2;
    node* t3head = new node(-1);
    int carry = 0;
    while(t1!=NULL && t2!=NULL){
        int sum = t1->data + t2->data + carry;
        if(sum>9){
            carry = 1;
        }else{
            carry =0;
        }
        int x = sum%10;
        node* newNode = new node(x);
        newNode->next = t3head;
        t3head = newNode;

        t1 = t1->next;
        t2 = t2->next;
    }
    if(carry==1){
        node* temp = t3head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        node* carryNode = new node(1);
        temp->next = carryNode;
    }
    return t3head;
}



int main(){
    node* head1 = new node(7);
    node* n1 = new node(1);
    node* n2 = new node(9);
    head1->next = n1;
    n1->next = n2;
    n2->next = NULL;

    printLL(head1);
    cout << "  " << endl;

    node* head2 = new node(5);
    node* n21 = new node(9);
    node* n22 = new node(2);
    head2->next = n21;
    n21->next = n22;
    n22->next = NULL;

    printLL(head2);
    cout << "  " << endl;

    node* sum = add2num(head1,head2);
    printLL(sum);

}