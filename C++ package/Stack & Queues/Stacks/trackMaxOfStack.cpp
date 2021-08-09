#include <bits/stdc++.h>

using namespace std;

void PushMax(stack<int> &st,stack<int> &mx,int data){
    st.push(data);
    if(st.size()==1){
        mx.push(data);
        return;
    }
    if(data>=mx.top()){
        mx.push(data);
    }
}
void PopMax(stack<int> &st,stack<int> &mx){
    if(st.top()==mx.top()){
        st.pop();
        mx.pop();
        return;
    }
    st.pop();
    if(st.empty()){
        st.empty();
    }
}

int main(){

    stack <int> st;
    stack <int> mx;

    PushMax(st,mx,10);
    PushMax(st,mx,20);
    PushMax(st,mx,5);
    PushMax(st,mx,4);

    cout << mx.top() << endl;
    mx.pop();
    cout << mx.top() << endl;

    
    
}