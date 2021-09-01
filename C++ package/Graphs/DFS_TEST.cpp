#include "stdG.cpp"

using namespace std;

class DFS:public G{
    public:

        map<int,bool> vis;
        void DFS_VISIT(int source){

            cout << source <<"->";
            vis[source] = true;
            for(auto e : adj[source]){
                vis[e] = true;
                DFS_VISIT(e);
            }
        }
        void DFS_T(int source){

            for(auto u : V){
                if(vis[u]!=true){
                    DFS_VISIT(u);
                }
            }
            cout << "x" << endl;
        }

};



int main(){

    DFS G1;
    G1.add(0,1);
    G1.add(0,2);
    G1.add(1,3);

    G1.DFS_T(0);

}