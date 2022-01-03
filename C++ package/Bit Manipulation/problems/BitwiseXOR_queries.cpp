#include<bits/stdc++.h>

using namespace std;

vector<int> BITXOR(vector<int> arr,vector<vector<int>>  queries){
	//we pre-compute xor, using prefix sum.
	int n = arr.size();
	vector<int> prefix_xor;
	prefix_xor.push_back(arr[0]);
	for(int i =1; i<n;i++){
		prefix_xor.push_back(prefix_xor[i-1]^arr[i]);
	}
	vector<int> ans;
	for(auto each : queries){
		int left = each[0];
		int right = each[1];

		int curr= prefix_xor[right];
		if(left > 0) curr^=prefix_xor[left-1];
		ans.push_back(curr);
	}
	
	return ans;
}

int main(){

	int n; // size of array
	cin >> n;
	int m;
	cin >> m; //size of queries
	vector<int> arr;
	for(int i =0;i<n;i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	vector<vector<int>> queries;
	for(int j =0;j<m;j++){
		int left, right;
		cin >> left >> right;
		queries.push_back({left,right});
	}
	vector<int> ans;
	ans = BITXOR(arr,queries);
	for(auto each : ans){
		 cout << each << " ";
	}
	cout << endl;
	




}
