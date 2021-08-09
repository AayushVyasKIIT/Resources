#include <bits/stdc++.h>
using namespace std;

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(int N=0):N(0){}
        void push(int data){
            q2.push(data);
            N++;
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> swap;
            swap = q1;
            q1 = q2;
            q2 = swap;


        }
        void pop(){
            q1.pop();
        }
        void peek(){
            cout << q1.front() << endl;
        }
};

int main(){

    Stack s(0);
    s.push(1);
    s.push(2);
    s.push(3);
    
    s.pop();
    s.peek();

}