#include <bits/stdc++.h>

using namespace std;
int strictly_increasing_index(vector<stack<int>> stacks,stack<int> &discs){
    int min_idx = 0;
    int mn = INT_MAX;
    for(int i=0;i<stacks.size();i++){
        if((stacks[i].top()-discs.top())>0 &&(stacks[i].top()-discs.top()) < mn){
            mn = abs(discs.top()-stacks[i].top());
            min_idx =i;
        }
    }
    return min_idx;
}

vector<stack<int>> solution(stack<int> &discs){
    vector<stack<int>> sol;

    while(!discs.empty()){
        if(sol.size()==0){
            stack<int> newStack;
            newStack.push(discs.top());
            discs.pop();
            sol.push_back(newStack);
        }
        int min_idx = strictly_increasing_index(sol,discs);
        if(discs.top()<sol[min_idx].top()){
            sol[min_idx].push(discs.top());
            discs.pop();
                
        }else{
            stack<int> newStack;
            newStack.push(discs.top());
            discs.pop();
            sol.push_back(newStack);
        }
        
    }
    return sol;
}
void printOutput(vector<stack<int>> sol){
    for(int i=0;i<sol.size();i++){
        cout << sol[i].top() << " ";
    }
}

int main(){
    int T,n;
    cin>> T;
    while(T--){
        cin >> n;
        stack<int> d;
        for(int i=0;i<n;i++){
            int input;
            cin >> input;
            d.push(input);
        }
        stack<int> discs;
        for(int i=0;i<n;i++){
            int input;
            discs.push(d.top());
            d.pop();
        }
      
        vector<stack<int>> lol = solution(discs);
        printOutput(lol);
        
        //call your function here.
        
    }
    
    
}