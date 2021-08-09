#include <bits/stdc++.h>

using namespace std;


int binarySearch(int arr[],int n,int key){

    sort(arr,arr+n);

    int size = n;
    int start = 0;
    int end = n;
    for(int i=0;i<n;i++){
        int mid =  (start+end)/2;
        if(arr[mid] ==key){
            return mid;
        }else if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
    
}
int main(){

    int arr[] = {2,3,1,4,5,7,8,0};
    int key = 2;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << binarySearch(arr,n,key);


    

}