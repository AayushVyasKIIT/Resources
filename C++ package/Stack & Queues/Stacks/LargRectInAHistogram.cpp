#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    stack<int> stack;
    stack.push(0);
    int ans=0;
    for(int i=0;i<arr.size();i++){
        while(!stack.empty() and arr[stack.top()]>arr[i]){
            int t=stack.top();
            int h =arr[t];
            stack.pop();
            if(stack.empty()){
                ans = max(ans,i*h);
            }else{
                int l = i-stack.top()-1;
                ans = max(ans,l*h);
            }
            
        }
        stack.push(i);
    }
    cout << ans << endl;
}