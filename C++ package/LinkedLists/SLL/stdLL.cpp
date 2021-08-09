#include <bits/stdc++.h>

using namespace std;
class node{
    public:
        int data;
        node* next = NULL;
        node(int data):data(data){}
};
int lengthLL(const node* head){
    int length = 0;
    if(head==NULL){
        return 0;
    }
    while(head!=NULL){
        length ++ ;
        head = head->next;
    }
    return length;

}

void printLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << " "<< temp->data <<"->";
        temp = temp->next;

    }
    cout << "NULL";
}

node* createCycle(node* &head,int pos){
    node* temp = head;
    int count =0;
    node* cycle;
    while(temp->next!=NULL){
        if(count == pos){
            cycle = temp;
        }
        temp = temp->next;
        count ++;
    }
    temp->next = cycle;
    return head;

}