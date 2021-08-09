#include <bits/stdc++.h>

using namespace std;

int main(){

    multiset<int,greater<int>> ms;
    vector<int> array = {-10,9,2,1,2,3,4,0,1};

    vector<int> MaxSlidingWindowAns;
    int k = 2;
    for(int i=0;i<k;i++){
        ms.insert(array[i]);
    }
    MaxSlidingWindowAns.push_back(*ms.begin());
    for(int i=k;i<array.size();i++){
        ms.erase(ms.lower_bound(array[i-k]));
        ms.insert(array[i]);
        MaxSlidingWindowAns.push_back(*ms.begin());
    }
    for(auto i:MaxSlidingWindowAns){
        cout << i << endl;
    }

}