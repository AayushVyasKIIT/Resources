#include <bits/stdc++.h>
#define ls long long unsigned
using namespace std;

//applying dijkstra
//converting numbers into edges
#define INF 1e6
class Graph{
    public:
        map<ls,list<pair<ls,ls>>> adj;
        Graph(ls len,vector<ls> str,map<ls,list<ls>> NumbPos){
            for(ls i=0;i<len;i++){ ///O(v)
                adj[i].push_back({i+1,1});
                adj[i+1].push_back({i,1});
            }
            
            addEdge(NumbPos);

        }
        void addEdge(map<ls,list<ls>> NumbPos){
            for(auto each : NumbPos){ //O(9)
                if(NumbPos[each.first].size() > 1){
                    NumbPos[each.first].sort();
                    adj[NumbPos[each.first].front()].push_back({NumbPos[each.first].back(),0});
                    adj[NumbPos[each.first].back()].push_back({NumbPos[each.first].front(),0});
                }
            }
                
        }
        void print(){
            for(auto each : adj){
                cout << each.first << ": ";
                for(auto u : adj[each.first]){
                    cout << u.first<< "(" << u.second << ") ";
                }
                cout << endl;
            }
        }
};
void Dijsktra(Graph G,ls n){ //O(mlogn)
    vector<ls> distance(n+1,INF);
    distance[0] = 0;
    vector<ls> pi;
    pi.assign(n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        
        pair<ls,ls> du = pq.top(); pq.pop();
        ls d = du.first;
        ls u = du.second;
        if(d > distance[u]){
            continue;
        }
        for(auto each:G.adj[u]){
            ls v = each.first;
            ls w = each.second;
            if(distance[u] + w >= distance[v]){
                continue;
            }
            distance[v] = distance[u] + w;
            pi[v] = u;
            pq.push({distance[v],v});
        }
    }
    
    ls count=0;
    while(true){
        n = pi[n];
        if(n==0 or n==-1){
            break;
        }
        count ++;
    }
    cout << count << endl;
}

//T(n) = O(mlogn) should pass?
int main(){
    string s;
    cin >> s;
    vector<ls> str;
    str.assign(s.size(),-1);
    for(ls i=0;i<s.size();i++){
        str[i] = s[i] - '0';
    }
    map<ls,list<ls>> NumbPos;
    for(ls i=0;i<str.size();i++){
        NumbPos[str[i]].push_back(i);
    }
    for(auto each : NumbPos){
        cout << each.first << ": "; 
        for(auto e : NumbPos[each.first]){
            cout << e << " ";
        }
        cout <<endl;
    }
    // insert an edge with weights whereever possible
    Graph G(str.size(),str,NumbPos);
    Dijsktra(G,str.size());
    
}