#include <bits/stdc++.h>

using namespace std;

int* selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return arr;
}
int main(){
    int arr[] = {2,3,1,5,0,6,4};
    int *a = selectionSort(arr,7);
    for(int i=0;i<7;i++){
        cout << a[i] ;
    }
}