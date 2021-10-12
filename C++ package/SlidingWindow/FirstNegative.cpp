#include<bits/stdc++.h>

using namespace std;

int main(){
	//goal is to find the first -ve number in every window of size k
	int n; cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	int k;cin >> k;
	queue<int> q;
	vector<int> ans;
	int i =0,j=0;
	while(j<n){
		if(arr[j] < 0){
			q.push(arr[j]);
		}
		if(j-i+1 < k){
			j++;
		}else if(j-i+1 == k){
			//do some calculations
			if(q.empty()){
				ans.push_back(0);	
			}else{
				ans.push_back(q.front()); //the fisrt negative number on the queue will surely be stored here.
				if(arr[i] == q.front()){ //if we have a number that will be remove from the window in next itr, we remove it from the queue
					q.pop();
				}

			}
			i++;
			j++;

		}
	
	}
	for(auto each : ans){
		cout << each << " ";
	}
}
