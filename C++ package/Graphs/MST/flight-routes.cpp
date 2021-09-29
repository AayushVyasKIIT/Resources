#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class Graph{

    public:
    map<ll,list<ll>> adj;
    map<ll,bool> vis1;
    map<ll,bool> vis2;
    void addEdge(ll u,ll v){
        adj[u].push_back(v);
    }
    void dfs_visit(ll v,map<ll,bool> &vis){
        vis[v] = true;

        for(auto e : adj[v]){
            if(!vis[e]){
                vis[e] = true;
                dfs_visit(e,vis);
            }
        }
    }
    
    void solution(ll n){
        ll start = 1;
        ll end = n;
        
        dfs_visit(start,vis1);
        
        dfs_visit(end,vis2);

        for(ll i=1;i<=n;i++){
            if(vis1[i] == false){
                cout << "NO" << endl;
                cout << start << " "<< i << endl;
                return;
            }
            if(vis2[i] == false){
                cout << "NO" << endl;
                cout << end << " "<< i << endl;
                return;
            }
        }
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    Graph G;
    while(m--){
        ll u,v;
        cin >> u >> v;
        G.addEdge(u,v);
    }
    G.solution(n);

    




}