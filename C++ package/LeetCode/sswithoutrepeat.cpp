#include <bits/stdc++.h> 
 
using namespace std; 
 
int main(){ 
 
        string s;cin>> s;
	int start = -1;
	map<int,int> idx;
	for(int i=0;i<s.size();i++){
		idx[s[i]] = -1;
	}
	int ans = 0;
	for(int i=0;i<s.size();i++){
		if(idx[s[i]] > start){
			start = idx[s[i]];
		}
		idx[s[i]] = i;
		ans = max(ans,i-start);


	}
	cout << ans << endl;
}
