#include <bits/stdc++.h>

using namespace std;


void nge(vector<int> arr,int n){
	
	stack<int> s;
	int res[n];
	for(int i= n-1;i>=0;i--){
		if(!s.empty()){

			while(!s.empty() and s.top() <= arr[i]){
				s.pop();
			}
		}
		if(s.empty()){
			res[i] = -1;
		}else{
			res[i] = s.top();
		}
		s.push(arr[i]);
	}
	for(int i = 0 ; i < n;i++){
		cout << res[i] << " ";
	}
}





int main(){
	int n;cin>> n;
	vector<int> arr;
	for(int i = 0;i<n;i++){
		int x; cin >> x;
		arr.push_back(x);
	}
	
	nge(arr,n);


}
