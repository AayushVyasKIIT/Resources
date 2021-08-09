#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
        set<int> V;
        map<int,bool> vis;
        map<int,list<int>> adj;

        void addEdge(int v,int w){
            V.insert(v);
            V.insert(w);
            adj[v].push_back(w);
        }
        void print(){
            for(auto u : adj){
                cout << u.first<< "->";
                for(auto each : u.second){
                    cout << each << "->";
                }
                cout << "/" << endl;
            }
        }
        void BFS(){
            queue<int> q;
            q.push(*V.begin());        

            while(!q.empty()){
                int u  = q.front();
                cout << u ;
                q.pop();
                for(auto v : adj[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            
        }

            
};


int main(){

    Graph G;

    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);

    G.print();

    G.BFS();


}