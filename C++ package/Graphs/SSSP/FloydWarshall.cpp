#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

void FloydWarshall(){
    vector<vector<int>> distance;
    distance.assign(n,vector<int> (n,INF));
    for(int i=0;i<n;i++){
       distance[i][i] = 1;
    }
    for(int r=0;i<n;i++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                distance[i][j] = min(distance[i][j],distance[i][r] + r[k][j]);
            }
        }
}
int main(){


    

 
}