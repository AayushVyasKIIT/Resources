#include <bits/stdc++.h>

using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
    int N;
    public:
        Stack():N(0){}
        void push(int data){
            q1.push(data);
            N++;
        }
        void pop(){
            if(q1.empty()){
                cout << "empty" << endl;
                return;
            }
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            cout << q1.front();
            q1.pop();
            queue<int> temp = q2;
            q2 = q1;
            q1 = temp;
        }
        void peek(){
            if(q1.empty()){
                cout << "empty" << endl;
                return;
            }
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            cout << q1.front();
            q2.push(q1.front());
            q1.pop();
            queue<int> temp = q2;
            q2 = q1;
            q1 = temp;

        }

};

int main(){
    
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    
    
    s.peek();
    s.pop();
    s.peek();

}