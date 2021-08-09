#include <bits/stdc++.h>

using namespace std;

void countSort(int arr[],int n){
    int mx = *max_element(arr,arr+n)+1;
    int count_arr[mx] = {0};

    for(int i=0;i<n;i++){
        count_arr[arr[i]]+=1;
    }
    for(int i=1;i<mx;i++){
        count_arr[i] = count_arr[i-1] + count_arr[i];
    }
   
    for(int i=n-1;i>=0;i--){
        int temp= count_arr[arr[i]]-1;
        swap(arr[temp],arr[i]);
        
    }

}




int main(){
    
    int arr[7] = {0,5,2,3,4,1,2};
    for(int i=0;i<7;i++){
        cout << arr[i];
    }
    cout << endl;
    countSort(arr,7);
    for(int i=0;i<7;i++){
        cout <<" " << arr[i];
    }
    sort(arr,arr+7);

}