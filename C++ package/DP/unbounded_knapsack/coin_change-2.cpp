#include <bits/stdc++.h>

using namespace std;


#define mxn 102
#define mxw 1002 

int static dp[mxn][mxw];

//initialise
void initialise(int n,int W){
	//first initialisation
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){

			if(i==0){ //this states that we have 0 coins but we are to make a sum of j, ans : we might need INF coins to make this sum
				dp[i][j] = INT_MAX-1; //INT_MAX -1 to prevent memory flow.
			}
			if(j==0){
				dp[i][j] = 0;//j
			}
		}
	}
}
//change the return type
int solve(int arr[],int W,int n){
	initialise(n,W); //first initialisation
	//second initialisation
	for(int j =1;j<W+1;j++){
		if(arr[0]%j==0){
			dp[1][j] = j/arr[0];
		}else{
			dp[1][j] = INT_MAX-1;
		}
	}
	for(int i=2;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			//choice diagram
			if(arr[i-1] <= j){
				dp[i][j]= min(dp[i][j-arr[i-1]] + 1, dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[n][W];
}
//goal  : find the minimum number of coins to make a particular sum
//IMP : this problem is one of a kind problem which requires a second initialisation process.



int main(){
	//if arr
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr[i] = x;
	}
	//if string 	string s;cin>> s;

	//add next here

	

	int W;cin >> W;
	//solve
	cout << solve(arr,W,n) << endl;

}
