#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> vec({10,16,7,14,5,3,12,9});
    vector <int> sorted_vec = vec;
    sort(sorted_vec.begin(),sorted_vec.end());
    vector <int> ans(8,0);
    for(int i=0;i<vec.size();i++){
        int min = sorted_vec[0];
        sorted_vec.erase(sorted_vec.begin());
        vector<int>::iterator it = find(vec.begin(),vec.end(),min);
        int index = it-vec.begin();
        ans[index] +=i;
    }
    for(auto element : ans){
        cout << element;
    }

}