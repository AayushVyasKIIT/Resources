// You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.

// Input

// The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,…,n.

// After this, the input has m lines describing the edges. Each line has three integers a, b, and c: there is an edge from node a to node b whose length is c.

#include<bits/stdc++.h>
#define ls long long signed
using namespace std;
#define INF 1e10

class Graph{
    public:
        vector<tuple<ls,ls,ls>> EL;
        void addEdges(ls u,ls v,ls w){
            EL.push_back(tie(u,v,w));
        }
        vector<ls> distance;
        void BellmanFord(int n){
            distance.assign(n+1,INF);
            distance[1] = 0;
            vector<ls> pi;
            for(int i=0;i<=n;i++){
                pi[i] = i;
            }
            pi.assign(n+1,-1);
            for(ls i=0;i<n-1;i++){
                for(auto &[u,v,w] : EL){
                    if(distance[u] + w < distance[v]){
                        distance[v] = distance[u] + w;
                        pi[v] = u;
                    }
                }
            }
            ls V = -1;
            for(auto &[u,v,w] : EL){
                if(distance[u] + w < distance[v]){
                    V = v;
                    cout << V << endl;
                }
            }
            if(V!=-1){
                ls st = V;
                cout << n;
                for(ls i=0;i<n;i++){
                    V = pi[V];
                    if(pi[V]==st){
                        break;
                    }   
                    cout << V << " ";
                }
                cout << endl;
                for(auto each : pi){
                    cout << each << " ";
                }
                st = V;
                vector<ls> ans;
                while(true){
                    ans.push_back(pi[st]);
                    if(st == V and ans.size()>1){
                        break;
                    }
                    st = pi[st];
                }
                cout << "YES" <<endl;
                reverse(ans.begin(),ans.end());
                for(auto each : ans){
                    cout << each << " " ;
                }
                return;
            }else{
                cout << "NO" << endl;
                return;
            }
        }

};


int main(){
    ls n,m;
    cin >> n >> m;
    Graph G;
    while(m--){
        ls a,b,c;
        cin >> a >> b >> c ;
        G.addEdges(a,b,c);
    }
    G.BellmanFord(n);


}