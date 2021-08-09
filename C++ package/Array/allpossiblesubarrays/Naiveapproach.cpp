#include <bits/stdc++.h>
#include "stdneeds.cpp"

using namespace std;

int main(){

    int size;
    cin >> size;

    int *arr = cinarray1d(size);
    int sum =0;
    int mx = INT_MIN;
    for(int i=0;i<size;i++){
        
        for(int j=i;j<size;j++){
            int sum=0;    
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            mx = max(sum,mx);
        }
        
    }
    cout << "Maximum sum subarray:" << mx << endl;

    
}