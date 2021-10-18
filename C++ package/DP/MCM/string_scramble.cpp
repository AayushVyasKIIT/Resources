#include<bits/stdc++.h>

using namespace std;

unordered_map<string,bool> dp;

bool scrambled(string s1,string s2){
	if(s1.compare(s2) == 0){
		return true;
	}if(s1.length() <=1){
		return false;
	}
	string key = s1 + ' ' + s2;
	if(dp.find(key)!=dp.end()){
		return dp[key];
	}

	int n = s1.size()-1;
	bool flag = false;
	for(int i=1;i<=n-1;i++){
		if(((scrambled(s1.substr(0,i),s2.substr(n-i,i))==true and scrambled(s1.substr(i,n-i),s2.substr(0,n-i)==true)) == true) || ((scrambled(s1.substr(0,i),s2.substr(0,i)) == true and scrambled(s1.substr(i,n-i),s2.substr(i,n-i)) ==true ))){
			flag = true;
			break;
		}
	}
	return dp[key] = flag;

}

int main(){
	string s1,s2; cin >> s1 >> s2;
	if(s1.length() != s2.length()){
		cout << 0 << endl;
	}
	cout <<	scrambled(s1,s2) << endl;
	
}
