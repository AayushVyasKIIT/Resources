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
				dp[i][j] = 1; //n
			}
			if(j==0){
				dp[i][j] = 0;//j
			}
		}
	}
}
//change the return type
bool subset_sum(int arr[],int W,int n){
	initialise(n,W);	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			//choice diagram
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] ||  dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
			
		}
	}
	return dp[n][W];
}
bool equal_partition(int arr[],int n){

	int sum = 0;
	for(int i =0;i<n;i++){
		sum += arr[i];
	}
	if(sum%2!=0){
		return false;
	}else{
		// if s1 == s2 then sum = s1 + s1 = 2s1, if sum/2 is present then other is also present
		return subset_sum(arr,sum/2,n);
	}
}



int main(){
	//if arr
	int n;cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr[i] = x;
	}
	//if string 
	//string s;cin>> s;

	//add next here
	


	//solve
	cout << equal_partition(arr,n) << endl;

}
