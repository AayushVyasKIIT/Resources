/* 
? Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
? an additional temporary stack, but you may not copy the elements into any other data structure
? (such as an array). The stack supports the following operations: push, pop, peek, and is Empty.
*/
#include <bits/stdc++.h>

using namespace std;

stack<int> sortStack(stack<int> &Unsorted){

    stack<int> sorted;

    while(!Unsorted.empty()){

        int tmp = Unsorted.top();
        Unsorted.pop();

        while(!sorted.empty() and tmp<sorted.top()){

                Unsorted.push(sorted.top());
                sorted.pop();
        }
        sorted.push(tmp);
    }
    Unsorted = sorted;
    return Unsorted;
}


int main(){

    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(1);
    st.push(2);
    st.push(4);

    cout<< st.top();
    st = sortStack(st);
    cout<< st.top();

    

}