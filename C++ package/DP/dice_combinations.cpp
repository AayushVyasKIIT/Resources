#include <bits/stdc++.h>

using namespace std;

int dp[7][10000000];

int solution(int arr[], int n){	
	for(int i = 1; i <= n;i++){
		dp[0][i] = 0;
	}
	for(int i = 0;i <7;i++){
		dp[i][0] = 1;
	} 

	for(int i = 1 ; i < 7 ; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i][j-arr[i-1]]%(1000000000+7) + dp[i-1][j]%(1000000000+7);
			}else{
				dp[i][j] = dp[i-1][j]%(1000000000+7);
			}
		}
	}
	for(int i=0;i<=6;i++){
		for(int j=0;j<=n;j++){
		
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[5][n];
}

int main(){
	memset(dp,-1,sizeof(dp));
	
	int n; cin >> n;
	int arr[] =  {1,2,3,4,5,6};
	//unbounded knapsack problem, where I can take an item as many times I want.
	cout <<	solution(arr,n) << endl;

}
