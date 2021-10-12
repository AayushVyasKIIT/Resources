#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> arr;
	for(int i =0;i<n;i++){
		int x; cin>> x;
		arr.push_back(x);
	}
	int k; cin >> k;
	
	int i=0,j=0;
	list<int> l;
	vector<int> ans;
	int mx=INT_MIN;
	while(j<n){
		while(!l.empty() and arr[j] > l.back()){
			l.pop_back();
		}
		l.push_back(arr[j]);
		if(j-i+1 < k){
			j++;

		}else if(j-i+1 == k){
			
			mx = l.front();
			ans.push_back(mx);
			if(arr[i] == mx){
				l.pop_front();
			}
			i++;
			j++;
		
		}	

	}
	for(auto each : ans){
		cout << each <<" ";
	}


}
