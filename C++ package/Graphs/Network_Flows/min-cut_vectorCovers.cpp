#include <bits/stdc++.h>
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
					auto &[v,cap,flow] =  EL[idx];
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
			auto &[u,idx] = p[t];
			auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);

			ll pushed = send_one_flow(s,u,min(f,cap-flow));

			flow += pushed;
			auto &rflow = get<2>(EL[idx^1]);
			rflow -= pushed;

			return pushed;
		}

	public:
		max_flow(int initialV) : V(initialV) {
			EL.clear();
			AL.assign(V, vi());
		}
		void print_edges(){	
			cout << "--------------Network flow-----------------" << endl;
			cout << "s-> ";
			for(auto idx : AL[0]){
				cout << get<0>(EL[idx]) << " ";
			}
			cout << "\n\nnetwork matchings:" << endl;
			for(int i=1;i<V-1;i++){
				cout <<"\t" <<i << "-> ";
				for(auto idx : AL[i]){
					if(get<0>(EL[idx]) == V-1){
						cout<<"->{" << get<2>(EL[idx]) <<"|" << get<1>(EL[idx]) << "}" << "[t] ";  
						continue;
					}else if(get<0>(EL[idx])== 0){
						cout<<"<-{" << get<2>(EL[idx]) <<"|" << get<1>(EL[idx]) << "}" << "[s] "; 
						continue;
					}
					cout << get<0>(EL[idx]) << "{" << get<2>(EL[idx]) << "|" << get<1>(EL[idx]) << "} ";
				}
				cout << endl;
			}
			cout <<endl;
			for(auto idx : AL[V-1]){
				cout << get<0>(EL[idx]) << " ";
			}
			cout << "->t\n" << endl;
		}

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  
  }

  ll edmonds_karp(int s, int t) {
    
    ll maxf = 0;                                 // maxf stands for max_flow
    
    while (BFS(s, t)) {                          // an O(V*E^2) algorithm
    
      ll f = send_one_flow(s, t);                // find and send 1 flow f
      if (f == 0) break;                         // if f == 0, stop
      maxf += f;                                 // if f > 0, add to maxf
    
    }
    
    return maxf;
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
					auto &[v,cap,flow] = EL[idx];
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
int main(){
	while(true){
		
		int r,c,n; //row,col,number of enemies
		cin >> r >> c >> n;
		if(r==0 and c==0 and n ==0){
			break;
		}
		vector<vector<ll>> grid;
		grid.assign(r+1,vector<ll>(c+1));
		for(int i=0;i<n;i++){
			int er,ec;
			cin >> er >> ec;
			grid[er][ec] = 1;
		}
		max_flow mxf(r+c+2);
		for(int i=0;i<=r;i++){
			for(int j=0;j<=c;j++){
				if(grid[i][j] == 1){
					mxf.add_edge(i,r+j,1);
				}
			}
		}
		for(int i=0;i<r;i++){
			mxf.add_edge(0,i+1,1);
		}
		for(int i=0;i<c;i++){
			mxf.add_edge(r+i+1,r+c+1,1);
		}
		cout << mxf.edmonds_karp(0,r+c+1) << " ";
		vector<ll> scomp,tcomp;
		scomp = mxf.reachable_set(0);
		for(int i=1;i<=r;i++){
			if(find(scomp.begin(),scomp.end(),i) == scomp.end()){
				cout <<"r" << i << " ";
			}
		}
		for(int i=1;i<=c;i++){
			if(find(scomp.begin(),scomp.end(),i+r)!=scomp.end()){
				cout <<"c" << i+r <<" ";
			}
		}
		cout << endl;
	}

}
