/* 
*Let the shortest walk from source to sink be through edges E1 -> E2 -> ... -> Ek, then Weight(E1) > Weight(E2) < Weight(E3) > Weight(E4) .....and so on.  
*/

#include <bits/stdc++.h>

using namespace std;

//at even intervals choose from max heap , the weight with maximum value.
//at odd intervals choose from min heap, the weight with maximum value.
class Graph{
    map<int,list<pair<int,int>>> adj;
    vector<int> distance;
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
    }
    /**
    * @param E number of edges
    */
    void dijkstra(int E){
        set<pair<int,int>> pq;
        distance.assign(n+1,INF);
        for(int i=1;i<=n;i++){
            pq.insert({distance[i],i});
        }
        int side = 0;
        while(!pq.empty()){
            auto [d,u] = *pq.begin();
            pq.erase(pq.begin());

            for(auto &[u,v,w]: adj[u]){
                if(distance[u]+w>distane[v]){
                    continue;
                }

                pq.erase(pq.find({distance[v],v});
                distance[v] = distance[u] + w;
                pq.insert({distance[v],v});
            }
        }

        
    }
}


int main(){


}