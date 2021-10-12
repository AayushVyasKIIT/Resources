#include <bits/stdc++.h>

using namespace std;

int recFib(int n){
    
    map<int,int> memo;
    
    if(memo[n])
        return memo[n];
    if(n<=2)
        return 1;
    else
        return recFib(n-1) + recFib(n-2);
    return memo[n]; 
    
}
int fibBottomUp(int n){
    map<int,int> memo;
    int f;
    for(int i=0;i<=n;i++){
        if(i<=2){
            f = 1;
        }else{
            f = memo[i-1] + memo[i-2];
        }
        memo[i] = f;
    }
    return memo[n];
}

int main(){
    cout <<"Using recursive DP" <<recFib(10);
    cout <<"Using Bottom-up approach" << fibBottomUp(10);
}
