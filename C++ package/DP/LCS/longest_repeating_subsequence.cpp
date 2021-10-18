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
int LCS(string s1,string s2,int n,int m){
	initialise(m,n);	
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			//choic:e diagram
			if(s1[i-1] == s2[j-1] and i!=j){
				dp[i][j] = 1+dp[i-1][j-1]; // if both same then add 1
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	return dp[m][n];
}

//goal :Given a single string you need to find out length of longest repeating subsequence



int main(){
	//if arr
//	int n; cin >> n;
//	int arr[n];
//	for(int i=0;i<n;i++){
//		int x;
////		cin >> x;
		//arr[i] = x;
	//}
	////if string 
	string s1;cin>> s1;
	string s2; s2 = s1;


	//add next here
	int m = s1.size();
	int n = s2.size();


	//solve
	cout <<	LCS(s1,s2,n,m) << endl; 

}
