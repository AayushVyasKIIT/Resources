#include <bits/stdc++.h>


using namespace std;

class Graph{
    public:
        map<int,list<int>> adj;
        void addEdge(int u,int v){
            adj[u].push_back(v);
        }
        void solution(int s,int d,int n){
            vector<int> vis;
            vis.assign(n,0);
            vector<int> path;
            path.assign(n,0);
            int path_index = 0;

            printAllPaths(s,d,vis,path,path_index);
        }
        void printAllPaths(int u,int d,vector<int> vis,vector<int> path,int path_index){
            vis[u] = 1;
            path[path_index] = u;
            path_index++;
            if(u==d){
                for(int i=0;i<path_index;i++){
                    cout << path[i] << " ";
                }
                cout << endl;
            }else{
                for(auto v : adj[u]){
                    if(!vis[v]){
                        printAllPaths(v,d,vis,path,path_index);
                    }
                }
            }
            path_index--;
            vis[u] = 0;
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