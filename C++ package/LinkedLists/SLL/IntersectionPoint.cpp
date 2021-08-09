#include <bits/stdc++.h>
#include "stdLL.cpp"
using namespace std;

int intersectionPoint(node* head1,node* head2){
    int l1 = lengthLL(head1);
    int l2 = lengthLL(head2);

    node* ptr1 = head1;
    node* ptr2 = head2;
    int st_pos_big;
    if(l1>l2){
        st_pos_big = l1-l2;
        node* temp = head1;
        int itr = 0;
        while(itr <st_pos_big){
            temp = temp->next;
            itr++;
        }
        ptr1 = temp;
    }else{
        st_pos_big = l2-l1;
        node* temp = head2;
        int itr = 0;
        while(itr < st_pos_big){
            temp = temp->next;
            itr++;
        }
        ptr2 = temp;
    }
    int pos = 0;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->next == ptr2->next){
            return pos+1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        pos++;

    }

    return -1;

}


int main(){

    node* head1 = new node(0);
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    head1->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << " LL1 " << endl;
    printLL(head1);
    int l = lengthLL(head1); 
    cout << l << endl;

    node* head2 = new node(4);
    node* n21 = new node(5);
    head2->next = n21;
    n21->next = n3;
    
    


    cout << " LL2 " << endl;
    printLL(head2);
    int l2 = lengthLL(head2); 
    cout << l2 << endl;

    cout << intersectionPoint(head1,head2);
}