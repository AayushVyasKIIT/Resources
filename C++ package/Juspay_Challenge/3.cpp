#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define ii pair<int,int>
#define edge tuple<int,ll,ll>
#define INF 1e4

class max_flow{
	private:
		int V;
		vector<vi> AL;
		vector<edge> EL;
		vi d,last;
		vector<ii> p;

		bool BFS(int s,int t){
			d.assign(V,-1);
			d[s] = 0;
			queue<int> q({s});
			p.assign(V,{-1,-1});

			while(!q.empty()){

				int u = q.front() ; q.pop();
				if(u==t){
					break;
				}
				for(auto &idx : AL[u]){
					auto v = get<0>(EL[idx]);
					auto cap = get<1>(EL[idx]);
					auto flow = get<2>(EL[idx]);
					if((cap-flow) > 0 and d[v]==-1){
						q.push(v);
						d[v] = d[u]+1;
						p[v] = {u,idx};
					}

				}
			}
			return d[t]!=-1;

		}
		ll send_one_flow(int s,int t,ll f=INF){
			if(s==t){
				return f;
			}
		
			auto u = p[t].first;
			auto idx = p[t].second;
			auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
			
			ll pushed = send_one_flow(s,u,min(f,cap-flow));

			flow += pushed;
			auto &rflow = get<2>(EL[idx^1]);
			rflow -= pushed;

			return pushed;
		}
	public:
		max_flow(int initialV):V(initialV){
			EL.clear();
			AL.assign(V,vi());
		}

		void add_edge(int u,int v,ll w,bool directed = true){
			if(u==v){
				return;
			}
			EL.emplace_back(v,w,0);
			AL[u].push_back(EL.size()-1);

			EL.emplace_back(v,directed?0:w,0);
			AL[v].push_back(EL.size()-1);
		}
		ll edmonds_karp(int s,int t){
			ll maxflow = 0;

			while(BFS(s,t)){

				ll flow = send_one_flow(s,t);
				if(flow==0){
					break;
				}
				maxflow+=flow;
			}

			return maxflow;
		}
		//helper function : for finding the set of vertices that are reachable from s. S
		/*
		 * BFS and add reachable vertices.
		 */
		vector<ll> reachable_set(int s){
			vector<ll> ans;
			vector<int> dist;

			dist.assign(V,-1);
			dist[s] = 0;
			queue<int> q({s});
			ans.push_back(s);	
			while(!q.empty()){
				int u = q.front();q.pop();
				for(auto &idx : AL[u]){
					auto v = get<0>(EL[idx]);
					auto cap = get<1>(EL[idx]);
					auto flow = get<2>(EL[idx]);
					if((cap-flow) > 0 and dist[v]==-1){
						ans.push_back(v);
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}

			return ans;
			
		}
		//helper function : finds if there exist a edge from i to j
		//look for all neighbours of i if j exist or not.
		bool isEdge(int i,int j){
			for(auto &idx : AL[i]){
				if(j ==get<0>(EL[idx])){
					return true;
				}
			}
			return false;

		}
};
int main() {

  std::ios::sync_with_stdio(false);

 
  int n; cin >> n;	
  int mx = INT_MIN;
  for(int i=0;i<n;i++){
	  int x;cin >> x;
	  mx = max(x,mx);
  }
  max_flow maxf(mx+1);
  int m; cin >> m;
  for(int i =0;i<m;i++){
	  int u,v;cin >> u >> v;
	  maxf.add_edge(u,v,1,false);
  }	
  int s,t; cin >> s >> t;
cout <<  maxf.edmonds_karp(s,t) << endl;

	vector<ll> scomp,tcomp;	
	scomp = maxf.reachable_set(1);

	for(int i=0;i<n+1;i++){
		if(find(scomp.begin(),scomp.end(),i) == scomp.end()){
			tcomp.push_back(i);
		}
	}
	for(auto &i : scomp){
		for(auto &j : tcomp){
			if(maxf.isEdge(i,j)){
				cout << i << " " << j << endl;
			}
		}
	}
}
