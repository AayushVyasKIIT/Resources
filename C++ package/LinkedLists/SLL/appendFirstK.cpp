#include <bits/stdc++.h>
#include "stdLL.cpp"
using namespace std;

node* appendFirstK(node* &head,int k){
    node* newHead;
    node* newTail;

    node* temp = head;
    int last = 0;
    while(temp->next != NULL){
        if(last==k){
            cout<< "helkkk";    
            newTail = temp;
            newHead = temp->next;
        }
        temp = temp->next;
        last++;
        cout << last;
    }
    newTail->next = NULL;
    temp->next = head;
    head = newHead;
    return head;
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
    head = appendFirstK(head,2);
    cout << "  " << endl;

    printLL(head);

}












