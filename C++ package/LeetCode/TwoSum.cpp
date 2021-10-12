#include<bits/stdc++.h>

#define pb push_back
using namespace std;

//commenting for the better:
void solve(vector<int> &arr,int sum){
	map<int,queue<int>> idx;
	for(int i=0;i<arr.size();i++){
		idx[arr[i]].push(i);
	}
	
	sort(arr.begin(),arr.end());
	int start = 0;
	int end = arr.size()-1;
	while(start<=end){
		if(arr[start]+arr[end] == sum){
			if(arr[start] == arr[end]){
				cout << "1" ;
				int a = idx[arr[start]].front(); idx[start].pop();
				int b = idx[arr[end]].front();
				cout << "[" << a <<"," << b << "]" <<endl;
				return;
			}
			int a = idx[arr[start]].front();
			int b = idx[arr[end]].front();
			cout << "[" << a  << "," <<  b << "]" << endl;
			return;
		}
		else if(arr[start] + arr[end] > sum){
			end --;
		}else{
			start ++;
		}
	}

}

int main(){
	
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.pb(x);
	}
	int sum;
	cin >> sum;
	solve(a,sum);
}
