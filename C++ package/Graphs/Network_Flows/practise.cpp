#include <bits/stdc++.h>

#define INF 1e18
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define edge tuple<int,ll,ll>


using namespace std;

class max_flow{
	private:
		int V; //total number of vertices |V|
		vector<vi> AL;
		vector<edge> EL; // list of tuples carrying information about : v, capacity, flow
		vector<ii> p; //keeps track of the parent
		vi d,last; // d: distance 
			
		// checks if path between s and t exists or not.	
		bool BFS(int s,int  t){
	 		d.assign(V,-1);
			d[s] = 0;
			queue<int> q({s});
			p.assign(V,{-1,-1});
			while(!q.empty()){
				int u = q.front(); q.pop();
				
				if(u==t){
					break; //path exists , badhaiya
				}
				for(auto &idx: AL[u]){ // AL gives us the pointer, which we use to map.
					auto &[v,cap,flow] = EL[idx];
						if((cap-flow) > 0 and (d[v] == -1)){ //possitive flow !(flow more capacity less) and !vis
							d[v]  = d[u] + 1;
							q.push(v);
							p[v] = {u,idx}; //mapping parent and its idx in AL
						}
					}
				}
				return d[t]!=-1; // @returns `true` if d[t]!=-1 means path exist.
		}
			
		ll send_one_flow(int s,int t,ll f = INF){ //recursive function to send one flow from s->t 
			if(s==t){ //stopping condition : meaning we have reached till the end of the flow.
				return f;
			}
			
			auto &[u,idx] = p[t];
			auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
			
			ll pushed = send_one_flow(s,u,min(f,cap-flow)); //min(f,cap-flow) finds the bottle-neck capacity along
			//the recursive path t->p[t]->[p[t]]->..........->s 
			
			flow += pushed; //updating flows of each node we encounter
			
			//rflow == back edge
			auto &rflow = get<2>(EL[idx^1]); // ex(010)->(011) 
			//Q: Use of XOR^1 ? A: It gives the idx of other vertex in the pair of vertices, whose flow we are talking about.
			// - when we take a XOR w 1, it flips the last bit. So, if we have idx=2(010) then its partner will be (011):01(0->1)
			// and vice-versa.
			rflow -= pushed ;
				
			return pushed; //bottle-neck
		}

	public:
		//__init__
		max_flow(int initialV):V(initialV){
			EL.clear(); 
			AL.assign(V,vi()); //basically 0 everywhere
		}
		void add_edge(int u,int v,ll w,bool directed = true){
			if(u==v){//self loop, violation of constraints.
				return; 
			}
			EL.emplace_back(v,w,0); //not wasting time creating a temporary tuple and then pushing it back to the vector tht's why 
			//using emplace_back instead of push_back
			AL[u].push_back(EL.size()-1); //AL[u] knows where the information about edges is kept in the Edgelist(EL)
			
			//for undirected , if(directed == false, we add a 0 capacity edge, else usual W capacity edge )
			EL.emplace_back(u,directed?0:w,0); //adding a back edge
			AL[v].push_back(EL.size()-1); //we remember this index.
			
		}
		/**
		* @param s source
		* @param t sink
		**/
		
		ll edmonds_karp(int s,int t){
			//init
			ll maxf = 0; //maximum flow that can be sent from source to sink, given that source have a tendency to supply infinitly
			while(BFS(s,t)){ //until there exist a path from source to sink 
				ll f = send_one_flow(s,t); //find and send 1 flow
				if(f==0) break; // not necessary to check it here, as we already did the cap - flow check
				maxf+=f; // add the bottle-neck to determine the maxflow.
				//formely this is known as augmenting the flow.	
			}
			return maxf;
		}	
		
		
};

int main(){
	std::ios::sync_with_stdio(false);
	int c = 0; //network number
	while(true){
		int n;
		cin >> n;
		if(not n){
			break;
		}
		int s,t,m; //source sink no_of_edges
		cin >> s >> t >> m;
		
		max_flow maxf(n+1);
		for(int i=0;i<m;i++){
			int u,v,cap;
			cin >> u >> v >> cap;
			maxf.add_edge(u,v,cap,false);
		}
		c++;
		printf("\nNetwork #%d: \t  Bandwidth: %d\n",c,maxf.edmonds_karp(s,t));
				
	}
	return 0;
}
