#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
	if(p1.second < p2.second){
		return true;
	}
	return false;
}
int solve(vector<pair<int,int>> req){
	sort(req.begin(),req.end(),comp);
	int ans = 1;
	int k=0;
	for(int i=1;i<req.size();i++){
		if(req[i].first >= req[k].second){
			k=i;
			ans++;

		}
	}
	return ans;
}
int main(){

	int n;cin >> n;
	int m;cin >> m;
	vector<pair<int,int>> req;
	for(int i=0;i<m;i++){
		int x1,x2;
		cin >> x1 >> x2;
		req.push_back({x1,x2});
	}
	cout << solve(req) << endl;

}
