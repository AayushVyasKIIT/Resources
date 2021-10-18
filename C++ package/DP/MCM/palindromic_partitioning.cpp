#include <bits/stdc++.h>

using namespace std;
#define mxn 1002
#define mxw 1002

int static dp[mxn][mxw];

int solve(string s,int i,int j){
	if(i>=j){
		return 0;
	}
	int mn = INT_MAX;
	for(int k=i;k<=j-1;k++){ //decide bounds of k
		int left,right;
		if(dp[i][k] !=-1){
			left = dp[i][k];
		}else{
			left = solve(s,i,k);
		}
		if(dp[k+1][j] !=-1){
			right = dp[k+1][j];
		}else{
			right = solve(s,k+1,j);
		}
		int tempans = 1+left+right;
		mn = min(tempans,mn);
	}
	return dp[i][j] = mn;
	
}


int main(){
	memset(dp,-1,sizeof(dp));
	string s;cin >> s;
	//choose i and j;
	int i = 0, j = s.size()-1;
	int n = s.size();
	cout << solve(s,i,j) << endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

}
