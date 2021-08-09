#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:

    set<int> V;
    map<int,bool> vis;
    map<int,list<int>> adj;

    void addEdge(int v,int w);
    void print();
    void DFS_VISIT(int v);
    void DFS();

};

void Graph::addEdge(int v,int w){
    //? adj[v] will give us the mapped linked list
    //? now we push_back w's value in v's list.
    V.insert(v);
    V.insert(w);
    adj[v].push_back(w);
}

void Graph::print(){
    
    map<int,list<int>>::iterator itr;
    for(itr = adj.begin();itr!=adj.end();itr++){
        cout << itr->first << "|->";
        for(auto each : itr->second){
            cout << each << "->";
        }
        cout << "/" << endl;
    }
}

void Graph::DFS_VISIT(int v){
    
    vis[v] = true;
    //? it will print the current node and look for the next vertex in adjacency list
    cout << v;
    
    for(auto each : adj[v]){
        if(!vis[each]){
            DFS_VISIT(each);
        }
    }
}

void Graph::DFS(){
    //? suppose if a node is isolated/disconnected then we need
    //? perform this for each vertex in graph G to make sure we 
    //? explored each vertex.
    for(auto each: adj){
        if(vis[each.first]!=true){
            DFS_VISIT(each.first);
        }
    }
}
int main(){

    Graph G;
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(2,3);
    
    G.print();
    G.DFS();

}