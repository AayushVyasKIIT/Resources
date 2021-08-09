#include <bits/stdc++.h>

using namespace std;

void sumOfSubArrays(int *arr,int n){
    
    for(int i=0;i<n;i++){
        int current_sum = 0;
        for(int j=i;j<n;j++){
            current_sum += arr[j];
            cout <<"Subarray:"<<i << " "<<current_sum << endl;
        }
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    sumOfSubArrays(arr,5);

} 