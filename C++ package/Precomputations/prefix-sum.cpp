#include<bits/stdc++.h>

using namespace std;

//Q: output sum of a range[L,R] of indices in an array

// N is given

int main(){

    vector<int> vi;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vi.push_back(x);
    }
    vector<int> prefix_sum;
    prefix_sum = vi;
    for(int i=0;i<n;i++){
        prefix_sum[i] += prefix_sum[i-1];
    }   
    int l,r;
    cin >> l >> r;
    cout << prefix_sum[r] - prefix_sum[l-1] << endl;

}