#include <bits/stdc++.h>

using namespace std;
int* bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);          
            }
        }
    }
    return arr;
}

int main(){
    int arr[] = {3,4,15,1,6};
    int *r = bubblesort(arr,5);
    for(int i=0;i<5;i++){
        cout << "|"<<r[i];
    }
       
}