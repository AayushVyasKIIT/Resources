#include <bits/stdc++.h>

using namespace std;


#define mxn 102
#define mxw 1002 

int static dp[mxn][mxw];

//initialise
void initialise(int n,int W){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){

			if(i==0){
				dp[i][j] = 0; //n
			}
			if(j==0){
				dp[i][j] = 1;//j
			}
		}
	}
}
//change the return type
int solve(int arr[] ,int W,int n){
	initialise(n,W);	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			//choice diagram
			if(arr[i-1] <= j){
				dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
				//ways(including it) + ways(not including it)
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][W];
}
// goal : find the maximum number of ways(coins through which we can make a particular sum of money
// base idea : count of subset with given sum



int main(){
	//if arr
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr[i] = x;
	}
	//if string 
//	string s;cin>> s;

	//add next here

	int money;cin >> money;
	//solve
	cout << solve(arr,money,n) << endl;

}
