#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[],int start,int end,int key){
    if(start<=end){
        int mid = (start+end)/2;
        cout << mid;
        if(key == arr[mid]){
            return mid;
        }
        
        if(key > arr[mid]){

            return binarySearch(arr,mid+1,end,key);
        }else{

            return binarySearch(arr,start,mid-1,key);
        }
    }
    return -1;
}
    
int main(){

    int arr[] = {2,3,1,4,5,7,8,0};
    int key = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    for(int i =0;i<n;i++){
        cout << arr[i];
    }
    int r = binarySearch(arr,0,n,key);
    (r == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << r;



}