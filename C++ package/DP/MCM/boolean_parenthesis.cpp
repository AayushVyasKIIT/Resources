#include <bits/stdc++.h>

using namespace std;
unordered_map<string,int> dp;

int solve(string s,int i,int j,bool isTrue){
	if(i>j){
		return 0;	
	}
	if(i==j){
		if(isTrue == true){
			return s[i] == 'T';
		}else{
			return s[i] == 'F';
		}
	}
	string key = to_string(i) + " " + to_string(j);
	if(dp.find(key)!=dp.end()){
		return dp[key];
	}
	int ans=0;
	for(int k=i+1;k<=j-1;k+=2){
		int LT  = solve(s,i,k-1,true);
		int RT = solve(s,k+1,j,true);
		int LF = solve(s,i,k-1,false);
		int RF = solve(s,k+1,j,false);
		if(s[k] == '&'){
			if(isTrue == true){
				ans+= LT*RT;
			}else{
				ans+= LT*RF + LF*RF + LF*RT;
			}
		}else if(s[k] == '|'){
			if(isTrue == true){
				ans+=LT*RT + LT*RF + RT*LF;
			}else{
				ans+=LF*RF;
			}

		}else if(s[k] == '^'){
			if(isTrue == true){
				ans+= LT*RF + RT*LF;
			}else{
				ans+= LT*RT + RF*LF;
			}

		}
	}
	return dp[key] = ans;
}

int main(){
	string s;cin>> s;
	int i=0,j=s.size()-1;
	cout << solve(s,i,j,true) << endl;
}
