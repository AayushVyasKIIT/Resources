#include<bits/stdc++.h>

using namespace std;

class comp{
    bool operator()(pair<int,int> &a,pair<int,int> &b){        
        return a.second < b.second;
    }
};

int main(){

    priority_queue<pair<int,int>,vector<pair<int,int>>> max_heap;

    max_heap.push(make_pair(0,10));
    max_heap.push(make_pair(1,7));
    max_heap.push(make_pair(2,17));
    max_heap.push(make_pair(3,11));
    max_heap.push(make_pair(4,5));




}