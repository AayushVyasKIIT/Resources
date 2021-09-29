#include "stdWeightedG.h"
#define INF INT_MAX
/**
*@param T for which you want the distance for.

**/
void dijsktra(Graph &G,int n,int s,int t,int T){
	map<int,int> pi; //predecessor of i;
	set<pair<int,int>> pq; //just because priority queue doesnot have the functionality to decrease-key.(update key).
	vector<int> dist(n,INF);
	dist[s] = 0;
	for(int u=0;u<n;u++){
		pq.insert({dist[u],u});
	}

	while(!pq.empty()){
		auto [d,u] = *pq.begin();
		pq.erase(pq.begin());

		for(auto &[v,w] : G.adj[u]){
			if(dist[u]+w >= dist[v]){
				continue;
			}
			pq.erase(pq.find({dist[v],v}));
			dist[v] = dist[u] + w;
			pq.insert({dist[v],w});
		}
		

	}
	if(dist[t]!=INF){
		-printf("Case #%d : %d\n",T,dist[t]);
	}else{
		printf("Case #%d : unreachable\n",T);
	}

}

int main(){


	int T;cin>>T;
	int i=T;
	while(T--){
		int n,m,s,t;
		cin >> n >> m >> s >> t;

		Graph G;
		while(m--){
			int u,v,w;
			cin>> u >> v >> w;
			G.addUndirected(u,v,w);
		}
		dijsktra(G,n,s,t,i-T);
	}



}
