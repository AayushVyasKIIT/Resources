#include <bits/stdc++.h>
#include "C:\Resources\C++ package\Array\stdneeds.cpp"

using namespace std;

int main(){

    int size;
    cin >> size;

    int *arr = cinarray1d(size);
    int sum =0;
    int mx = INT_MIN;
    int cummulative[size+1];      
    cummulative[0] = 0;
    for(int i=1;i<size+1;i++){
        cummulative[i] = cummulative[i-1] + arr[i-1];
    }
    cout << "Cummulative array is:" << endl;
    printArray(cummulative,size+1);
    for(int i=1;i<=size;i++){
        sum=0;
        for(int j=0;j<i;j++){
            sum = cummulative[i] - cummulative[j];
            mx = max(sum,mx);
        }

    }
    cout << "Maximum Sum sub array is:" << mx;

    
}