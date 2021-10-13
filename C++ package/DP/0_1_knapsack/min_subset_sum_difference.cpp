#include <bits/stdc++.h>

using namespace std;


#define mxn 102
#define mxw 1002 
#define vi vector<int>

bool static dp[mxn][mxw];

//initialise
void initialise(int n,int W){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<W+1;j++){

			if(i==0){
				dp[i][j] = false; //n
			}
			if(j==0){
				dp[i][j] = true;//j
			}
		}
	}
}
//change the return type
vi solve(int arr[],int W,int n){
	initialise(n,W);	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			//choice diagram
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			} 

		}
	}
	vi numberline;
	for(int j=0;j<=W/2;j++){
		if(dp[n][j] == 1){
			numberline.push_back(j);
		}
	}
	return numberline;
}
// goal : minimise(sum(subset1) - sum(subset2)) given : no negative integers present
// sum(arr[]) = sum(subset1) + sum(subset2)


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
	
	int W=0;
	for(int i=0;i<n;i++){
		W+=arr[i];
	}


	//solve
	vi nl;
	nl = solve(arr,W,n);
	int ans =INT_MAX;
	for(int i=0;i<nl.size();i++){
		ans = min(ans, W-2*(nl[i]));
	}
	cout << ans << endl;


}
