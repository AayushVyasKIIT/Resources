#include <bits/stdc++.h>

using namespace std;

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int p =r;
    int i = l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[p]);
    return i+1;

}



void QuickSort(int arr[],int l,int r){
    if(l<r){
        int pi = partition(arr,l,r);
        QuickSort(arr,l,pi-1);
        QuickSort(arr,pi+1,r);
    }
}


int main(){

    int arr[7] = {4,5,2,3,4,1,2};
    for(int i=0;i<7;i++){
        cout << arr[i];
    }
    cout << endl;
    QuickSort(arr,0,6);
    for(int i=0;i<7;i++){
        cout << arr[i];
    }
}