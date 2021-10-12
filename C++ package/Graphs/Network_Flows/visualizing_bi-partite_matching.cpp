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

};
int main(){
	int n,m;
	cin >> n >> m;
	
}
