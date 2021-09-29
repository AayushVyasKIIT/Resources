/**
	@file 
	@brief util file for using graph class ,weighted (Directed/Undirected)
 */

#include <bits/stdc++.h> 

using namespace std;

class Graph{
	private:
    	public:
		map<int,list<pair<int,int>>> adj;
		map<int,bool> vis;
	
		void addDirected(int u,int v,int w){    
			adj[u].push_back({v,w});
		}
		void addUndirected(int u,int v,int w){
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		void print(){
			for(auto each: adj){
				cout << each.first << ":" ;
				for(auto e : adj[each.first]){
					printf("%d(%d)->",e.first, e.second);
				}
				cout << "x" << endl;
			}
		}

};

