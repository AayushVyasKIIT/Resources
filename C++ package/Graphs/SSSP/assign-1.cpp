/* 
Alice, Bob, and Charlie live in a country where there are N cities. The cities are numbered from 0 to N-1. For every ordered pair of cities (u, v), there is a flight from City u to City v, which costs C[u][v] rupees.

Alice is initially in City A, Bob is in City B, and Charlie is in City C. Alice has to visit Charlie, but is also wondering if she should also visit Bob before that. That is, Alice has two options:

    Option 1: Alice visits Charlie, without worrying about Bob. That is, she goes from City A to City C.
    Option 2: Alice goes from City A to City B, where she visits Bob, and then from there she goes to City C to visit Charlie.


To help her make the decision, please find the minimum total cost if she goes with Option 2. And if she goes with Option 1, how much money will she save? There are many scenarios given, in which the initial cities of the three friends are different. Find this for each such scenario.

Note that she can take indirect connecting flights as well. It doesn't have to be a direct flight from City A to City C (or City B).

Also note that in Option 2, even if she passes through City C while going from City A to City B, she still has to eventually get to City C at the end after visiting City B.
Input

    The first line of the input contains one integer, N.
    The next N lines contain N integers each. The v-th integer in the u-th line is C[u][v].
    The next line of the input contains one integer, M, which is the number of scenarios.
    Each of the next M lines contains 3 integers each, A, B, and C, which represent the initial cities of the three friends.

Output
For each scenario, output two integers - First the minimum cost if Alice chooses Option 2. Then, output the amount she will save if she chooses Option 2. 
 */
#include <bits/stdc++.h>
#define INF 1e6
using namespace std;

vector<vector<int>> floyd_warshall(vector<vector<int>> am ,int n){
    vector<vector<int>> apsp;
    apsp.assign(n,vector<int>(n,INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            apsp[i][j] = am[i][j];
        }
    }
    for(int r=0;r<n;++r){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                apsp[i][j] = min(apsp[i][j],apsp[i][r] + apsp[r][j]);
            }
        }
    }
    return apsp;
}
void print(vector<vector<int>> a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            cout << a[i][j] << " " ;
        }
        cout << endl;
    }
}
int main(){

    int n ; cin >> n;
    //input n*n matrix
    vector<vector<int>> am;
    am.assign(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x; cin >> x;
            am[i][j] = x;
        }
    }
   /// <apply floyd warshall here to calculate all pair shortest paths.
    vector<vector<int>> apsp;
    apsp = floyd_warshall(am,n);
    int m;
    cin >> m;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        cout << apsp[a][b] + apsp[b][c] << " " <<   (apsp[a][b] + apsp[b][c]) - apsp[a][c] << endl;
    }

    
}