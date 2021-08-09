#include <bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node* next = NULL;
        node(int data):data(data){}
};

void append(node* &head,int val){
    node* newNode = new node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next!= head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void printCLL(node* &head){
    node* temp = head;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while(temp!=head);
    cout << head->data << endl;
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
    n3->next = head;   
    printCLL(head);
    append(head,5);
    printCLL(head);





}