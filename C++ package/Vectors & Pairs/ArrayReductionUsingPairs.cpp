#include <bits/stdc++.h>

using namespace std;
bool myComparator(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){
    int arr[] = {10,16,7,14,5,3,12,9};

    vector<pair<int,int>> dict ;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){

        dict.push_back(make_pair(arr[i],i));
    }

    sort(dict.begin(),dict.end(),myComparator);

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        arr[dict[i].second] = i;
    }

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i];
    }

    
}