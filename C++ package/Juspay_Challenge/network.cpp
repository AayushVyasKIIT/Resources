#include <bits/stdc++.h>

using namespace std;

#define INF 1000000

class graph{
	public:
		map<int,list<pair<int,int>>> adj;

		void addEdge(int u,int v,int w){
			adj[u].push_back({v,w});
		}
		/*void print(){
			for(auto each : adj){
				int u= each.first;
				cout << u << "->";	
	
				for(auto &[v,w] : adj[u]){
					cout << v << " ";
				}
				cout << endl;
			}
		}*/
		void dijsktra(int source,int target,int n){
			vector<int> dist(n+1,INF);
			dist[source] = 0;
			set<pair<int,int>> pq;
			for(int u = 0;u <= n; u++){
				pq.insert({dist[u],u});
			}
			while(!pq.empty()){
				auto p =*pq.begin();
				int d = p.first;
				int u = p.second;
				pq.erase(pq.begin());

				for(auto each : adj[u]){
					int v = each.first;
					int w = each.second;
					if(dist[u] + w >= dist[v]){
						continue;
					}

					pq.erase(pq.find({dist[v],v}));
					dist[v] = dist[u] + w;
					pq.insert({dist[v],v});

				}


			}
;
			cout << dist[target] << endl;

		}
};


int main(){
	int n;cin >> n;
	int x;
	int mx = INT_MIN;
	for(int i =0;i<n;i++){
		cin >> x;
		if(x>mx){
			mx = x;
		}
	}
	graph g;
	int m;cin >> m;

	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		g.addEdge(u,v,w);
	}

	int source; cin >> source;
	int target; cin >> target;

	g.dijsktra(source,target,mx);



}
