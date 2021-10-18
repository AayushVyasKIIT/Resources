#include <bits/stdc++.h>

using namespace std;
#define mxn 1002
#define mxw 1002

int static dp[mxn][mxw];

int solve(int arr[],int i,int j){
	if(i>=j){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int mn = INT_MAX;
	for(int k=i;k<=j-1;k++){ //decide bounds of k
		int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
		mn = min(tempans,mn);
	}
	return dp[i][j] = mn;
	
}


int main(){
	memset(dp,-1,sizeof(dp));
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		int x; cin >>x;
		arr[i] = x;
	}
	//choose i and j;
	int i = 1, j = n-1;
	cout << solve(arr,i,j) << endl;
}
