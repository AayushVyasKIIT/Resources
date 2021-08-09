#include <bits/stdc++.h>
#include "C:\Resources\C++ package\Array\stdneeds.cpp"
using namespace std;

int kadane(int* arr,int size){
    
    int currSum =0;
    int mx = INT_MIN;

    for(int i=0;i<size;i++){
        if(arr[i]<0){
            currSum=0;
        }else{
            currSum += arr[i];
        }
        mx = max(currSum,mx);

    }
    return mx;
}


int main(){
    int size;
    cin >> size ;
    int *arr = cinarray1d(size);

    //case1 : non-wrap around sum using kadane's algorithm.
    int nonwrap = kadane(arr,size);

    //case2 : wrap around sum
    int totalSum =0;
    int wrap;

    for(int i=0;i<size;i++){
        totalSum += arr[i];
        arr[i] *= -1;
    }

    wrap = totalSum + kadane(arr,size);

    //finalcase
    cout << "Maximum sum of circular Sub array is: " << max(wrap,nonwrap);






}