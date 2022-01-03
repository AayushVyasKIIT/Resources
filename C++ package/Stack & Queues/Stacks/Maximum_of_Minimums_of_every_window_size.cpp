#include <bits/stdc++.h>

using namespace std;

vector<int> prev_smallest(vector<int> &arr,vector<int> &prev_smaller){
	stack<int> s;
	prev_smaller.assign(arr.size() ,-1);
	for(int i = 0 ; i < arr.size();i++){
		while(!s.empty() and arr[s.top()] >= arr[i]){
			s.pop();
		}
		if(!s.empty()){
			prev_smaller[i] = s.top();
		}
		s.push(i);
	}
	return prev_smaller;
}
vector<int> next_smallest(vector<int> &arr,vector<int> &next_smaller){
	stack<int> s;
	next_smaller.assign(arr.size(),arr.size());
	for(int i=arr.size()-1;i>=0;i--){
		while(!s.empty() and arr[s.top()] >= arr[i]){
			s.pop();
		}
		if(!s.empty()){
			next_smaller[i] = s.top();
		}
		s.push(i);
	}
	return next_smaller;

}
vector<int> maxofmin(vector<int> arr){
	vector<int> next_smaller;
	vector<int> prev_smaller;
	prev_smallest(arr,prev_smaller);
	next_smallest(arr,next_smaller);
	vector<int> ans(arr.size()+1,0);
	for(int i=arr.size() - 1;  i  >= 0;i--){
		
		int range = next_smaller[i] - prev_smaller[i] - 1;
		cout <<arr[i] << " " <<  ans[range] << endl;
		ans[range] = max(ans[range],arr[i]);

	}
	for(int i= arr.size()-1;i>=1;i--){

		ans[i] = max(ans[i],ans[i+1]);
	}
	return ans;

}

int main(){

	int n; cin >> n;
	vector<int> arr;
	for(int i =0; i<n;i++){
		int x;cin >> x;
		arr.push_back(x);
	}	
	vector<int> ans  = maxofmin(arr);
	for(auto each : ans){
		cout << each << " ";
	}
	cout << endl;




}
