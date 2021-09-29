// There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.

// Input

// The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,…,n.

// Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.

// Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.

// Output

// Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.

// If there are no solutions, print "IMPOSSIBLE".

// Constraints

//     1≤n≤105


// 1≤m≤2⋅105

// 1≤a,b≤n


// Example

// Input:
// 5 3
// 1 2
// 1 3
// 4 5

// Output:
// 1 2 2 1 2

#include <bits/stdc++.h>

using namespace std;

//can be seen as a bipartite , 2 neighbours have friendships, so keeping them in alternatively in 2 teams

class Graph{

	public:
		
		map<int,list<int>> adj;
		map<int,bool> vis;
		map<int,int> team;

	
		void add(int u,int v){
			//friendships are mutual
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		void dfs_visit(int u,int s){
			vis[u] = true;
			if(s==0){
				team[u] = 1;
			}else{
				team[u] = 2;
			}

			for(auto each : adj[u]){
				if(!vis[each]){
					vis[each] =true;
					dfs_visit(each,1-s);		
				}
			}
			
		}
		void dfs(){

			for(auto each : adj){
				if(!vis[each.first]){
					dfs_visit(each.first,0);
				}
			}
		}
		void solution(int n){
			dfs();
			for(int i=1;i<=n;i++){
				if(team[i] == 0){
					cout << 1 <<endl;
				}else{

					cout << team[i] << " " ;
				
				}
			}
			cout << endl;
		}


};

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