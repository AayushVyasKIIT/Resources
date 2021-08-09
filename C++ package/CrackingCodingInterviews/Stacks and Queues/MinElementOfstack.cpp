/* 
*Stack Min: How would you design a stack which, in addition to push and pop, has a function min
*which returns the minimum element? Push, pop and min should all operate in 0(1) time.
*/

#include <bits/stdc++.h>

using namespace std;

class Stack{
    int *arr;
    int top;
    int size;
    int min =INT_MAX;
    public:
        //not considering boundary cases for now
        Stack(int size){
            arr = new int[size];
            top=-1;
        }
        void push(int data){
            top++;
            if(this->min>data){
                this->min = data;
            }
            arr[top] = data;
        }
        void pop(){
            top--;
        }
        int minelement(){
            return min;   
        }

};

int main(){
    Stack s(5);
    s.push(4);
    s.push(1);
    s.push(2);
    s.push(1);
    s.push(5);

    cout << s.minelement() << endl;

}