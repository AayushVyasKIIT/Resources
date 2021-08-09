#include <bits/stdc++.h>

using namespace std;

void WaveSort(int arr[],int n){

    for(int i=1;i<=n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i-1],arr[i]);
        }else if(arr[i]>arr[i+1] && i<=n-2){
            swap(arr[i],arr[i+1]);
        }
    }

}

int main(){

    int arr[6] = {3,2,0,1,4,6};
    WaveSort(arr,6);
    for(int i=0;i<6;i++){
        cout << arr[i];
    }
}