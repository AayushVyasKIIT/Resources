#include <bits/stdc++.h>

using namespace std;

/*[200~There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is

hi.

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone

N:

    If the frog is currently on Stone 

    i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi−hj∣ is incurred, where

        j is the stone to land on.

	Find the minimum possible total cost incurred before the frog reaches Stone
	N.
*/

int static dp[1002];
int solve(int ht[],int n){
	int ans = 0;
	if(n==1){
		return 0;
	}
	if(n==2){
		return abs(ht[1]-ht[2]);
	}
	if(dp[n] != -1){
		return dp[n];
	}
	if(n>2){
		int iplus1 = solve(ht,n-1) + abs(ht[n] - ht[n-1]);
		int iplus2 = solve(ht,n-2) + abs(ht[n] - ht[n-2]);
		ans = min(iplus1,iplus2);

	}

	return dp[n] = min(iplus1,iplus2);

}




int main(){
	memset(dp,-1,sizeof(dp));
	int N;cin >> N;
	int ht[N];
	for(int i=0;i<N;i++){
		int x;cin >> x;
		ht[i] = x;
	}
	cout <<	solve(ht,N-1);
}
