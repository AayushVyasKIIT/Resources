#include<bits/stdc++.h>

using namespace std;

class Graph{
public:
	map<int,list<int>> adj;
	map<int,bool> vis;
	map<int,int> distance;

	//undirected grap
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void bfs(int source,int n){
		queue<int> q;
		q.push(source);
		vis[source] = true;
		distance[source] = 0;
		while(!q.empty()){
			
			int u = q.front();
			cout << u << " ";
			q.pop();
			for(auto v : adj[u]){
				if(!vis[v]){
					vis[v] = true;
					distance[v]+=distance[u] + 6;
					q.push(v);
				}
			}
			
		}
		for(int i=1;i<=n;i++){
			if(distance[i] or i==source){
				cout << distance[i] << " " ;
			}else{
				cout << -1  <<  " " ;
			}
		}
		cout << endl ;
		
	}

};


int main(){

	Graph G;
	G.addEdge(1,2);
	G.addEdge(2,3);
	G.addEdge(3,7);
	G.addEdge(3,4);
	G.addEdge(4,5);
	G.bfs(1,7);

	
	
}
