#include <bits/stdc++.h>
using namespace std;
void insertAtbottom(stack<int> &st,int ele){
    //base condition
    if(st.empty()){
        st.push(ele);
        return;
    }
    int top_ele = st.top();
    st.pop();
    insertAtbottom(st,ele);
    st.push(top_ele); // we are doing this because, we kept popping out all the elements in line 7.
}

void reverseStack(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtbottom(st,ele);
    
}


int main(){

    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while(st.empty()!=1){
        cout << st.top();
        st.pop();
    }

    //1 2 3 4 5  // 5 4 3 2 1
}