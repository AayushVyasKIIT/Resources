#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	//test case #1 : III
	//test case #2 : IV
	//tes case #3 : VI
	
	map<char,int> ri; //roman to integer mapping
	ri['I'] = 1;
	ri['V'] =             5;
        ri['X'] =             10;
        ri['L'] =              50;
	ri['C'] =              100;
	ri ['D'] =              500;
        ri['M'] =              1000;
	
	int prev = 0;
	int ans = 0;
	for(int i=0;i<s.size();i++){
		int curr = ri[s[s.size() - 1 - i]];
		
		if(prev <= curr){
			prev = curr;
			ans+=curr;
		}else{
			prev =curr;
			ans-=curr;
		}
	}
	cout << ans << endl;

}
