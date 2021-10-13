#include<bits/stdc++.h>

using namespace std;

#define mxn 102
#define mxw 1002
bool static dp[mxn][mxw];

bool solve(int arr[],int W,int n){
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			if(arr[i-1] <= j){
				dp[i][j] = (dp[i-1][j - arr[i-1]] || dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}

int main(){
	int n;cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		int x;cin>>x;
		arr[i] = x;
	}
	int W;cin >> W;
	//ini
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){
			if(i==0){
				dp[i][j] = false;
			}
			if(j==0){
				dp[i][j] = true;
			}
		}
	}	
	cout << solve(arr,W,n);
}
