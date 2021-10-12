#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define ii pair<int,int>
#define edge tuple<int,ll,ll>

#define INF 1e9

class max_flow{
        private:
		int V;
		vi d,last;
		vector<vi> AL;
		vector<edge> EL;
		vector<ii> p;
		
		bool BFS(int s,int t){
			d.assign(V,-1);
			p.assign(V,{-1,-1});
			d[s] = 0;
			queue<int> q({s});
			while(!q.empty()){
				int u = q.front(); q.pop();
				
				if(u==t){
					break;
				}

				for(auto &idx : AL[u]){
					auto cap = get<1>(EL[idx]);
					auto v = get<0>(EL[idx]);
					auto flow = get<2>(EL[idx]);

					if((cap-flow)>0 and d[v]==-1){
						q.push(v);
						d[v] = d[u] +1;
						p[v] = {u,idx};
					}
				}
			}
			return d[t]!=-1;
		}
		//returns the bottle_neck flow which augments to make the max_flow
		ll send_one_flow(int s,int t,ll f = INF){
			if(s==t){
				return f;
			}

			auto &idx = get<1>(p[t]);
			auto &u = get<0>(p[t]);


			auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
			ll pushed = send_one_flow(s,u,min(f,cap-flow));

			//augmented flow
			flow +=pushed;

			//reverse flow
			auto &rflow = get<2>(EL[idx^1]);
			rflow -= pushed;

			return pushed;
		}

	public:
		max_flow(int initialV):V(initialV){
			EL.clear();
			AL.assign(V,vi());
		}
		void add_edge(int u,int v,int w,bool directed = true){
			if(u==v){
				return; //no self loops allowed
			}
			EL.emplace_back(v,w,0);
			AL[u].push_back(EL.size()-1);

			EL.emplace_back(u,directed?0:w,0);
			AL[v].push_back(EL.size()-1);

		}
		ll edmonds_karp(int s,int t){
			ll maxflow = 0;

			while(BFS(s,t)){

				ll flow = send_one_flow(s,t);
				if(flow== 0){
					break;
				}
				maxflow += flow;
			}
			return maxflow;
		}

};
int main(){
	int n,m;
	cin >> n >> m;
	max_flow mxf(n+1);
	while(m--){
		int u,v;
		cin >> u >> v;
		ll w;
		cin >> w;
		mxf.add_edge(u,v,w);
	}
	int T;
	cin >> T;
	while(T--){
		max_flow test(mxf);
		int s,t;
		cin >> s >> t;	
		cout << test.edmonds_karp(s,t) << endl;
	}

}
