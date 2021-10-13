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
				dp[i][j] = 0;//j
			}
		}
	}
}
//change the return type
int solve(int arr[],int price[], int W,int n){
	initialise(n,W);	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			//choice diagram
			if(arr[i-1] <=j){
				dp[i][j] = max(price[i-1] + dp[i][j-arr[i-1]], dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j-1];
			}
		}
	}
	return dp[n][W];
}
//goal: given a rod of length l, with cost associate with each length
// cut_length : [1,2,3......n]
// price : [p1,p2,p3,....pn]
// lenght : total length(int)
// o/p: the maximum profit you can make 
// solution : pure unbounded knapsack
int main(){
	//if arr
	int n; cin >> n;
	int arr[n]; // here arr -> coin
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr[i] = x;
	}
	//if string 
	//	string s;cin>> s;

	//add next here
	int price[n];
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		price[i] = x;
	}
	int length; cin >> length; //corresponds to W

	cout <<	solve(arr,price,length,n) << endl;
}
