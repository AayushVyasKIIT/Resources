#include <bits/stdc++.h>

using namespace std;

class Queue{
    private:
        stack<int> stack1;
    public:
        void enqueue(int data){
            stack1.push(data);
        }
        int dequeue(){
            if(stack1.empty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            int x = stack1.top();
            stack1.pop();
            if(stack1.empty()){
                return x;
            }
            int item = dequeue();
            stack1.push(x);

            return item;
        }
    
};


int main(){

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << q.peek();


}