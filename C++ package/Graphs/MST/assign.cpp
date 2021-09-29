#include <bits/stdc++.h>

using namespace std;

class DSU{
    public:
        vector<int> p,depth;
        map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> vpq;
        int numOfSets;

        DSU(int n){
            p.assign(n,-1);
            depth.assign(n,0);
            numOfSets = n-1;
            for(int i=0;i<n;i++){
                p[i] = i;
            }
        }
        int findSet(int i){
            if(p[i] == i ){
                return i;
            }
            return i = findSet(p[i]);
        }
        void unionSet(int i,int j){
            if(findSet(i)  == findSet(j)){
                return;
            }
            int x = findSet(i);
            int y = findSet(j);

            if(depth[x] > depth[y]){
                swap(x,y);
            }
            p[x] = y;
            if(depth[x] == depth[y]){
                depth[y]++;
            }
            numOfSets--;
        }
};
int main(){
    int n,m;
    cin >> n >> m;
    DSU d(n+1);
    while(m--){
        int i,j;
        cin >> i >> j;
        d.unionSet(i,j);
    }
    vector<pair<int,int>> c;
    c.assign(n+1,{0,0});
    for(int i=1;i<=n;i++){
        int cost;
        cin >> cost;
        c[i] = {cost,i};
    }
    for(int i=1;i<=n;i++){
        if(c[i].first < 0){
            continue;
        }
        d.vpq[d.findSet(i)].push(make_pair(c[i].first,i));
    }
    sort(c.begin(),c.end());
    int ans = 0;

    for(int i=1;i<=n;i++){
        if(d.numOfSets == 1){
            cout << ans << endl;
            return 0;
        }
        if(d.vpq[d.findSet(c[i].second)].empty() || d.vpq[d.findSet(c[i+1].second)].empty()){
            continue;
        }
        if(d.findSet(c[i].second) == d.findSet(c[i+1].second)){
            continue;
        }
        pair<int,int> mn;
        if(d.vpq[d.findSet(c[i].second)].top().first > d.vpq[d.findSet(c[i+1].second)].top().first){
            mn = d.vpq[d.findSet(c[i+1].second)].top();
        }else{
            mn = d.vpq[d.findSet(c[i].second)].top();
        }
        ans+=d.vpq[d.findSet(c[i].second)].top().first + d.vpq[d.findSet(c[i+1].second)].top().first;
        d.unionSet(c[i].second,c[i+1].second);
        d.vpq[d.findSet(c[i].second)].push(mn);

    }
    if(d.numOfSets > 1){
        cout << -1 << endl;
    }
    
    
}