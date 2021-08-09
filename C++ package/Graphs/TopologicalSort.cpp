 #include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int time =0;
    set<int> V;
    map<int,int> d;
    map<int,int> f; 
    map<int,bool> vis;
    map<int,list<int>> adj;
    list<int> topological_sort;

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
    time = time+1;
    d[v] = time;
    for(auto each : adj[v]){
        if(!vis[each]){
            DFS_VISIT(each);
        }
    }
    time = time +1;
    f[v] = time;

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
    G.addEdge(0, 1); 
    G.addEdge(0, 2); 
    G.addEdge(0, 3);
    G.addEdge(1, 2); 
    G.addEdge(2, 4);
    G.addEdge(3, 3); 
    G.addEdge(4, 4);
    
    G.print();
    G.DFS();

    cout << endl;
    for(auto each: G.f){
        cout << "node:" <<each.first<< " start_time:"<< each.second  << endl;
    }
    for(auto each: G.adj){
        G.DFS_VISIT(each.first);
        if(G.f[each.first]!=0 && G.vis[each.first]!=true)
            G.topological_sort.push_front(each.first);
    }
    for( auto each: G.topological_sort){
        cout << each;
    }
}what ever a