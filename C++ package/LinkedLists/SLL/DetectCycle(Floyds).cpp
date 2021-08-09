#include <bits/stdc++.h>

#include "stdLL.cpp"

using namespace std;


bool detectCycle(node* &head){
    node* fast = head;
    node* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
void RemoveCycle(node* &head){
    node* fast = head;
    node* slow = head;
    bool cycle = 0;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){
            cycle = 1;
            break;
        }
    }
    fast = head;
    while(fast->next!=slow->next && cycle){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
    cout << "  " << endl;
    createCycle(head,1);
    detectCycle(head)?cout<<"cycle detected":cout<<"Its fine";
    RemoveCycle(head);
    detectCycle(head)?cout<<"cycle detected":cout<<" Its fine";
    printLL(head);


    
}