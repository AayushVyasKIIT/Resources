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
int number_of_subsets_w_given_sum(int arr[],int W,int n){
	initialise(n,W);	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			//choice diagram
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}

		}
	}
	
	return dp[n][W];
}

//goal : find subsets count( [S1,S2 ... .Sn]) such that s1 - s2 = difference(given)
// how : Assuming we have found 2 sets
// sum(s1)  - sum(s2) = difference(given)
// sum(s1) + sum(s2) = sum(obvious)
// solving these equations will give us s1 = (difference + sum)/ 2;
// problems boils down to finding subsets with sum(s1) 
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
	//step1 : find sum(s1)
	int sum = 0;
	for(int i =0; i<n;i++){
		sum+=arr[i];
	}
	int d; cin >> d;
	int s1 = (d + sum)/2;
	


	//solve
	cout << number_of_subsets_w_given_sum(arr,s1,n) << endl;

}
