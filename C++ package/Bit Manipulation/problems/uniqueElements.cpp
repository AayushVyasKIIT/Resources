#include <bits/stdc++.h>

using namespace std;

int Unique_elements(int arr[],int n){
    int xorsum =0;

    for(int i=0;i<n;i++){
        xorsum =xorsum^arr[i];
        cout << xorsum;
    }
    return xorsum;
}

int main(){
    int arr[5] = {1,2,3,2,1}; //each element is present twice ,Except one!
    cout << Unique_elements(arr,5);
}