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
class BFS: public G{
    public:
        map<int,bool> vis;

        void traverse(int source){
            queue<int> q;
            q.push(source);
            vis[source] = true;
            while(!q.empty()){
                int u = q.front();
                cout << u << " ->";
                for(auto e : adj[u]){
                    if(vis[e]==false){
                        q.push(e);
                        vis[e] = true;
                    }
                }
                q.pop();
            }
            cout << "x" << endl;

        }
};

int main(){

    BFS g1;
    g1.add(0,1);
    g1.add(0,2);
    g1.add(1,3);
    
    g1.traverse(0);

}