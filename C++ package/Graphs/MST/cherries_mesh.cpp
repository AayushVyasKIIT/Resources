/** 
* @brief :  Your friend is recently done with cooking class and now he wants to boast in front of his school friends by making a nice dessert.
He has come up with an amazing dessert called Cherries Mesh. To make the dish, he has already collected cherries numbered 1 to N.
He has also decided to connect each distinct and unordered pair of cherries with a sweet strand, made of sugar.
Sweet strands are either red or black, depending on the sugar content in them. 
Each black strand contains one units of sugar, and each red strand contains two units of sugar.
But it turns out that the dessert is now too sweet, 
and these days his school friends are dieting and they usually like dishes with less sugar. 
He is really confused now and comes to your rescue. Can you help him find out which all sweet strands he should remove such that each pair of cherries is connected directly or indirectly via a sugar strand,
and the dish has the minimum possible sugar content?

*!Input:

The first line of input gives the number of test cases, T.

Each test case begins with a line containing two integers N and M, the number of cherries and the number of black sweet strands, respectively.

Then M lines follow, each describing a pair of cherries connected to a black strand. The i-th line contains cherries numbered Ci and Di, it indicates that Ci and Di cherry are connected with a black strand of sugar.

Note: Any other pair of cherries not present in the input means that they are connected by a red strand.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is minimum possible sugar content.  
*/

#include <bits/stdc++.h>

using namespace std;
class DSU{
    public:
        vector<int> p,depth,setSize;
        int numOfSets;

        DSU(int n){
            p.assign(n,-1);
            for(int i=0;i<n;i++){
                p[i] = i;
            }
            depth.assign(n,0);
            setSize.assign(n,0);
            numOfSets = n-1;
        }   
        int findSet(int i){
            if(p[i] == i){
                return i;
            }
            return i = findSet(p[i]);
        }
        void unionSet(int u,int v){
            if(findSet(u) == findSet(v)){
                return;
            }
            int x = findSet(u);
            int y = findSet(v);

            if(depth[x] > depth[y]){
                swap(x,y);
            }
            p[x] = y;
            if(depth[x] == depth[y]){
                depth[y]++;
            }
            setSize[y]+=setSize[x];
            numOfSets--;
        }
};
int main(){
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        int n,m;
        cin >> n >> m;
        DSU d(n+1);
        int numberOfBlackEdges =0;
        while(m--){
            int u,v;
            cin >> u >> v;
            if(d.findSet(u) == d.findSet(v)){continue;}
            d.unionSet(u,v);
            numberOfBlackEdges++;
        }
        printf("Case #%d: %d\n",t,numberOfBlackEdges + 2*(d.numOfSets - 1));
        
    }
}