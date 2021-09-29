#include "stdWeightedG.h"

#define vi vector<int>
#define INF INT_MAX
using namespace std;

int BellmanFord(vector<tuple<int,int,int>> EL,int source,int n){

    //initialize the distance array
    vi distance;
    vi pi;
    for(int i=1;i<=n;i++){
        distance[i
    }
    for(int i=0;i<n;i++){
        pi[i] = i;
        
        cout << p[i];
    }

    distance[source] = 0;
    for(int i=0;i<n-1;i++){
        for(auto &[u,v,w] : EL){
            if(distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
                pi[v] = u;
                
            }
        }
    }
    
    for(auto &[u,v,w] : EL){
        if(distance[u] + w > distance[v]){
            return 0;
        }
    }
    return 1;

}

int main(){
    int T; cin >> T;

    vector<tuple<int,int,int>> EL;
    while(T--){
        int n,m; cin >> n >> m;
        EL.clear();
        EL.resize(m);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            EL[i] = tie(u,v,w);
        }
    
        if(BellmanFord(EL,0,n)==0){
            cout << "not possible" << endl;
        }else{
            cout << "possible" << endl;
        }
    }


}