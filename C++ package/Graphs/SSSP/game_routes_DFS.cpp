/**
* @brief : A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. 
The game has been designed so that there are no directed cycles in the underlying graph.
In how many ways can you complete the game? 
**/
//T(n) = n!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
#define vi vector<int>
class Graph{
    public:
        map<int,list<int>> adj;
        int ans;
        void addEdge(int u,int v){
            adj[u].push_back(v);
        }
        void solution(int s,int d,int n){
            ans = 0;
            vi vis;vis.assign(n,0);
            vi path;path.assign(n,0);
            int path_index = 0;

            dfs_visit(s,d,vis,path,path_index);
            cout << ans <<endl;
        }
        void dfs_visit(int u,int d,vi vis,vi path,int path_index){
            vis[u] = 1;
            path[path_index] = u;
            path_index++;
            if(u==d){
                ans = (ans%int(mod))+1;
                return;
            }else{
                for(auto v : adj[u]){
                    if(!vis[v]){
                        dfs_visit(v,d,vis,path,path_index);
                    }
                }
            }
            path_index--;
            path.pop_back();
            vis[u] = 0;

            return;
        }
};

int main(){
    int n,m;
    cin >> n >> m;
    Graph G;
    while(m--){
        int u,v;
        cin >> u >> v;
        G.addEdge(u,v);
    }
    G.solution(1,n,n+1);
    
}