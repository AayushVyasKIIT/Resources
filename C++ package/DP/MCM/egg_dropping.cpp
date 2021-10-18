#include <bits/stdc++.h>

using namespace std;

int static dp[1002][1002];

int solve(int e,int f){
	if(e == 0 || f == 0){
		return 0;
	}
	if(f == 1){
		return 1;
	}
	if(e==1){
		return f;
	}
	int mn = INT_MAX;

	for(int k=1;k<=f;k++){ //f's value will take the range
		int low,high;
		if(dp[e-1][k-1] !=-1){
			low = dp[e-1][k-1];
		}else{

			low = solve(e-1,k-1);
		}
		if(dp[e][f-k] != -1){
			high = dp[e][f-k];
			
		}else{
			high = solve(e,f-k); //why f-k? because we are working with ranges.
		}

		int tempans = 1+ max(low,high); // we want the answer and for this we might want to consider the worst case attempts, as we cannot recover egg if thrown from high height, but from less height 
		// we can use that again to test for k+1 lvl.
		mn = min(tempans, mn);
	}
	return dp[e][f] = mn;

}


int main(){
	memset(dp,-1,sizeof(dp));
	int e; cin >> e;
	int f; cin >> f;
	
	cout <<	solve(e,f) << endl;

}
