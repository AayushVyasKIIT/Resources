#include <bits/stdc++>

using namespace std;

void DNFSort(int arr[],int n){
    int low= 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        if(mid==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(mid==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}


int main(){

}