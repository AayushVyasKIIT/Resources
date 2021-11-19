#include <bits/stdc++.h>

using namespace std;

struct job{
	int i;
	int s;
	int f;
};

bool cmp(job a,job b){
	if(a.f < b.f){
		return 1;
	}
	return 0;
}
//returns the index of the last compatible interval(finish time) 
int solve(job j[],int n){
	sort(j,j+n,cmp);
	
	vector<job> ans;
	ans.push_back(j[0]);
	for(int i=1;i<n;i++){
		if(j[i-1].f <= j[i].s){
			ans.push_back(j[i]);
		}
	}
	for(auto each : ans){
		cout << each.i << " ";
	}
	cout << endl;
	return 0;
}


int main(){
	int n;cin >> n;
	job j[n];
	int s,f,val;
	for(int i=0;i<n;i++){
		cin >> s >> f >> val;
		j[i].i = val;
		j[i].s = s;
		j[i].f = f;
	}
	cout <<	solve(j,n);

	
}
