#include <bits/stdc++.h>

using namespace std;

int rainwater(vector<int> pillars){
    int water = 0;
    stack<int> stack;
    for(int i=0;i<pillars.size();i++){
        while(!stack.empty() && pillars[i]>pillars[stack.top()]){
            int t = stack.top();
            int height =pillars[stack.top()];
            stack.pop();
            if(stack.empty()){
                break;
            }
            int l = i - stack.top() -1;
            int h = min(pillars[i],pillars[stack.top()]/*this is the next element(from R->L))-pillars[t]//t is the current element*/)-pillars[t];
            water+= l*h;
        }
        stack.push(i);
    }
    return water;
}
int main(){
    vector<int> pillars = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << rainwater(pillars);   
}