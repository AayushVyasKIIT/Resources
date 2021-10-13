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
				dp[i][j] = 1;//w
			}
		}
	}
}
//change the return type
int count_of_subsets_w_given_sum(int arr[],int W,int n){
	initialise(n,W);	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			//choice diagram
			if(arr[i-1] <=j){
				dp[i][j]  = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}

		}
	}
	
	return dp[n][W];
}
//problem statement : given arr[] find a subset with target sum, you can flip signs inorder to achieve the target.
//goal : we can see its boiling down to partitioning the array into 2 sets set1(+) - set2(-). 
//Here target = difference b/w sum(s1) - sum(s2) or in other words sum(s1) + sum(-s2) = target.

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
	int target; cin >> target;
	int sum  = 0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	//solve
	int s1 = (target + sum)/2;
	cout << count_of_subsets_w_given_sum(arr,s1,n) << endl;
	



}
