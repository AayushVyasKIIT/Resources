#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> vec = {1,2,3};

    vector<vector<int>> ans;
    sort(vec.begin(),vec.end());
    do{
        ans.push_back(vec);
    }while(next_permutation(vec.begin(),vec.end()));

    
    for(auto i : ans){
        for(auto j:i){
            cout<< j;
        }
        cout << endl;
    }

}