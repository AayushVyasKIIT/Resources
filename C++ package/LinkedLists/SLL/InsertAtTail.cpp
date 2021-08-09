#include <bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node* next = NULL;
    node(int data):data(data){}
};

void insertAtTail(int data,node* &head){

    node* newNode = new node(data);

    if(head==NULL){
        head = newNode;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = newNode;

}
void printLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << " "<< temp->data <<"->";
        temp = temp->next;

    }
    cout << "NULL";
}




int main(){

    node* head = new node(0);
    node* n1 = new node(1);
    node* n2 = new node(2);
    head->next = n1;
    n1->next = n2;
    insertAtTail(3,head);
    printLL(head);
    

}