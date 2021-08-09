#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void PermutationsOnDuplicateItems(vector<int> &vec,int idx){
    
    if(idx == vec.size()){
        ans.push_back(vec);
        return;
    }

    for(int i=idx;i<vec.size();i++){
        if(i!=idx && vec[i]==vec[idx])
            continue;
        swap(vec[i],vec[idx]);
        PermutationsOnDuplicateItems(vec,idx+1);
        swap(vec[i],vec[idx]);
    }
    return;

}


int main(){

    vector<int> vec = {1,2,1};
    PermutationsOnDuplicateItems(vec,0);

    for(auto i : ans){
        for(auto j:i){
            cout<< j;
        }
        cout << endl;
    }


}