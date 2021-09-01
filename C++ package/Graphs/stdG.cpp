#include <bits/stdc++.h>

using namespace std;

class G{
    public:
        set<int> V;
        map<int,list<int>> adj;

        //adds an edge
        void add(int v,int w){
            V.insert(v);
            V.insert(w);

            adj[v].push_back(w);
        }
        void remove(int v){
            adj.erase(v);
            V.erase(v);
            for(auto u : V){
                adj[u].remove(v);
            }
        }
        void print(){
            for(auto u: V){
                cout << u << "|->";
                for(auto e: adj[u]){
                    cout << e << "->";
                }
                cout << "/" << endl;
            }
        }
};