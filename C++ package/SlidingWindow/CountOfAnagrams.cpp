#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;cin>> s;
	string anagram; cin>> anagram;
	int k = anagram.size();

	unordered_map<char,int> mp;
	for(int i=0;i<anagram.size();i++){
		mp[anagram[i]] +=1;
	}
	int uniCount = mp.size(); //how many unique elements are present 
	//mp contains their respective count
	int ans = 0;
	int i = 0,j = 0;
	while(j<s.size()){
		if(mp.find(s[j])!=mp.end()){
				mp[s[j]]--; //we decrement the individual count
				if(mp[s[j]] == 0){ // see if a char count is completely used, if yes we decrease unicount
					uniCount --;
				}
		}
		if(j-i+1 < k){
			j++;
		}else if(j-i+1 == k){
			if(uniCount == 0){
				ans++;
			}

			if(mp.find(s[i])!=mp.end()){ //IMP : if s[i] belongs to anagram, we need to free it here before we move the window forward.

				mp[s[i]]++; // we free it by increase it count 
				if(mp[s[i]]>0){ //increase that  
					uniCount++;
				}
			}
			i++;
			j++;

		}
	}
	cout << ans << endl;
}

