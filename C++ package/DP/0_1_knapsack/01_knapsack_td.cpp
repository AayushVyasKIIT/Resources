#include <bits/stdc++.h>

using namespace std;

#define mxn 102
#define mxw 1002


int static dp[mxn][mxw];
int solve(int wt[],int val[],int W,int n){
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
					  //i-1 bc idx 0,,,,n-1	//previous value
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}


int main(){
	//ini
	for(int i=0;i<mxn;i++)
		for(int j=0;j<mxw;j++)
			dp[i][j]  = 0; //this is the base condition in recursive solution
	int n;cin>>n;
	int wt[n];
	for(int i =0;i<n;i++){
		int x;cin >>x;
		wt[i] = x;
	}
	int val[n];
	for(int j=0;j<n;j++){
		int x;cin>>x;
		val[j] = x;
	}
	int W;cin >> W;
	cout <<"ans: "<<	solve(wt,val,W,n);
}
