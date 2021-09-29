
#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		map<int,list<int>> adj;
		map<int,bool> vis;
		map<int,int> parent;
		
		void add(int u,int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}	
		void bfs(){
			queue<int> q;
			q.push(1);
			parent[1] = 1;
			vis[1] = true;

			while(!q.empty()){
				int u = q.front();
				q.pop();
				for(auto v : adj[u]){
					if(!vis[v]){
						vis[v] = true;
						parent[v]= u;
						q.push(v);
					}
				} 
			}
		}
		void solution(int n){
			bfs();
			vector<int> ans;
			while(true){
				ans.push_back(n);
				n = parent[n];
				if(n==parent[n]){
					ans.push_back(n);
					break;
				}
			}
			reverse(ans.begin(),ans.end());
			if(parent[n]==0){
				cout << "IMPOSSIBLE" << endl;
			}
			cout << ans.size()<< endl;
			for(auto each :ans){
				cout << each << " " ;
			}
			cout << endl;
		}
	
};

///approach ; explore bfsly/dfsly and keep track of the parent pointer whilst you do so.
int main(){

	int n,m;
	cin >> n >> m;
	
	Graph G;
	while(m--){
		int x,y;
		cin >> x >> y;
		G.add(x,y);
	}
	G.solution(n);
}