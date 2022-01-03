#include <bits/stdc++.h>

using namespace std;

//Problem : Given an array of strings words[], o/p the maximum product of lengths of 2 words such that words[i] and words[j] doesnot have any letters in common.

int MaxProductOfLenOfWords(vector<string> words){

	int n = words.size();
	
	vector<int> mask;
	vector<int> len;

	//pre-calculate the lengths of each word and store them in an array, where i represents the positioning of the word in the words array.
	for(int i = 0;i<n;i++){
		len.push_back(words[i].size());
	}
	mask.assign(n,0);
	int mx = INT_MIN;
	for(int i = 0 ; i < n ;i++){
		for(auto ch : words[i]){
			mask[i] = mask[i] | (1<<(ch - 'a'));
		}
		for(int j = 0 ;j<i;j++){
			if(!(mask[i] & mask[j])){
				mx = max(mx,len[i]*len[j]);		
			}
		}

	}	
	return mx;
}


int main(){
	
	//input;
	vector<string> words;
	int n;cin >> n;
	for(int i = 0; i<n;i++){
		string x;cin >> x;
		words.push_back(x);
	}
	cout << MaxProductOfLenOfWords(words) <<endl;

}
