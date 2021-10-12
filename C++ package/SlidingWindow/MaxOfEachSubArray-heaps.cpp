#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;cin >> n;
	vector<int> arr;
	for(int i =0;i<n;i++){
		int x;
		cin>> x;
		arr.push_back(x);
	}
	int k;cin>> k;

	int i =0,j = 0;
	int mx = INT_MIN;
	vector<int> ans;
	priority_queue<int> pq;
	while(j<n){

		pq.push(arr[j]);
		if(j-i+1 < k){
			j++;
		}else if(j-i+1 == k){
			mx = max(pq.top(),mx);
			ans.push_back(mx);

			if(pq.top() == arr[i]){
				pq.pop();
			}
			i++;
			j++;
		}	

	}
	for(auto e : ans){
		cout << e << " ";
	}


}
