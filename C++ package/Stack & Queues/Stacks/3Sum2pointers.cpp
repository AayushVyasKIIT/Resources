#include<bits/stdc++.h>

using namespace std;

bool sum3present(vector<int> arr,int sum){

    sort(arr.begin(),arr.end());
    int start = 0;
    int end = arr.size()-1;
    for(int i=0;i<arr.size();i++){
        int sum2 = sum - arr[i];
        start=i+1;
        
        while(start<end){
            if(arr[start]+arr[end]==sum2){
                
                return true;
            }else if(arr[start]+arr[end]>sum2){
                end--;
            }else{
                start++;
            }
        }
    }
    return false;
}

int main(){

    vector<int> arr  = {12,12,6,6};
    sum3present(arr,24)?cout<<"found":cout<<"not found";
}