#include <bits/stdc++.h>

using namespace std;

struct job{
	int s;
	int f;
	int val;
};

bool cmp(job a,job b){
	if(a.f < b.f){
		return 1;
	}
	return 0;
}
//returns the index of the last compatible interval(finish time) 
int bs(job j[],int i){
	int low = 0;
	int high = i;
	//binary search iterative
	while(low<=high){
		int mid = (low+high)/2;
		if(j[mid].f <= j[i].s){
			if(j[mid+1].f <= j[i].s){
				low = mid+1;
			}else{
				return mid;
			}
		}else{
			high = mid-1;
		}
	}
	return -1;
}
int solve(job j[],int n){
	sort(j,j+n,cmp);
	int dp[n];
	dp[0] = j[0].val;
	
	for(int i=1;i<n;i++){
		int inclval = j[i].val;
		int compatible = bs(j,i);
		if(compatible!=-1){
			inclval += dp[compatible];
		}
		dp[i] = max(inclval,dp[i-1]);
	}
	return dp[n-1];

}


int main(){
	int n;cin >> n;
	job j[n];
	int s,f,val;
	for(int i=0;i<n;i++){
		cin >> s >> f >> val;
		j[i].s = s;
		j[i].f = f;
		j[i].val = val;
	}
	cout <<	solve(j,n);

	
}
