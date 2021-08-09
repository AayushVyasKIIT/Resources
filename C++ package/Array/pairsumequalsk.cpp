#include <bits/stdc++.h>
#include "stdneeds.cpp"

using namespace std;

bool pairequalsK(int* arr,int size,int k){
    int low = 0;
    int high = size-1;
    while(low<high){
        if(arr[low]+arr[high]<k){
            low++;
        }else if(arr[low]+arr[high] == k){
            return true;
        }else{
            high--;
        }
    }
    return false;
        

}

int main(){
    int k=4;
    int *arr = array1d(5);
    sort(arr,arr+5);
    printArray(arr,5);
    pairequalsK(arr,5, k)?cout<< "yes":cout<<"no";

}