#include <bits/stdc++.h>

using namespace std;

class Queue{
    private:
        int* arr;
        int front;
        int back;
        int n;
    public:
        Queue(int n){
            arr = new int[n];
            front =-1;
            back = -1;
        }        
        void enqueue(int data){
            if(back==n){
                cout << "Queue Overflow" << endl;
                return; 
            }
            back++;
            arr[back] = data;

            if(front==-1){
                front++;
            }
        }
        void dequeue(){
            if(front==-1){
                cout << "Queue Empty" << endl;
                return;
            }
            if(front>back){
                cout << "Queue OverFlow" << endl;
                return;
            }
            front++;
        }
        bool isEmpty(){
            if(front==-1 || front>back){
                return 1;
            }
            return 0;
        }
        int peek(){
            if(front==-1 || front > back){
                return -1;
            }
            return arr[front];

        }
};


int main(){

    Queue q(10);
    for(int i=0;i<10;i++)
        q.enqueue(i);
    
    cout << q.peek();
    for(int i=0;i<9;i++)
        q.dequeue();
    cout << q.peek();
    
    q.dequeue();
    cout << q.isEmpty() << endl;


}