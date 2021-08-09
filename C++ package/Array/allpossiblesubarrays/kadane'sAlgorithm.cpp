#include <bits/stdc++.h>
#include "C:\Resources\C++ package\Array\stdneeds.cpp"
using namespace std;

int main(){

    int size;
    cin >> size;

    int *arr = cinarray1d(size);
    int currSum =0;
    int mx = INT_MIN;

    for(int i=0;i<size;i++){
        if(arr[i]<0){
            currSum = 0;
        }else{
            currSum += arr[i];
        }
        mx = max(currSum,mx);
        
    }
    cout << "Maximum Sum sub array is:" << mx;

}