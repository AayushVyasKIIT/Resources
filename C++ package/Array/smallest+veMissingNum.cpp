#include <bits/stdc++.h>

using namespace std;
int smallestMissingPossitiveNumber(int *arr,int size){
    int smpi;
    int max_size = *max_element(arr,arr+size)+1;
    bool check[max_size];

    for(int i=0;i<max_size;i++){
        check[i]=false;
    }

    for(int i=0;i<size;i++){
        if(arr[i]>=0 && check[arr[i]]!=true){
            check[arr[i]] = true;
        }
    }

    for(int i=0;i<max_size;i++){
        if(check[i]==false){
            smpi = i;
            break;
        }
    }
    return smpi;
}
int main(){

    int arr[] = {0,-9,1,3,-4,5};
    cout << "Smallest possitive integer missing is : " << smallestMissingPossitiveNumber(arr,6);


}