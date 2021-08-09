#include <bits/stdc++.h>

using namespace std;

void max_till_i(int arr[],int size){
    int current_max = *arr;
    for(int i=1;i<size;i++){
        if(current_max>*(arr+i)){
            *(arr+i) = current_max;
        }else{
            current_max = *(arr+i);
        }

    }
}

int main(){

    int arr[] = {0,-9,1,3,-4,5,0};
    max_till_i(arr,7);
    for(int i=0;i<7;i++){
        cout << arr[i];
    }
}