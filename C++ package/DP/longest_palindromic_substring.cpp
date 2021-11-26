#include <bits/stdc++.h>


using namespace std;

string solution(string s){
	
	int n = s.size();
	
	int best_len = 0;
	string best_s = "";
	//case 1 : odd length substrings
	for(int mid = 0 ;mid < n;mid++){
		for(int x = 0; mid-x>=0 and mid+x<n;x++){
			if(s[mid-x]!=s[mid+x]){
				break;
			}

			int len = 2*x + 1;
			if(best_len < len){
				best_len = len;
				best_s = s.substr(mid-x,len);
			}
		}
	}
	//case 2: even length substrings
	for(int mid = 0;mid<n-1;mid++){
		for(int x = 1; mid-x+1 >= 0 and mid+x<n;x++){
			if(s[mid-x+1] != s[mid+x]){
				break;
			}
			int len = 2*x;
			if(best_len < len){
				best_len = len;
				best_s = s.substr(mid-x+1,len);
			}
		}
	}

	return best_s;
	
}

int main(){
	string s; cin >> s;
	cout <<	solution(s) << endl;
}
