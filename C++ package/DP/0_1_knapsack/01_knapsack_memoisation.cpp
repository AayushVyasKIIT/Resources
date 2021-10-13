#include <bits/stdc++.h>

using namespace std;

#define mxn 102 // 0 <= n <= 100
#define mxw 1002 // 0 <= W <= 1000

int static dp[mxn][mxw];

int knapsack(int wt[],int val[],int W,int n){
	//base condition 
	if(n==0 || W==0){
		return 0;
	}
	//choise diagram
	if(dp[n][W] != -1){
		return dp[n][W];
	}
	if(wt[n-1] <= W){
		return dp[n][W] = max(val[n-1] + knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1)); 
				//value added        Total capacity - wt          value not included 
	}else if(wt[n-1] > W){
		return dp[n][W] = knapsack(wt,val,W,n-1); //W not reduced and value also not added 
	}
}


int main(){
	
	memset(dp,-1,mxn*sizeof(dp[0])); //fill with -1
	//take input
	int n;cin>>n;
	int wt[n],val[n];

	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		wt[i] = x; 
	}
	for(int i =0;i<n;i++){
		int x;
		cin >> x;
		val[i] = x;
	}
	int W; cin >> W;
	cout << "ans:"  << knapsack(wt,val,W,n);



}
