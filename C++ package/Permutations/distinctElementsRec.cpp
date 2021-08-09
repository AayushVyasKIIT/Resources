#include <bits/stdc++.h>

using namespace std;

vector<vector <int>> ans;
void permutation_rec(vector<int> &vec, int idx ){
    if(idx == vec.size()){
        ans.push_back(vec);
        return;
    }
    for(int i=idx;i<vec.size();i++){
        swap(vec[i],vec[idx]);
        permutation_rec(vec,idx+1);
        swap(vec[i],vec[idx]);
    }
    return;

}


int main(){

    vector<int> vec = {1,2,3};
    permutation_rec(vec,0);

    for(auto i : ans){
        for(auto j:i){
            cout<< j;
        }
        cout << endl;
    }


}