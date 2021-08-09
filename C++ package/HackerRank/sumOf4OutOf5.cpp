#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[5]= {1,2,3,4,5};

    int minSum = INT_MAX,maxSum= INT_MIN;
    int currSum = 0;
    for(int i=0;i<5;i++){
        currSum =0;
        for(int j=0;j<5;j++){
            if(i!=j){
                cout << i << j;
                currSum += arr[j];
            }
        }
        minSum = min(currSum,minSum);
        maxSum = max(currSum,maxSum);
    }
    cout << minSum << " ";
    cout << maxSum;

}