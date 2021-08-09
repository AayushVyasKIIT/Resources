#include <bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node* next = NULL;
        node(int data):data(data){}
};

class Queue{
    private:
        node* front;
        node* back;
    public:
        Queue(){
            front = NULL;
            back = NULL;
        }
        void enqueue(int data){
            node* newNode = new node(data);
            if(front==NULL){
                front = newNode;
                back = newNode;
            }
            back->next = newNode;
            back = newNode;
        }   
        void dequeue(){
            if(front==NULL ||  front>back){
                cout << "OverFlow or Underflow" << endl;
            }
            front = front->next;
        }  
        int peek(){
            if(front==NULL ||  front>back){
                cout << "OverFlow or Underflow" << endl;
            }
            return front->data;
        }
        bool isEmpty(){
            if(front == NULL || front>back){
                return 1;
            }
            return 0;
        }
};  
int main(){
    Queue q;
    for(int i=0;i<10;i++)
        q.enqueue(i);
    
    cout << q.peek();
    for(int i=0;i<9;i++)
        q.dequeue();
    cout << q.peek();
    
    q.dequeue();
    cout << q.isEmpty() << endl;

}