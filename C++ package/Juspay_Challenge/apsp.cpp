#include <bits/stdc++.h>

using namespace std;

class DSU{
	public:
		vector<int> p,depth;
		DSU(int n){
			p.assign(n,-1);
			depth.assign(n,0);
			for(int i =0;i<n;i++){
				p[i] = i;
			}
		}
		int findSet(int i){
			if(p[i] == i){

				return i;
			}
			return p[i] = findSet(p[i]);
		}
		void unionSet(int i,int j){
			if(findSet(i) == findSet(j)){
				return;
			}
			int x = findSet(i);
			int y = findSet(j);

			if(depth[x] > depth[y]){
				swap(x,y);
			}
			p[x] = y;
			if(depth[x] == depth[y]){
				depth[y] ++;
			}
		}


};



int main(){
	int n; cin >> n;
	int mx = INT_MIN;
	for(int i =0;i<n;i++){
		int x;cin >> x;
		mx = max(mx,x);
	}
	DSU d(mx+1);
	int m;cin >> m;	
	for(int i =0;i<m;i++){
		int u,v;
		cin >> u >> v;
		d.unionSet(u,v);
	}
	int s; cin >> s;
	int t; cin >> t;
	if(d.findSet(s) == d.findSet(t)){
	
		cout << 1 <<endl;


	}else{
		cout << 0 << endl;
	}




}
