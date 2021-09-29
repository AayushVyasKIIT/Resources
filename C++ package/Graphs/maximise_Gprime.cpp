/**
* @brief
Given an undirected complete graph G with n vertices.
The weight of the edge between is equal to .
Let be the shortest distance between vertices and be the sum of all shortest distances between any two vertices.
You can remove at most k edges from graph G in order to obtain a graph G'. 
You have to maximize the ratio of the sum of all shortest distances between any two vertices in new graph G' (after removing the edges) and sum of all shortest distances between any two vertices in old graph G (before reomoving the edges): .
G must remain connected.
*/
#include <bits/stdc++.h>
#define INF -1e21
#define ll long long
using namespace std;

//approach : 
// used the adjaceny distance matrix to calucalte min() and max() G and G' ouput
vector<vector<ll>> dist;

void floyd(int n,int k){
    int edges_removed = k;
    for(ll r=0;r<n;r++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(k==0){
                    return;
                }
                if(i==j){
                    continue;
                }
                if(dist[i][j] < (dist[i][r] + dist[r][j])){
                    k--;
                    cout << edges_removed - k << endl;
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    
}


int main(){

    ll n,k;
    cin >> n >> k;
    dist.assign(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int s;cin>>s;
            dist[i][j] = s;
        }
    }
    floyd(n,k);





}
