#include <bits/stdc++.h>
#include "stdneeds.cpp"
using namespace std;

// r1 : the first repeating element r2: its index value must be the least.
int first_repeating_element(int arr[],int size){

    int countidx[*max_element(arr,arr+size)+1];
    for(int i=0;i<*max_element(arr,arr+size)+1;i++){
        countidx[i] = -1;
    }
    int minidx=INT_MAX;
    for(int i=0;i<size;i++){
        if(countidx[arr[i]]==-1){
            countidx[arr[i]] = i;
        }else if(countidx[arr[i]]>=0){
            if(countidx[arr[i]]<minidx){
                minidx = countidx[arr[i]];
            }
        }
    }
    return minidx;
}

int main(){
    int* arr = array1d(5);
    printArray(arr,5);
    cout <<"\nMin idx:" <<first_repeating_element(arr,5);
}

